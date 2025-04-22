#include "pch.h"
#include "player.h"
#include "Draw.h"
void player::Initalize() {
	srand((unsigned int)time(NULL));
	pos_x = rand() % 900 + 50;
	pos_y = rand() % 400 + 50;
	storage_stay = new Gdiplus::Bitmap(L"../image/player.png");
	width = storage_stay->GetWidth();
	height = storage_stay->GetHeight();
}
void player::Update() {
	pos_cal();
}
void player::Render() {
	Draw::Get().Drow_Image(storage_stay, width, height, 0, 0, 0, 0);
}