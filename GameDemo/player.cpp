#include "pch.h"
#include "player.h"
#include "Draw.h"
#include "Input.h"
#include "Vector.h"
#include "Timer.h"
#include "enemy_manager.h"


int player::count = 0;
void player::Initalize() {
	player::count = 0;
	srand((unsigned int)time(NULL));
	pos.x = 500;
	pos.y = 400;
	storage_player_u = new Gdiplus::Bitmap(L"../image/player_u.png");
	im_wid_hei.x = storage_player_u->GetWidth();
	im_wid_hei.y = storage_player_u->GetHeight();
	storage_player_d = new Gdiplus::Bitmap(L"../image/player_d.png");
	storage_player_l = new Gdiplus::Bitmap(L"../image/player_l.png");
	storage_player_r = new Gdiplus::Bitmap(L"../image/player_r.png");
	now_player = UP;
	player::pos_cal();
	
}
void player::Update() {
	player::move();
	player::pos_cal();	
	player::check_coll();
}

void player::Render() {
	switch (now_player)
	{
	case player::UP:
		Draw::Get().Draw_Image(storage_player_u, im_wid_hei.x, im_wid_hei.y, bit_pos.x, bit_pos.y, 0, 0);
		break;
	case player::DOWN:
		Draw::Get().Draw_Image(storage_player_d, im_wid_hei.x, im_wid_hei.y, bit_pos.x, bit_pos.y, 0, 0);
		break;
	case player::RIGHT:
		Draw::Get().Draw_Image(storage_player_r, im_wid_hei.y,im_wid_hei.x, bit_pos.x, bit_pos.y, 0, 0);
		break;
	case player::LEFT:
		Draw::Get().Draw_Image(storage_player_l, im_wid_hei.y, im_wid_hei.x, bit_pos.x, bit_pos.y, 0, 0);
		break;
	default:
		break;
	}
}


void player::move() {
	speed = 100;
	if (KeyState::KEY_DOWN == Input::Get().check(37)
		|| KeyState::KEY_HOLD == Input::Get().check(37)) {
		now_player = LEFT;
		tmp.get_vect(-1, 0);
		pos += tmp * (float)Timer::Get().deltaTime() * (float)speed;
	}
	if (KeyState::KEY_DOWN == Input::Get().check(39)
		|| KeyState::KEY_HOLD == Input::Get().check(39)) {
		now_player = RIGHT;
		tmp.get_vect(1, 0);
		pos += tmp * (float)Timer::Get().deltaTime() * speed;
	}
	if (KeyState::KEY_DOWN == Input::Get().check(38)
		|| KeyState::KEY_HOLD == Input::Get().check(38)) {
		now_player = UP;
		tmp.get_vect(0, -1);
		pos += tmp * (float)Timer::Get().deltaTime() * speed;
	}
	if (KeyState::KEY_DOWN == Input::Get().check(40)
		|| KeyState::KEY_HOLD == Input::Get().check(40)) {
		now_player = DOWN;
		tmp.get_vect(0, 1);
		pos += tmp * (float)Timer::Get().deltaTime() * speed;
	}
}

void player::pos_cal() {
	if (now_player == UP || now_player == DOWN) { // 회전시 중점에 따라서 비트맵이 그려지는 위치를 변경
		bit_pos.x = pos.x - im_wid_hei.x / 2;    
		bit_pos.y = pos.y - im_wid_hei.y / 2;
	}
	else
	{
		bit_pos.x = pos.x - im_wid_hei.y / 2;
		bit_pos.y = pos.y - im_wid_hei.x / 2;
	}
	if (now_player == UP || now_player == DOWN) { 
		min.x = pos.x - im_wid_hei.x / 2;
		max.x = pos.x + im_wid_hei.x / 2;
		min.y = pos.y - im_wid_hei.y / 2;
		max.y = pos.y + im_wid_hei.y / 2;
	}
	else
	{
		min.x = pos.x - im_wid_hei.y / 2;
		max.x = pos.x + im_wid_hei.y / 2;
		min.y = pos.y - im_wid_hei.x / 2;
		max.y = pos.y + im_wid_hei.x / 2;
	}
}

void player::check_coll(){
	for (int i = 0; i < enemy_manager::Get().p_enemy_list.size(); i++)
	{
		if ((max.x   >  enemy_manager::Get().p_enemy_list[i]->min.x
			&& enemy_manager::Get().p_enemy_list[i]->max.x   >   min.x)
			&& (max.y   >   enemy_manager::Get().p_enemy_list[i]->min.y
			&& enemy_manager::Get().p_enemy_list[i]->max.y   >   min.y)) {
			//wchar_t buffer[256];
			//swprintf_s(buffer, L"충돌: %f", this, min.x);  //디버그용
			//MessageBox(NULL, buffer, L"Debug - Render", MB_OK);
			enemy_manager::Get().Destroy_enemy(i);
			count += 1;
		}
	}
}

int player::return_count() {
	int tmp = count;
	return tmp;
}