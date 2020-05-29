#pragma once
#include <Windows.h>
#include <string>
#include <map>
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Offsets.h"
#include "Drawing.h"

DWORD __declspec(naked) __fastcall D2CLIENT_InitAutomapLayer_STUB(DWORD nLayerNo)
{
	__asm
	{
		push edi;
		mov edi, ecx;
		call D2CLIENT_InitAutomapLayer_I;
		pop edi;
		ret;
	}
}

class Maphack {
public:
	/*
	void OnLoop();
	void OnDraw();
	void OnAutomapDraw();
	void OnGameJoin();
	void OnGamePacketRecv(BYTE* packet, bool* block);

	void ResetRevealed();
	void ResetPatches();

	void OnKey(bool up, BYTE key, LPARAM lParam, bool* block);*/
	static AutomapLayer* InitLayer(int level) {
		AutomapLayer2* layer = D2COMMON_GetLayer(level);
		if (!layer) return NULL;
		return (AutomapLayer*)D2CLIENT_InitAutomapLayer_STUB(layer->nLayerNo);
	}
	void RevealRoom(Room2* room)
	{
		for (PresetUnit* preset = room->pPreset; preset; preset = preset->pPresetNext)
		{
			int cellNo = -1;
			if (preset->dwType == UNIT_MONSTER)
			{
				// Izual Check
				if (preset->dwTxtFileNo == 256)
					cellNo = 300;
				// Hephasto Check
				if (preset->dwTxtFileNo == 745)
					cellNo = 745;
				// Special Object Check
			}
			else if (preset->dwType == UNIT_OBJECT) {
				// Uber Chest in Lower Kurast Check
				if (preset->dwTxtFileNo == 580 && room->pLevel->dwLevelNo == MAP_A3_LOWER_KURAST)
					cellNo = 318;

				// Countess Chest Check
				if (preset->dwTxtFileNo == 371)
					cellNo = 301;
				// Act 2 Orifice Check
				else if (preset->dwTxtFileNo == 152)
					cellNo = 300;
				// Frozen Anya Check
				else if (preset->dwTxtFileNo == 460)
					cellNo = 1468;
				// Canyon / Arcane Waypoint Check
				if ((preset->dwTxtFileNo == 402) && (room->pLevel->dwLevelNo == 46))
					cellNo = 0;
				// Hell Forge Check
				if (preset->dwTxtFileNo == 376)
					cellNo = 376;

				// If it isn't special, check for a preset.
				if (cellNo == -1 && preset->dwTxtFileNo <= 572) {
					ObjectTxt* obj = D2COMMON_GetObjectTxt(preset->dwTxtFileNo);
					if (obj)
						cellNo = obj->nAutoMap;//Set the cell number then.
				}
			}
			else if (preset->dwType == UNIT_TILE) {
				/*LevelList* level = new LevelList;
				for (RoomTile* tile = room->pRoomTiles; tile; tile = tile->pNext) {
					if (*(tile->nNum) == preset->dwTxtFileNo) {
						level->levelId = tile->pRoom2->pLevel->dwLevelNo;
						break;
					}
				}
				level->x = (preset->dwPosX + (room->dwPosX * 5));
				level->y = (preset->dwPosY + (room->dwPosY * 5));
				level->act = room->pLevel->pMisc->pAct->dwAct;
				automapLevels.push_back(level);*/
			}

			//Draw the cell if wanted.
			if ((cellNo > 0) && (cellNo < 1258))
			{
				AutomapCell* cell = D2CLIENT_NewAutomapCell();
				int x = (preset->dwPosX + (room->dwPosX * 5));
				int y = (preset->dwPosY + (room->dwPosY * 5));
				cell->xPixel = (((x - y) * 16) / 10) + 1;
				cell->yPixel = (((y + x) * 8) / 10) - 3;
				D2CLIENT_AddAutomapCell(cell, &((*p_D2CLIENT_AutomapLayer)->pObjects));
			}

		}
	}
	void RevealLevel(Level* level)
	{
		if (!level || level->dwLevelNo < 0 || level->dwLevelNo > 255) return;
		InitLayer(level->dwLevelNo);
		for (Room2* room = level->pRoom2First; room; room = room->pRoom2Next) {
			bool roomData = false;
			if (!room->pRoom1) {
				D2COMMON_AddRoomData(level->pMisc->pAct, level->dwLevelNo, room->dwPosX, room->dwPosY, room->pRoom1);
				roomData = true;
			}
			if (!room->pRoom1) continue;
			D2CLIENT_RevealAutomapRoom(room->pRoom1, TRUE, *p_D2CLIENT_AutomapLayer);
			RevealRoom(room);
			if (roomData) D2COMMON_RemoveRoomData(level->pMisc->pAct, level->dwLevelNo, room->dwPosX, room->dwPosY, room->pRoom1);
		}
	}
	void RevealAct(int act)
	{
		UnitAny* player = D2CLIENT_GetPlayerUnit();
		if (!player || !player->pAct) return;
		int actIds[6] = { 1, 40, 75, 103, 109, 137 };
		Act* pAct = D2COMMON_LoadAct(act - 1, player->pAct->dwMapSeed, *p_D2CLIENT_ExpCharFlag, 0, D2CLIENT_GetDifficulty(), NULL, actIds[act - 1], D2CLIENT_LoadAct_1, D2CLIENT_LoadAct_2);
		if (!pAct || !pAct->pMisc) return;
		for (int level = actIds[act - 1]; level < actIds[act]; level++) {
			Level* pLevel = GetLevel(pAct, level);
			if (!pLevel) continue;
			if (!pLevel->pRoom2First) D2COMMON_InitLevel(pLevel);
			RevealLevel(pLevel);
		}
		InitLayer(player->pPath->pRoom1->pRoom2->pLevel->dwLevelNo);
		//D2COMMON_UnloadAct(pAct);
	}
	void RevealGame() {
		for (int act = 1; act <= ((*p_D2CLIENT_ExpCharFlag) ? 5 : 4); act++) RevealAct(act);
	}
};
