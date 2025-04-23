#pragma once
#include "pch.h"
#include "Life_Object.h"

class player : public Life_Object
{
	float pos_x, pos_y = 0; // 이미지 하단 중심부!
	float width, height = 0; // 해당 이미지 폭,높이
	float bit_pos_x, bit_pos_y = 0; // 비트맵 기준 x,y좌표
	float min_x, min_y, max_x, max_y = 0; // AABB()에 사용할 좌표
	Gdiplus::Bitmap* storage_stay;
public:
	virtual void Initalize()override;
	virtual void Update()override;
	virtual void Render()override;
	void move();
};

