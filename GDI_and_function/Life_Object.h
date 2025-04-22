#pragma once


class Life_Object
{
// 오브젝트의 중심이 이미지 기준 하단 중심부에 위치하도록 설정할 예정
private:
	float pos_x, pos_y = 0; // 이미지 하단 중심부!
	float width, height = 0; // 해당 이미지 폭,높이
	float bit_pos_x, bit_pos_y = 0; // 비트맵 기준 x,y좌표
	float min_x, min_y, max_x, max_y = 0; // AABB()에 사용할 좌표
public:
	Life_Object() = default;
	virtual ~Life_Object() = default;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Initalize() = 0;
	void pos_cal();
};

