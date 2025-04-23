#include "pch.h"

#include "MenuScene.h"
#include "Draw.h"
#include "SceneMove.h"



void MenuScene::Scene_init() {
	storage_stay = new Gdiplus::Bitmap(L"../image/menu.png");
	width_stay = storage_stay->GetWidth();
	height_stay = storage_stay->GetHeight();
	
}

void MenuScene::Update() {
	if (KeyState::KEY_UP == Input::Get().check(32)) {
		SceneMove::Get().ChangeScene(1);
		
	}
}

void MenuScene::Render() {
	Draw::Get().Drow_Image(storage_stay, width_stay, height_stay, 0, 0, 0, 0);
}