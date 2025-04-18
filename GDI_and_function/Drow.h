#pragma once

#include "SingleTone.h"

class  Drow : public SingleTon<Drow> {
public:
	Drow() = default;
	~Drow() = default;
private:
	HWND win_hWnd;
	int win_width;
	int win_height;
	int im_width;
	int im_height;
	Gdiplus::Graphics* graphics;
	HDC m_FrontBufferDC;
	HDC m_BackBufferDC;
	HBITMAP m_BackBufferBitmap;
	ULONG_PTR m_GdiPlusToken;
	Gdiplus::Bitmap* now_bitmap;
public:
	void Drow_Initalize(HWND hWnd, int width, int height);
	// TODO: 라이브러리 함수의 예제입니다.
	void Drow_Image(Gdiplus::Bitmap* bitmap, int im_width, int im_height, int locate_x, int locate_y, int srcX, int srcY);
	void Drow_End();

};