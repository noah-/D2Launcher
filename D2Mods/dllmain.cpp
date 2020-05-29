#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "Maphack.h"
#include "Drawing.h"
#include "AutoTele.h"
AutoTele at = AutoTele();
bool newTarget = false;
int reveal = 0;
Vector v;
DWORD WINAPI ATThread(VOID* lpvoid) {
    while (true) {
        if (newTarget) {
            at.ManageTele(v);
            newTarget = false;
        }
        if (reveal) {
            Maphack().RevealAct(reveal);
            reveal = 0;
        }
        at.DoWork();
        Sleep(100);
    }
    return 1;
}
WNDPROC origWndProc;
LONG WINAPI GameWindowEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (uMsg == WM_KEYDOWN) {
        if (wParam == VK_NUMPAD0)
        {
            auto player = D2CLIENT_GetPlayerUnit();
            if (player) {
                v = vVector[player->pPath->pRoom1->pRoom2->pLevel->dwLevelNo * 4];
                newTarget = true;
            }
        }
        if (wParam == VK_NUMPAD1)
        {
            auto player = D2CLIENT_GetPlayerUnit();
            if (player) {
                v = vVector[player->pPath->pRoom1->pRoom2->pLevel->dwLevelNo * 4 + 1];
                newTarget = true;
            }
        }
        if (wParam == VK_NUMPAD2)
        {
            auto player = D2CLIENT_GetPlayerUnit();
            if (player) {
                v = vVector[player->pPath->pRoom1->pRoom2->pLevel->dwLevelNo * 4 + 2];
                newTarget = true;
            }
        }
        if (wParam == VK_NUMPAD3)
        {
            auto player = D2CLIENT_GetPlayerUnit();
            if (player) {
                v = vVector[player->pPath->pRoom1->pRoom2->pLevel->dwLevelNo * 4 + 3];
                newTarget = true;
            }
        }
        if (wParam == VK_NUMPAD4)
        {
            auto player = D2CLIENT_GetPlayerUnit();
            if (player) reveal = player->dwAct + 1;
        }
	}
	return (LONG)CallWindowProcA(origWndProc, hWnd, uMsg, wParam, lParam);
}
void Hooks() {
    origWndProc = (WNDPROC)GetWindowLong(D2GFX_GetHwnd(), GWL_WNDPROC);
    SetWindowLong(D2GFX_GetHwnd(), GWL_WNDPROC, (LONG)GameWindowEvent);
    Patch(Jump, 0x53B30, (int)GameDraw_Interception, 5).Install();
    Patch(Jump, 0x5ADB3, (int)GameAutomapDraw_Interception, 5).Install();
    //Patch(Jump, 0x4C990, (int)GameLoop_Interception, 6).Install();
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        CreateThread(0, 0, ATThread, 0, 0, 0);
        Hooks();
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH) {
    }
    return TRUE;
}

