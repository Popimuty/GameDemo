#pragma once
#include "pch.h"
#include "Life_Object.h"

class player : public Life_Object
{
private:
	enum player_state { UP = 0, DOWN = 1, RIGHT = 2, LEFT = 3 };
	player_state now_player;
	Vector2 pos;		// 이미지 하단 중심부!
	Vector2 im_wid_hei; // 해당 이미지 폭,높이
	Vector2 bit_pos;    // 비트맵 기준 x,y좌표
	Vector2 min, max;   // AABB()에 사용할 좌표
	Vector2 tmp;
	float speed;
	Gdiplus::Bitmap* storage_player_r;
	Gdiplus::Bitmap* storage_player_l;
	Gdiplus::Bitmap* storage_player_u;
	Gdiplus::Bitmap* storage_player_d;
public:
	int count = 0;
	virtual void Initalize()override;
	virtual void Update()override;
	virtual void Render()override;
	void move();
	void pos_cal();
	void check_coll();
	int return_count();
};

