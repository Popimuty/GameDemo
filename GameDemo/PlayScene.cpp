#include "pch.h"
#include "PlayScene.h"
#include "Draw.h"
#include "enemy.h"


void PlayScene::Scene_init() {

	storage_player = new Gdiplus::Bitmap(L"../image/player.png");
	width_player = storage_player->GetWidth();
	height_player = storage_player->GetHeight();

	//wchar_t buffer[256];
	//swprintf_s(buffer, L"[Scene_init]\nthis: %p\nstorage_stay: %d", this, width_stay); // 디버그용
	//MessageBox(NULL, buffer, L"Debug - Scene_init", MB_OK);
}


void PlayScene::Update() {

}


void PlayScene::Render() {
	//wchar_t buffer[256];
	//swprintf_s(buffer, L"[Render]\nthis: %p\nstorage_stay: %p", this, storage_stay);  //디버그용
	//MessageBox(NULL, buffer, L"Debug - Render", MB_OK);

	//Draw::Get().Drow_Image(storage_, width_stay, height_stay, 0, 0, 0, 0);

	enemy_tmp.Render(); 
	
}