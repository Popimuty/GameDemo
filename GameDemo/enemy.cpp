#include "pch.h"
#include "enemy.h"
#include "Draw.h"

void enemy::Initalize() {
	//srand((unsigned int)time(NULL));
	storage_stay = new Gdiplus::Bitmap(L"../image/bug.png");
	im_wid_hei.x = storage_stay->GetWidth();
	im_wid_hei.y = storage_stay->GetHeight();
	pos.x = (rand() * (enemy_num + 1) * 73) % 800 + 50;
	pos.y = (rand() * (enemy_num + 1) * 73) % 600 + 50;
	pos_cal();
}
void enemy::Update() {

}
void enemy::Render() {
	//x, y	화면에 그릴 위치(좌측 상단 좌표)
	//bitmap	그릴 이미지의 포인터(Gdiplus::Bitmap*)
	//srcX, srcY	비트맵 내부에서 시작할 위치(자르기 시작 좌표)
	//srcWidth, srcHeight	비트맵에서 잘라낼 너비와 높이
	Draw::Get().Draw_Image(storage_stay, im_wid_hei.x,im_wid_hei.y, bit_pos.x, bit_pos.y, 0, 0);
}

void enemy::pos_cal() {
	bit_pos.x = pos.x - im_wid_hei.x / 2;
	bit_pos.y = pos.y - im_wid_hei.y;
	min.x = pos.x - im_wid_hei.x / 2;
	max.x = pos.x + im_wid_hei.x / 2;
	min.y = pos.y - im_wid_hei.y;
	max.y = pos.y;
}