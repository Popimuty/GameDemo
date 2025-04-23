#include "pch.h"
#include "enemy.h"
#include "Draw.h"

void enemy::Initalize() {
	srand((unsigned int)time(NULL));
	storage_stay = new Gdiplus::Bitmap(L"../image/bug.png");
	im_wid_hei.x = storage_stay->GetWidth();
	im_wid_hei.y = storage_stay->GetHeight();
	wchar_t buffer[100];
	swprintf(buffer, 100, L"현재 enemy 수: %p", storage_stay);
	MessageBoxW(NULL, buffer, L"디버그", MB_OK);
}
void enemy::Update() {
	pos_cal();
}
void enemy::Render() {
	//x, y	화면에 그릴 위치(좌측 상단 좌표)
	//bitmap	그릴 이미지의 포인터(Gdiplus::Bitmap*)
	//srcX, srcY	비트맵 내부에서 시작할 위치(자르기 시작 좌표)
	//srcWidth, srcHeight	비트맵에서 잘라낼 너비와 높이
	Draw::Get().Drow_Image(storage_stay, im_wid_hei.x,im_wid_hei.y, pos.x,pos.y, 0, 0);
}
