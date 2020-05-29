#pragma once
#include <windows.h>
#include <string>
#include <map>
#include "Patch.h"
#include "D2Constants.h"
#include "D2Offsets.h"

wchar_t* AnsiToUnicode(const char* str, UINT codepage = CP_UTF8) {
	wchar_t* buf = NULL;
	int len = MultiByteToWideChar(codepage, 0, str, -1, buf, 0);
	buf = new wchar_t[len];
	MultiByteToWideChar(codepage, 0, str, -1, buf, len);
	return buf;
}
POINT CalculateTextLen(const wchar_t* szwText, int Font) {
	POINT ret = { 0, 0 };
	if (!szwText) return ret;
	DWORD dwWidth, dwFileNo;
	DWORD dwOldSize = D2WIN_SetTextSize(Font);
	ret.y = D2WIN_GetTextSize((wchar_t*)szwText, &dwWidth, &dwFileNo);
	ret.x = dwWidth;
	D2WIN_SetTextSize(dwOldSize);
	return ret;
}
POINT CalculateTextLen(const char* szwText, int Font) {
	POINT ret = { 0, 0 };
	if (!szwText) return ret;
	wchar_t* buf = AnsiToUnicode(szwText);
	ret = CalculateTextLen(buf, Font);
	delete[] buf;
	return ret;
}
bool IsInGame(void) {
	UnitAny* player = D2CLIENT_GetPlayerUnit();
	Control* firstControl = *p_D2WIN_FirstControl;
	if (player && !firstControl) {
		if (player->pInventory && player->pPath && player->pPath->pRoom1 && player->pPath->pRoom1->pRoom2 && player->pPath->pRoom1->pRoom2->pLevel && player->pPath->pRoom1->pRoom2->pLevel->dwLevelNo)
			return true;
	}
	return false;
}
POINT ScreenToAutomap(int x, int y) {
	POINT result = { 0, 0 };
	x *= 32;
	y *= 32;
	result.x = ((x - y) / 2 / (*p_D2CLIENT_Divisor)) - (*p_D2CLIENT_Offset).x + 8;
	result.y = ((x + y) / 4 / (*p_D2CLIENT_Divisor)) - (*p_D2CLIENT_Offset).y - 8;

	if (D2CLIENT_GetAutomapSize()) {
		--result.x;
		result.y += 5;
	}
	return result;
}
POINT GetScreenSize() {
	POINT ingame = { *p_D2CLIENT_ScreenSizeX, *p_D2CLIENT_ScreenSizeY }, oog = { 800, 600 };
	return IsInGame() ? ingame : oog;
}
POINT GetTextSize(std::string text, unsigned int font) {
	unsigned int height[] = { 10,11,18,24,10,13,7,13,10,12,8,8,7,12 };
	DWORD width, fileNo;
	wchar_t* wString = AnsiToUnicode(text.c_str());
	DWORD oldFont = D2WIN_SetTextSize(font);
	D2WIN_GetTextWidthFileNo(wString, &width, &fileNo);
	D2WIN_SetTextSize(oldFont);
	POINT point = { width, height[font] };
	delete[] wString;
	return point;
}
bool DrawString(unsigned int x, unsigned int y, int align, unsigned int font, TextColor color, std::string text, ...) {
	char buffer[4096];
	va_list arg;
	va_start(arg, text);
	vsprintf_s(buffer, 4096, text.c_str(), arg);
	va_end(arg);
	wchar_t* wString = AnsiToUnicode(buffer);
	unsigned int properX = x;
	if (align == 1) x = x - (GetTextSize(buffer, font).x / 2);
	if (align == 2) x = x - GetTextSize(buffer, font).x;
	unsigned int height[] = { 10,11,18,24,10,13,7,13,10,12,8,8,7,12 };
	if (align == 3) y = y + height[font];
	DWORD size = D2WIN_SetTextSize(font);
	D2WIN_DrawText(wString, x, y, color, 0);
	D2WIN_SetTextSize(size);
	delete[] wString;
	return true;
}
bool DrawBox(unsigned int x, unsigned int y, unsigned int xSize, unsigned int ySize, unsigned int color, BoxTrans trans) {
	D2GFX_DrawRectangle(x, y, x + xSize, y + ySize, color, trans);
	return true;
}
bool DrawCrosshook(unsigned int x, unsigned int y, unsigned int color) {
	CHAR szLines[][2] = { 0,-2, 4,-4, 8,-2, 4,0, 8,2, 4,4, 0,2, -4,4, -8,2, -4,0, -8,-2, -4,-4, 0,-2 };
	for (unsigned int n = 0; n < 12; n++) {
		D2GFX_DrawLine(x + szLines[n][0], y + szLines[n][1], x + szLines[n + 1][0], y + szLines[n + 1][1], color, -1);
	}
	return true;
}
bool IsValidMonster(UnitAny* pUnit)
{
	if (!pUnit) return false;
	if ((pUnit->dwMode == 0) || (pUnit->dwMode == 12)) return false;
	if ((pUnit->dwTxtFileNo == 608) && (pUnit->dwMode == 8)) return false;
	if ((pUnit->dwTxtFileNo == 68) && (pUnit->dwMode == 14)) return false;
	if ((pUnit->dwTxtFileNo == 258 || (pUnit->dwTxtFileNo == 261)) && (pUnit->dwMode == 14)) return false;
	DWORD badMonIds[] = { 227, 283, 326, 327, 328, 329, 330, 410, 411, 412, 413, 414, 415, 416, 366, 406, 351, 352, 353, 266, 408, 516, 517, 518, 519, 522, 523, 543, 543, 545 };
	for (DWORD n = 0; n < 30; n++) if (pUnit->dwTxtFileNo == badMonIds[n]) return false;
	if (D2COMMON_GetUnitStat(pUnit, 172, 0) == 2) return false;
	/*wchar_t* name = D2CLIENT_GetUnitName(pUnit);
	char* tmp = UnicodeToAnsi(name);

	if ((strcmp(tmp, "an evil force") == 0) || (strcmp(tmp, "dummy") == 0) || (strcmp(tmp, "Maggot") == 0)) {
		delete[] tmp;
		return false;
	}
	delete[] tmp;*/
	return true;
}
bool IsObjectChest(ObjectTxt* obj)
{
	//ObjectTxt *obj = D2COMMON_GetObjectTxt(objno);
	return (obj->nSelectable0 && (
		(obj->nOperateFn == 1) || //bed, undef grave, casket, sarc
		(obj->nOperateFn == 3) || //basket, urn, rockpile, trapped soul
		(obj->nOperateFn == 4) || //chest, corpse, wooden chest, buriel chest, skull and rocks, dead barb
		(obj->nOperateFn == 5) || //barrel
		(obj->nOperateFn == 7) || //exploding barrel
		(obj->nOperateFn == 14) || //loose bolder etc....*
		(obj->nOperateFn == 19) || //armor stand
		(obj->nOperateFn == 20) || //weapon rack
		(obj->nOperateFn == 33) || //writ
		(obj->nOperateFn == 48) || //trapped soul
		(obj->nOperateFn == 51) || //stash
		(obj->nOperateFn == 68)    //evil urn
		));
}
void DrawAutomapPrimitives() {
	UnitAny* player = D2CLIENT_GetPlayerUnit();
	if (!player || !player->pAct || player->pPath->pRoom1->pRoom2->pLevel->dwLevelNo == 0) return;
	std::map<std::string, unsigned int> monsterColors;
	auto MyPos = ScreenToAutomap(D2CLIENT_GetUnitX(player), D2CLIENT_GetUnitY(player));
	for (int i = 1; i <= 2; i++) {
		for (int j = 0; j <= 127; ++j) {
			for (UnitAny* unit = p_D2CLIENT_ServerSideUnitHashTables[i].table[j]; unit != NULL; unit = unit->pListNext) {

		//for (Room1* room1 = player->pAct->pRoom1; room1; room1 = room1->pRoomNext) {
		//	for (UnitAny* unit = room1->pUnitFirst; unit; unit = unit->pListNext) {
				DWORD xPos, yPos;
				if (unit->dwType == UNIT_MONSTER && IsValidMonster(unit)) {
					int color = 0x5B;
					if (unit->pMonsterData->fBoss & 1) color = 0x84;
					if (unit->pMonsterData->fChamp & 1) color = 0x91;
					if (unit->pMonsterData->fMinion & 1) color = 0x60;

					xPos = unit->pPath->xPos;
					yPos = unit->pPath->yPos;

					POINT automapLoc = ScreenToAutomap(xPos, yPos);
					DrawCrosshook(automapLoc.x, automapLoc.y, color);
				}
				/*else if (unit->dwType == UNIT_ITEM && (unit->dwFlags & UNITFLAG_REVEALED) == UNITFLAG_REVEALED) {
					UnitItemInfo uInfo;
					uInfo.item = unit;
					uInfo.itemCode[0] = D2COMMON_GetItemText(unit->dwTxtFileNo)->szCode[0];
					uInfo.itemCode[1] = D2COMMON_GetItemText(unit->dwTxtFileNo)->szCode[1];
					uInfo.itemCode[2] = D2COMMON_GetItemText(unit->dwTxtFileNo)->szCode[2];
					uInfo.itemCode[3] = 0;
					if (ItemAttributeMap.find(uInfo.itemCode) != ItemAttributeMap.end()) {
						uInfo.attrs = ItemAttributeMap[uInfo.itemCode];
						const vector<Action> actions = map_action_cache.Get(&uInfo);
						for (auto& action : actions) {
							// skip action if the ping level requirement isn't met
							if (action.pingLevel > Item::GetPingLevel()) continue;
							auto color = action.colorOnMap;
							auto borderColor = action.borderColor;
							auto dotColor = action.dotColor;
							auto pxColor = action.pxColor;
							auto lineColor = action.lineColor;
							xPos = unit->pItemPath->dwPosX;
							yPos = unit->pItemPath->dwPosY;
							automapBuffer.push_top_layer(
								[color, unit, xPos, yPos, MyPos, borderColor, dotColor, pxColor, lineColor]()->void {
									POINT automapLoc;
									Drawing::Hook::ScreenToAutomap(&automapLoc, xPos, yPos);
									if (borderColor != UNDEFINED_COLOR)
										Drawing::Boxhook::Draw(automapLoc.x - 4, automapLoc.y - 4, 8, 8, borderColor, Drawing::BTHighlight);
									if (color != UNDEFINED_COLOR)
										Drawing::Boxhook::Draw(automapLoc.x - 3, automapLoc.y - 3, 6, 6, color, Drawing::BTHighlight);
									if (dotColor != UNDEFINED_COLOR)
										Drawing::Boxhook::Draw(automapLoc.x - 2, automapLoc.y - 2, 4, 4, dotColor, Drawing::BTHighlight);
									if (pxColor != UNDEFINED_COLOR)
										Drawing::Boxhook::Draw(automapLoc.x - 1, automapLoc.y - 1, 2, 2, pxColor, Drawing::BTHighlight);
									if (lineColor != UNDEFINED_COLOR) {
										Drawing::Linehook::Draw(MyPos.x, MyPos.y, automapLoc.x, automapLoc.y, lineColor);
									}
								});
							if (action.stopProcessing) break;
						}
					}
				}*/
				else if (unit->dwType == UNIT_OBJECT && !unit->dwMode && IsObjectChest(unit->pObjectData->pTxt)) {
					xPos = unit->pObjectPath->dwPosX;
					yPos = unit->pObjectPath->dwPosY;
					auto automapLoc = ScreenToAutomap(xPos, yPos);
					DrawBox(automapLoc.x - 1, automapLoc.y - 1, 4, 4, 255, BoxTrans::BTHighlight);
				}
			}
			/*for (list<LevelList*>::iterator it = automapLevels.begin(); it != automapLevels.end(); it++) {
				if (player->pAct->dwAct == (*it)->act) {
					string tombStar = ((*it)->levelId == player->pAct->pMisc->dwStaffTombLevel) ? "\377c2*" : "\377c4";
					POINT unitLoc;
					Hook::ScreenToAutomap(&unitLoc, (*it)->x, (*it)->y);
					char* name = UnicodeToAnsi(D2CLIENT_GetLevelName((*it)->levelId));
					std::string nameStr = name;
					delete[] name;

					automapBuffer.push([nameStr, tombStar, unitLoc]()->void {
						Texthook::Draw(unitLoc.x, unitLoc.y - 15, Center, 6, Gold, "%s%s", nameStr.c_str(), tombStar.c_str());
						});
				}
			}*/
		}
	}
}

