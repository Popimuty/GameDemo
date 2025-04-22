#include "pch.h"
#include <windows.h>
#include <objidl.h>
#include <stdlib.h>
#include <gdiplus.h> 
#pragma comment(lib, "gdiplus.lib")
#include "GameApp.h"
#include "MenuScene.h"
#include "SceneMove.h"


//__super  : 현재 클래스의 부모 클래스(기반 클래스) 를 참조
void GameApp::Initialize()
{
	__super::Initialize(); //  WinGameApp::Initialize();
	//scene
	SceneMove::Get().CreateScene<MenuScene>();
}

void GameApp::Shutdown()
{
	__super::Shutdown(); //  WinGameApp::Shutdown();
	//scene
}


