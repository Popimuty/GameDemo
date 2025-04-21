#include "pch.h"
#include "MenuScene.h"
#include "Drow.h"

void MenuScene::Render() {

}

void MenuScene::Scene_init() {
	storage_stay = new Gdiplus::Bitmap(L"../charactor/player.png");
	width_stay = storage_stay->GetWidth();
	height_stay = storage_stay->GetHeight();
}

void MenuScene::Update() {
	Drow::Get().Drow_Image(storage_stay, width_stay, height_stay);
}