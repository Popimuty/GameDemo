#include "pch.h"


#include "MenuScene.h"
#include "Drow.h"
#include "SceneMove.h"



void MenuScene::Render() {
	wchar_t buffer[256];
	swprintf_s(buffer, L"[Render]\nthis: %p\nstorage_stay: %p", this, storage_stay);  //디버그용
	MessageBox(NULL, buffer, L"Debug - Render", MB_OK);
	
	Drow::Get().Drow_Image(storage_stay, width_stay, height_stay, 0, 0, 0, 0);
}

void MenuScene::Scene_init() {
	storage_stay = new Gdiplus::Bitmap(L"../charactor/player.png");
	width_stay = storage_stay->GetWidth();
	height_stay = storage_stay->GetHeight();

	wchar_t buffer[256];
	swprintf_s(buffer, L"[Scene_init]\nthis: %p\nstorage_stay: %p", this, storage_stay); // 디버그용
	MessageBox(NULL, buffer, L"Debug - Scene_init", MB_OK);
	
}

void MenuScene::Update() {
	
}