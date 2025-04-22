
#include "pch.h"
#include "GameApp.h"

// 할것 : 오브젝트, 적 , 플레이어(이동) 완성 
//        각 scene  chage 설정하기 -> playscene에 타이머 필요!


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