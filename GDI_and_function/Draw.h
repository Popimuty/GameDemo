#pragma once

#include "SingleTone.h"

class  Draw : public SingleTon<Draw> {
public:
	Draw() = default;
	~Draw() = default;
private:
	HWND win_hWnd =NULL;
	int win_width  = 0;
	int win_height  = 0;
	int im_width = 0;
	int im_height = 0;
	Gdiplus::Graphics* graphics;
	HDC m_FrontBufferDC;
	HDC m_BackBufferDC;
	HBITMAP m_BackBufferBitmap;
	ULONG_PTR m_GdiPlusToken;
	Gdiplus::Bitmap* now_bitmap;
public:
	void Drow_Init(HWND hWnd, int width, int height);
	// TODO: 라이브러리 함수의 예제입니다.
	
	void Drow_Image(Gdiplus::Bitmap* bitmap, int im_width, int im_height, int locate_x, int locate_y, int srcX, int srcY);
	void Drow_End();

};