void GameDraw_Interception(void) {
	if (GetScreenSize().y > 1000) {
		int barFixHeight = (int)((48.0 / GetScreenSize().y) * (GetScreenSize().y - 26));
		DrawBox(165, GetScreenSize().y - 47, 725 - 165, 47, 0x0, BoxTrans::BTThreeFourths);
		DrawBox(725 + 470, GetScreenSize().y - 47, 725 - 165, 47, 0x0, BoxTrans::BTThreeFourths);
		DrawString(165 + (725 - 165) / 2, GetScreenSize().y - 5, 1, 3, TextColor::Gold, "shalzuth's maphack");
		DrawString(725 + 470 + 4, GetScreenSize().y - 35, 3, 7, TextColor::Gold, "N0 = Next Lvl");
		DrawString(725 + 470 + 4, GetScreenSize().y - 35 + 20, 3, 7, TextColor::Gold, "N1 = Objective");
		DrawString(725 + 470 + 4 + 200, GetScreenSize().y - 35 + 0, 3, 7, TextColor::Gold, "N2 = Waypoint");
		DrawString(725 + 470 + 4 + 200, GetScreenSize().y - 35 + 20, 3, 7, TextColor::Gold, "N3 = Previous Lvl");
		DrawString(725 + 470 + 4 + 400, GetScreenSize().y - 35, 3, 7, TextColor::Gold, "N4 = Reveal");
	}
	else
		DrawString(1, GetScreenSize().y - 1, 0, 6, TextColor::Gold, "shalzuth's maphack");
}
void GameAutomapDraw(void) {
	auto MyPos = ScreenToAutomap(D2CLIENT_GetUnitX(D2CLIENT_GetPlayerUnit()), D2CLIENT_GetUnitY(D2CLIENT_GetPlayerUnit()));
	DrawAutomapPrimitives();
}
void __declspec(naked) GameAutomapDraw_Interception()
{
	__asm
	{
		push eax;
		call GameAutomapDraw;
		pop eax;
		pop edi;
		pop esi;
		ret;
	}
}
