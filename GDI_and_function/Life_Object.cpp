#include "pch.h"
#include "Life_Object.h"
#include "Vector.h"

//float pos_x, pos_y = 0; // 이미지 하단 중심부!
//float width, height = 0; // 해당 이미지 폭,높이
//float bit_pos_x, bit_pos_y = 0; // 비트맵 기준 x,y좌표
//float min_x, min_y, max_x, max_y = 0; // AABB()에 사용할 좌표

void Life_Object::pos_cal() {
	bit_pos.x = pos.x - im_wid_hei.x / 2;
	bit_pos.y = pos.y - im_wid_hei.y;
	min.x = pos.x - im_wid_hei.x / 2;
	max.x = pos.x + im_wid_hei.x / 2;
	min.y = pos.y - im_wid_hei.y;
	max.y = pos.y;
}

void Life_Object::Initalize() {
	pos.get_vect(0,0);		
	im_wid_hei.get_vect(0, 0);
	bit_pos.get_vect(0, 0);
	min.get_vect(0, 0);
	max.get_vect(0, 0);
}