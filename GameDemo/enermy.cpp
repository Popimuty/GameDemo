#include "pch.h"
#include "enermy.h"
#include "Draw.h"

void enermy::Initalize() {
	srand((unsigned int)time(NULL));
	pos_x = rand() % 900 + 50;
	pos_y = rand() % 400 + 50;
	storage_stay = new Gdiplus::Bitmap(L"../image/bug.png");
	width = storage_stay->GetWidth();
	height = storage_stay->GetHeight();
}
void enermy::Update() {
	pos_cal();
}
void enermy::Render() {
	Draw::Get().Drow_Image(storage_stay, width, height, 0, 0, 0, 0);
}