
#include "pch.h"
#include "GameApp.h"




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{


   GameApp gameapp;
    gameapp.Initialize();
    gameapp.Loop();
    gameapp.Shutdown();
    return (int)1;
}