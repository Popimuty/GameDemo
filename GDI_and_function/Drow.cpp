#include "pch.h"                  // 가장 먼저! (PCH 사용 시)
//#include "Renderer.h"



//- Kernel : 메모리를 관리하고 프로그램 실행을 담당 
//- GDI : 화면 처리와 그래픽을 담당 
//- User : User Interface와 Window를 관리

Gdiplus::Graphics* graphics;
HDC g_FrontBufferDC;
HDC g_BackBufferDC;
HBITMAP g_BackBufferBitmap;
ULONG_PTR g_GdiPlusToken;
void DrawImage(int, int, Gdiplus::Bitmap*, int, int, int, int);
void Drow_Initalize(HWND g_hWnd, int g_width, int g_height)
{
	if (g_hWnd == nullptr) {
		MessageBox(NULL, L"g_hWnd가 nullptr입니다.", L"오류", MB_OK);
	}

	g_FrontBufferDC = GetDC(g_hWnd); //윈도우 클라이언트 영역의 DeviceContext얻기,지정 창의 클라이언트 영역을 업데이트함
	g_BackBufferDC = CreateCompatibleDC(g_FrontBufferDC); // 호환되는 DeviceContext 생성
	g_BackBufferBitmap = CreateCompatibleBitmap(g_FrontBufferDC, g_width, g_height); // 메모리 영역생성
	SelectObject(g_BackBufferDC, g_BackBufferBitmap); // MemDC의 메모리영역 지정
	// GDI+ 초기화
	g_GdiPlusToken;
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&g_GdiPlusToken, &gsi, nullptr);
	graphics = Gdiplus::Graphics::FromHDC(g_BackBufferDC);
}


// TODO: 라이브러리 함수의 예제입니다.
void Drow(Gdiplus::Bitmap* bitmap, int width, int height, int g_width, int g_height)
{

	PatBlt(g_BackBufferDC, 0, 0, g_width, g_height, WHITENESS);
	//Renderer_Initalize();if (bitmap != nullptr)
	DrawImage(0, 0, bitmap, 0, 0, width, height);
	// Renderer::EndDraw()
	BitBlt(g_FrontBufferDC, 0, 0, g_width, g_height, g_BackBufferDC, 0, 0, SRCCOPY);
}




void DrawImage(int x, int y, Gdiplus::Bitmap* bitmap, int srcX, int srcY, int srcWitdh, int srcHeight)
{
	Gdiplus::Rect srcRect(srcX, srcY, srcWitdh, srcHeight); // 소스의 영역
	Gdiplus::Rect destRect(x, y, srcRect.Width, srcRect.Height); // 화면에 그릴 영역
	graphics->DrawImage(bitmap, destRect, srcRect.X, srcRect.Y,  // 소스의 일부분만을 그린다. 
		srcRect.Width, srcRect.Height, Gdiplus::UnitPixel);
}
//graphics->DrawImage(character, x, y, character->GetWidth(), character->GetHeight());
void EndDrow(HWND g_hWnd) {
	DeleteObject(g_BackBufferBitmap);
	DeleteDC(g_BackBufferDC);
	ReleaseDC(g_hWnd, g_FrontBufferDC);
}
