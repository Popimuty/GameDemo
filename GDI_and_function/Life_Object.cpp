#include "pch.h"
#include "Life_Object.h"

//float pos_x, pos_y = 0; // 이미지 하단 중심부!
//float width, height = 0; // 해당 이미지 폭,높이
//float bit_pos_x, bit_pos_y = 0; // 비트맵 기준 x,y좌표
//float min_x, min_y, max_x, max_y = 0; // AABB()에 사용할 좌표

void Life_Object::pos_cal() {
	bit_pos_x = pos_x - width / 2;
	bit_pos_y = pos_y - height;
	min_x = pos_x - width / 2;
	max_x = pos_x + width / 2;
	min_y = pos_y - height;
	max_y = pos_y;
}