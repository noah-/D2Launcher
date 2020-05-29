#pragma once
#include <Windows.h>
#include <string>
#include <map>
#include "D2Constants.h"
#include "D2Structs.h"
#include "ArrayEx.h"
#include "CollisionMap.h"
#include "Vectors.h"
#include "TeleportPath.h"

int waypoints[] = { 119,157,156,323,288,402,324,237,238,398,496,511,494 };
int CSID = 0;
int CS[] = { 392, 394, 396, 255 };

class AutoTele {
private:
	unsigned int NextKey, OtherKey, WPKey, PrevKey;
	unsigned int Colors[6];

	int Try;
	POINT End;
	DWORD _timer, _timer2, _InteractTimer;
	bool SetInteract, SetTele, CastTele, TeleActive, DoInteract;
	DWORD InteractType, InteractId;
	Room2* InteractRoom;
	DWORD LastArea;
	POINT Vectors[5];
	CArrayEx <POINT, POINT> TPath;

	DWORD GetPlayerArea() {
		auto player = D2CLIENT_GetPlayerUnit();
		if (player && player->pPath && player->pPath->pRoom1 && player->pPath->pRoom1->pRoom2 && player->pPath->pRoom1->pRoom2->pLevel)
			return player->pPath->pRoom1->pRoom2->pLevel->dwLevelNo;
		return 0;
	}
	int MakePath(int x, int y, DWORD Areas[], DWORD count, bool MoveThrough) {
		CCollisionMap g_collisionMap;
		DWORD dwCount;
		POINT aPath[255];
		if (!g_collisionMap.CreateMap(Areas, count)) return false;
		POINT ptStart = { D2CLIENT_GetPlayerUnit()->pPath->xPos, D2CLIENT_GetPlayerUnit()->pPath->yPos };
		POINT ptEnd = { x, y };
		if (!g_collisionMap.IsValidAbsLocation(ptStart.x, ptStart.y)) return false;
		if (!g_collisionMap.IsValidAbsLocation(ptEnd.x, ptEnd.y)) return false;
		g_collisionMap.AbsToRelative(ptStart);
		g_collisionMap.AbsToRelative(ptEnd);
		WordMatrix matrix;
		if (!g_collisionMap.CopyMapData(matrix)) return false;
		CTeleportPath tf(matrix.GetData(), matrix.GetCX(), matrix.GetCY());
		dwCount = tf.FindTeleportPath(ptStart, ptEnd, aPath, 255);
		if (dwCount == 0) return false;
		for (DWORD i = 0; i < dwCount; i++) g_collisionMap.RelativeToAbs(aPath[i]);
		if (MoveThrough) {
			if (aPath[dwCount - 1].x > aPath[dwCount - 2].x) aPath[dwCount].x = aPath[dwCount - 1].x + 2;
			else aPath[dwCount].x = aPath[dwCount - 1].x - 2;
			if (aPath[dwCount - 1].y > aPath[dwCount - 2].y) aPath[dwCount].y = aPath[dwCount - 1].y + 2;
			else aPath[dwCount].y = aPath[dwCount - 1].y - 2;
			dwCount++;
			if (GetDistanceSquared(aPath[dwCount - 1].x, aPath[dwCount - 1].y, aPath[dwCount - 3].x, aPath[dwCount - 3].y) <= 30) {
				aPath[dwCount - 2] = aPath[dwCount - 1];
				aPath[dwCount - 1].x = 0;
				aPath[dwCount - 1].y = 0;
				dwCount--;
			}
		}
		TPath.RemoveAll();
		for (DWORD i = 1; i < dwCount; i++) TPath.Add(aPath[i], 1);
		return dwCount;
	}
	POINT FindPresetLocation(DWORD dwType, DWORD dwTxtFileNo, DWORD Area) {
		UnitAny* player = D2CLIENT_GetPlayerUnit();
		Level* pLevel = GetLevel(player->pAct, Area);
		POINT loc;
		loc.x = 0;
		loc.y = 0;
		DoInteract = 0;
		if (!pLevel) return loc;
		bool bAddedRoom = false;
		bool stoploop = false;
		for (Room2* pRoom = pLevel->pRoom2First; pRoom; pRoom = pRoom->pRoom2Next)
		{
			bAddedRoom = false;
			if (!pRoom->pPreset && !pRoom->pRoomTiles && !pRoom->pRoom1)
			{
				D2COMMON_AddRoomData(player->pAct, pLevel->dwLevelNo, pRoom->dwPosX, pRoom->dwPosY, player->pPath->pRoom1);
				bAddedRoom = true;
			}
			for (PresetUnit* pUnit = pRoom->pPreset; pUnit; pUnit = pUnit->pPresetNext)
			{
				//PrintText(4, "X: %d, Y: %d, TxtFileNo: %d, Type: %d", pUnit->dwPosX, pUnit->dwPosY, pUnit->dwTxtFileNo, pUnit->dwType);
				if (((dwType == NULL) || (dwType == pUnit->dwType)) && (dwTxtFileNo == pUnit->dwTxtFileNo))
				{
					if (dwType == UNIT_TILE || (dwType == UNIT_OBJECT && dwTxtFileNo == 298))
					{
						InteractRoom = pRoom;
						InteractType = dwType;
						//DoInteract = 1;
					}
					if (dwType == UNIT_OBJECT)
					{
						for (int i = 0; i <= 13; i++)
						{
							if (waypoints[i] == dwTxtFileNo)
							{
								InteractRoom = pRoom;
								InteractType = dwType;
								//DoInteract = 1;
								stoploop = 1;
								break;
							}
						}
					}
					loc.x = (pUnit->dwPosX) + (pRoom->dwPosX * 5);
					loc.y = (pUnit->dwPosY) + (pRoom->dwPosY * 5);
					stoploop = 1;
					break;
				}
			}
			if (bAddedRoom)
			{
				D2COMMON_RemoveRoomData(D2CLIENT_GetPlayerUnit()->pAct, pLevel->dwLevelNo, pRoom->dwPosX, pRoom->dwPosY, D2CLIENT_GetPlayerUnit()->pPath->pRoom1);
				bAddedRoom = false;
			}
			if (stoploop)
			{
				stoploop = 0;
				break;
			}
		}
		return loc;
	}
	bool GetSkill(WORD wSkillId) {
		if (!D2CLIENT_GetPlayerUnit()) return 0;
		for (Skill* pSkill = D2CLIENT_GetPlayerUnit()->pInfo->pFirstSkill; pSkill; pSkill = pSkill->pNextSkill)
			if (pSkill->pSkillInfo->wSkillId == wSkillId) return 1;
		return 0;
	}
	bool SetSkill(WORD wSkillId, bool Left) {
		if (!D2CLIENT_GetPlayerUnit()) return 0;
		BYTE PutSkill[9] = { 0x3c,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF };
		if (GetSkill(wSkillId))
		{
			*(WORD*)&PutSkill[1] = wSkillId;
			if (Left) *(BYTE*)&PutSkill[4] = 0x80;
			D2NET_SendPacket(9, 0, PutSkill);
		}
		else return 0;
		return 1;
	}
	bool CastOnMap(WORD x, WORD y, bool Left) {
		ClickMap(3, x, y);
		return 1;
		LPBYTE aPacket = new BYTE[5];
		*(BYTE*)&aPacket[0] = Left ? (BYTE)0x08 : (BYTE)0x0F;
		*(WORD*)&aPacket[1] = x;
		*(WORD*)&aPacket[3] = y;
		D2NET_SendPacket(5, 0, aPacket);
		delete[] aPacket;
		return 1;
	}
	bool Interact(DWORD UnitId, DWORD UnitType) {
		LPBYTE aPacket = new BYTE[9];
		*(BYTE*)&aPacket[0] = (BYTE)0x13;
		*(DWORD*)&aPacket[1] = UnitType;
		*(DWORD*)&aPacket[5] = UnitId;
		D2NET_SendPacket(9, 1, aPacket);
		delete[] aPacket;
		return 1;
	}
	DWORD GetUnitByXY(DWORD X, DWORD Y, Room2* pRoom) {
		UnitAny* pUnit;
		if (!pRoom) return 0;
		if (!pRoom->pRoom1) return 0;
		if (!pRoom->pRoom1->pUnitFirst) return 0;
		pUnit = pRoom->pRoom1->pUnitFirst;
		if (!pUnit) return 0;
		if (!pUnit->pObjectPath) return 0;
		while (pUnit) {
			if (pUnit->dwType != UNIT_PLAYER)
				if (X == pUnit->pObjectPath->dwPosX)
					if (Y == pUnit->pObjectPath->dwPosY)
						return pUnit->dwUnitId;
			pUnit = pUnit->pListNext;
		}
		return 0;
	}

public:
	void ManageTele(Vector T) {
		DWORD Areas[2];
		DWORD AreaCount = 1;
		Areas[0] = GetPlayerArea();
		if (Areas[0] == MAP_A2_CANYON_OF_THE_MAGI) {
			if (T.dwType == 0 && T.Id == 0) {
				T.dwType = 6;
				T.Id = GetLevel(D2CLIENT_GetPlayerUnit()->pAct, Areas[0])->pMisc->dwStaffTombLevel;
			}
		}
		else if (Areas[0] == MAP_A1_COLD_PLAINS) {
			//if (Toggles["CP to cave"].state)
			//	if (T.Id == MAP_A1_BURIAL_GROUNDS)
			//		T.Id = MAP_A1_CAVE_LEVEL_1;
		}
		else if (Areas[0] == MAP_A4_THE_CHAOS_SANCTUARY && T.Id2 >= 1337) {
			CSID == 3 ? CSID = 0 : CSID++;
			vVector[Areas[0] * 4].Id = CS[CSID];
		}
		if (!T.Id) {
			// PrintText(1, "ÿc4AutoTele:ÿc1 Invalid destination");
			return;
		}
		if (T.Area) {
			Areas[1] = T.Area;
			AreaCount = 2;
		}
		DoInteract = 0;
		if (T.dwType == 6 || T.dwType == 8) {
			CCollisionMap g_collisionMap;
			if (!g_collisionMap.CreateMap(Areas, AreaCount)) return;
			LPLevelExit ExitArray[0x40];
			int ExitCount = g_collisionMap.GetLevelExits(ExitArray);
			if (!ExitCount) return;
			for (int i = 0; i < ExitCount; i++) {
				if (ExitArray[i]->dwTargetLevel == T.Id) {
					LevelTxt* lvltext = D2COMMON_GetLevelText(T.Id);
					DoInteract = 0;
					if (ExitArray[i]->dwType == 2) {
						DoInteract = 1;
						InteractType = UNIT_TILE;
						InteractRoom = ExitArray[i]->pRoom;
					}
					else DoInteract = 0;
					int nodes = MakePath(ExitArray[i]->ptPos.x, ExitArray[i]->ptPos.y, Areas, AreaCount, ExitArray[i]->dwType == 2 ? 1 : 0);
					PrintText(1, "ÿc4AutoTele:ÿc1 Going to %s, %d nodes.", lvltext->szName, nodes);
					break;
				}
			}
			return;
		}
		if (T.dwType == XY) {
			DoInteract = 0;
			if (!T.Id || !T.Id2) {
				PrintText(1, "ÿc4AutoTele:ÿc1 No X/Y value found");
				return;
			}
			int nodes = MakePath(T.Id, T.Id2, Areas, AreaCount, 0);
			PrintText(1, "ÿc4AutoTele:ÿc1 Going to X: %d, Y: %d, %d nodes", T.Id, T.Id2, nodes);
			return;
		}
		POINT PresetUnit = AreaCount == 2 ? FindPresetLocation(T.dwType, T.Id, Areas[1]) : FindPresetLocation(T.dwType, T.Id, Areas[0]);
		if (PresetUnit.x != 0 && PresetUnit.y != 0) {
			if (T.dwType == UNIT_TILE || (T.dwType == UNIT_OBJECT && T.Id == 298))
				DoInteract = 1;
			if (T.dwType == UNIT_OBJECT)
				for (int i = 0; i <= 13; i++)
					if (waypoints[i] == T.Id)
						DoInteract = 1;
			int nodes;
			if (nodes = MakePath(PresetUnit.x, PresetUnit.y, Areas, AreaCount, 0)) {
				if (T.dwType == UNIT_OBJECT) {
					ObjectTxt* ObjTxt = D2COMMON_GetObjectTxt(T.Id);
					PrintText(1, "ÿc4AutoTele:ÿc1 Going to %s, %d nodes", ObjTxt->szName, nodes);
				}
				InteractType = T.dwType;
			}
			else return;
		}
		else {
			PrintText(1, "ÿc4AutoTele:ÿc1 Can't find object");
			return;
		}
	}
	bool CanCast() {
		auto player = D2CLIENT_GetPlayerUnit();
		if (player->dwMode == 1 || player->dwMode == 2 || player->dwMode == 3) return true;
		return false;
		int modes[10] = { 7, 8, 10, 11, 12, 13, 14, 15, 16, 18 };
		for (int i = 0; i < 10; i++) {
			if (player->dwMode == modes[i]) return false;
		}
		return true;
	}
	void DoWork() {
		DWORD playerArea = GetPlayerArea();
		if (playerArea && LastArea != playerArea && D2CLIENT_GetPlayerUnit()) {
			LastArea = playerArea;
			if (LastArea != MAP_A4_THE_CHAOS_SANCTUARY)
				CSID = 0;
			GetVectors();
			//LoadHandle = CreateThread(0, 0, LoadNewArea, this, 0, 0);
			//return;
		}

		if (LastArea == MAP_A4_THE_CHAOS_SANCTUARY)
			if (vVector[LastArea * 4].Id2 != (1337 + CSID)) {
				vVector[LastArea * 4].Id2 = 1337 + CSID;
				GetVectors();
			}
		if (TPath.GetSize()) {
			End = TPath.GetLast();
			if (SetTele) {
				if (!SetSkill(0x36, 0)) {	//0x36 is teleport
					TPath.RemoveAll();
					PrintText(1, "ÿc4AutoTele:ÿc1 Failed to set teleport!");
				}
				_timer = GetTickCount();
				SetTele = 0;
			}
			if (D2CLIENT_GetPlayerUnit()->pInfo->pRightSkill->pSkillInfo->wSkillId == 0x36) TeleActive = 1;
			else {
				if (TeleActive) {
					TeleActive = 0;
					TPath.RemoveAll();
					PrintText(1, "ÿc4AutoTele:ÿc1 Aborting teleport, deselected teleport");
					return;
				}
				if ((GetTickCount() - _timer) > 1000) {
					TPath.RemoveAll();
					PrintText(1, "ÿc4AutoTele:ÿc1 Failed to set teleport skill. Ping: %d", *p_D2CLIENT_Ping);
					return;
				}
				return;
			}
			if (CastTele) {
				if (!CanCast()) return;
				CastTele = 0;
				_timer2 = GetTickCount();
				if (!CastOnMap(static_cast<WORD>(TPath.ElementAt(0).x), static_cast<WORD>(TPath.ElementAt(0).y), false)) {
					TPath.RemoveAll();
					return;
				}
			}

			if ((GetTickCount() - _timer2) > 500) {
				if (Try >= 5) {
					PrintText(1, "ÿc4AutoTele:ÿc1 Failed to teleport after 5 tries");
					TPath.RemoveAll();
					Try = 0;
					DoInteract = 0;
					return;
				}
				else {
					Try++;
					CastTele = 1;
					return;
				}
			}

			if (GetDistanceSquared(D2CLIENT_GetUnitX(D2CLIENT_GetPlayerUnit()), D2CLIENT_GetUnitY(D2CLIENT_GetPlayerUnit()), TPath.ElementAt(0).x, TPath.ElementAt(0).y) <= 5) {
				TPath.RemoveAt(0, 1);
				CastTele = 1;
			}

			if (DoInteract) {
				if (GetDistanceSquared(D2CLIENT_GetUnitX(D2CLIENT_GetPlayerUnit()), D2CLIENT_GetUnitY(D2CLIENT_GetPlayerUnit()), End.x, End.y) <= 5) {
					_InteractTimer = GetTickCount();
					InteractId = GetUnitByXY(End.x, End.y, InteractRoom);
					SetInteract = 1;
					TPath.RemoveAll();
					return;
				}
			}
		}
		else {
			End.x = 0;
			End.y = 0;
			SetTele = 1;
			CastTele = 1;
			TeleActive = 0;
			Try = 0;
		}
		if (DoInteract && SetInteract && _InteractTimer && (GetTickCount() - _InteractTimer > 150)) {
			Interact(InteractId, InteractType);
			SetInteract = 0;
			_InteractTimer = 0;
		}
	}
	void GetVectors() {
		DWORD MyArea = GetPlayerArea();
		DWORD Areas[2] = { MyArea, 0 };
		DWORD AreaCount = 1;
		BOOL buildCollisionMap = false;
		for (int i = 0; i < 4; i++) {
			Vector V = vVector[MyArea * 4 + i];
			if (V.dwType == EXIT || (MyArea == MAP_A2_CANYON_OF_THE_MAGI && V.dwType == 0 && V.Id == 0)) {
				if (V.Area) {
					Areas[1] = V.Area;
					AreaCount = 2;
				}
				buildCollisionMap = true;
			}
		}
		CCollisionMap g_collisionMap;
		if (buildCollisionMap) buildCollisionMap = g_collisionMap.CreateMap(Areas, AreaCount);
		Vectors[4].x = 0;
		Vectors[4].y = 0;
		for (int i = 0; i < 4; i++) {
			Vectors[i].x = 0;
			Vectors[i].y = 0;
			Vector V = vVector[MyArea * 4 + i];
			if (MyArea == MAP_A2_CANYON_OF_THE_MAGI) {
				if (V.dwType == 0 && V.Id == 0) {
					V.dwType = EXIT;
					V.Id = GetLevel(D2CLIENT_GetPlayerUnit()->pAct, MyArea)->pMisc->dwStaffTombLevel;
				}
			}
			if (V.dwType == UNIT_PLAYER) continue;
			if (V.dwType == XY) {
				Vectors[i].x = V.Id;
				Vectors[i].y = V.Id2;
			}
			if (V.dwType == UNIT_TILE || V.dwType == UNIT_OBJECT || V.dwType == UNIT_MONSTER) {
				if (V.Area) Vectors[i] = FindPresetLocation(V.dwType, V.Id, V.Area);
				else Vectors[i] = FindPresetLocation(V.dwType, V.Id, MyArea);
			}

			if (V.dwType == EXIT || V.dwType == EXIT_MULTI) {
				if (!buildCollisionMap) continue;
				LPLevelExit ExitArray[0x40];
				int ExitCount = g_collisionMap.GetLevelExits(ExitArray);
				if (!ExitCount) continue;
				bool bIsMulti = V.dwType == EXIT_MULTI;
				for (int j = 0; j < ExitCount; j++) {
					if (ExitArray[j]->dwTargetLevel == V.Id) Vectors[i] = ExitArray[j]->ptPos;
					else if (bIsMulti && ExitArray[j]->dwTargetLevel == V.Id2) Vectors[4] = ExitArray[j]->ptPos;
					delete ExitArray[j];
				}
			}
		}
	}
};

enum TeleType {
	Next = 0,
	Other,
	WP,
	Prev
};
