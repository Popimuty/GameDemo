#pragma once
#include "pch.h"
#include "Life_Object.h"

class enemy : public Life_Object
{
	friend class enemy_manager;
private:
	int enemy_num = 0;
	Vector2 pos;		// 이미지 중심부!
	Vector2 im_wid_hei; // 해당 이미지 폭,높이
	Vector2 bit_pos;    // 비트맵 기준 x,y좌표
	
	Gdiplus::Bitmap* storage_stay;
	
public:
	virtual void Initalize()override;
	virtual void Update()override;
	virtual void Render()override;
	void pos_cal();
	Vector2 min, max;   // AABB()에 사용할 좌표
	
};

