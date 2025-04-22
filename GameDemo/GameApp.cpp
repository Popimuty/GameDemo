#include "pch.h"

#include "GameApp.h"
#include "SceneMove.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"


//__super  : 현재 클래스의 부모 클래스(기반 클래스) 를 참조
void GameApp::Initialize()
{
	__super::Initialize(); //  WinGameApp::Initialize();
	//scene
	SceneMove::Get().CreateScene<MenuScene>();
	SceneMove::Get().CreateScene<PlayScene>();
	SceneMove::Get().CreateScene<EndScene>();
}

void GameApp::Shutdown()
{
	__super::Shutdown(); //  WinGameApp::Shutdown();
	//scene
}


