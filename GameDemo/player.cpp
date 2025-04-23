#include "pch.h"
#include "player.h"
#include "Draw.h"
#include "Input.h"
#include "Vector.h"
#include "Timer.h"

void player::Initalize() {
	srand((unsigned int)time(NULL));
	pos.x = 500;
	pos.y = 400;
	storage_stay = new Gdiplus::Bitmap(L"../image/player.png");
	im_wid_hei.x = storage_stay->GetWidth();
	im_wid_hei.y = storage_stay->GetHeight();
}
void player::Update() {

	pos_cal();	
}

void player::Render() {
	Draw::Get().Drow_Image(storage_stay, im_wid_hei.x, im_wid_hei.y, 0, 0, 0, 0);
}


void player::move() {
	speed = 10;
	Vector2 tmp;
	if (KeyState::KEY_DOWN == Input::Get().check(37)
		&& KeyState::KEY_HOLD == Input::Get().check(37)) {

		tmp.get_vect(-1, 0);
		pos += tmp * (float)Timer::Get().deltaTime();
	}

	if (KeyState::KEY_DOWN == Input::Get().check(38)
		&& KeyState::KEY_HOLD == Input::Get().check(38)) {

		tmp.get_vect(0, -1);
		pos += tmp * (float)Timer::Get().deltaTime();
	}
	if (KeyState::KEY_DOWN == Input::Get().check(39)
		&& KeyState::KEY_HOLD == Input::Get().check(39)) {

		tmp.get_vect(1, 0);
		pos += tmp * (float)Timer::Get().deltaTime();
	}
	if (KeyState::KEY_DOWN == Input::Get().check(40)
		&& KeyState::KEY_HOLD == Input::Get().check(40)) {

		tmp.get_vect(0, 1);
		pos += tmp * (float)Timer::Get().deltaTime();
	}
}