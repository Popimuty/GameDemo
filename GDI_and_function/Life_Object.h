#pragma once
#include"Vector.h"

class Life_Object
{
// 오브젝트의 중심이 이미지 기준 하단 중심부에 위치하도록 설정할 예정
private:
	Vector2 pos;		// 이미지 하단 중심부!
	Vector2 im_wid_hei; // 해당 이미지 폭,높이
	Vector2 bit_pos;    // 비트맵 기준 x,y좌표
	Vector2 min, max;   // AABB()에 사용할 좌표
public:
	Life_Object() = default;
	virtual ~Life_Object() = default;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Initalize() = 0;
	void pos_cal();
};

