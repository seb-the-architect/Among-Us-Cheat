// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Custom injected code entry point

#include "pch-il2cpp.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include "il2cpp-appdata.h"
#include "helpers.h"
#include "mem.h"

using namespace app;

// Set the name of your log file here
extern const LPCWSTR LOG_FILE = L"il2cpp-log.txt";

typedef void(*tSetKillTimer)(void* p_PlayerControl, float time);
tSetKillTimer oSetKillTimer;

void hSetKillTimer(void* __this, float time)
{
    oSetKillTimer(__this, 0.f);
}

// Custom injected code entry point
void Run()
{
    // Initialize thread data - DO NOT REMOVE
    il2cpp_thread_attach(il2cpp_domain_get());
    il2cppi_new_console();

    List_1_PlayerControl_* PlayerList;
    PlayerControl* Player;
    Vector2 pos;

    oSetKillTimer = (tSetKillTimer)PlayerControl_SetKillTimer;
    oSetKillTimer = (tSetKillTimer)TrampHook(oSetKillTimer, hSetKillTimer, 10);
    
    for (;;)
    {
        //Grabbing the player list
        //PlayerControl* localPlayer = (*PlayerControl__TypeInfo)->static_fields->LocalPlayer;
        //if (localPlayer->fields._cachedData)
        //{
            //localPlayer->fields._cachedData->fields.IsImpostor = true;
        //}
        
        PlayerList = (*PlayerControl__TypeInfo)->static_fields->AllPlayerControls;
        
        //Iterating through the player list
        for (int i = 0; i < PlayerList->fields._size; i++)
        {
            //Accessing a player via index
            Player = PlayerList->fields._items->vector[i];
            
            if (Player->fields._cachedData && false)
            {
                //If player isImposter
                if (Player->fields._cachedData->fields.IsImpostor)
                {
                    std::cout << "Imposter = " << il2cppi_to_string(Player->fields._cachedData->fields._playerName) << std::endl;
                    pos = PlayerControl_GetTruePosition(Player, NULL);
                    std::cout << "X: " << pos.x << ", Y: " << pos.y << "\n" << std::endl;
                }
                else
                {
                    std::cout << "Innocent = " << il2cppi_to_string(Player->fields._cachedData->fields._playerName) << std::endl;
                    pos = PlayerControl_GetTruePosition(Player, NULL);
                    std::cout << "X: " << pos.x << ", Y: " << pos.y << "\n" << std::endl;
                }
                std::cout << "=============================================\n" << std::endl;
                Sleep(1000);
            }
        }
        
    }
}