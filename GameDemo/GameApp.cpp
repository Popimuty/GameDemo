#include "GameApp.h"


//__super  : 현재 클래스의 부모 클래스(기반 클래스) 를 참조
void GameApp::Initialize()
{
	__super::Initialize(); //  WinGameApp::Initialize();
	//scene
}

void GameApp::Shutdown()
{
	__super::Shutdown(); //  WinGameApp::Shutdown();
	//scene
}
