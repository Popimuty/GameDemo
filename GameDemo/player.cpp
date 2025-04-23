#include "pch.h"
#include "player.h"
#include "Draw.h"
#include "Input.h"
void player::Initalize() {
	srand((unsigned int)time(NULL));
	pos_x = 500;
	pos_y = 400;
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


void player::move() {
	if (KeyState::KEY_DOWN == Input::Get().check(37)
		&& KeyState::KEY_HOLD == Input::Get().check(37)) {
		
	}
	if (KeyState::KEY_DOWN == Input::Get().check(38)
		&& KeyState::KEY_HOLD == Input::Get().check(38)) {

	}
	if (KeyState::KEY_DOWN == Input::Get().check(39)
		&& KeyState::KEY_HOLD == Input::Get().check(39)) {

	}
	if (KeyState::KEY_DOWN == Input::Get().check(40)
		&& KeyState::KEY_HOLD == Input::Get().check(40)) {

	}
}