#include "pch.h"                  // 가장 먼저! (PCH 사용 시)
#include "Draw.h"
#include "WinCreateLoop.h"



//- Kernel : 메모리를 관리하고 프로그램 실행을 담당 
//- GDI : 화면 처리와 그래픽을 담당 
//- User : User Interface와 Window를 관리


void Draw::Drow_Init(HWND hWnd, int width, int height)
{
	
	win_hWnd = hWnd;
	win_width = width;
	win_height = height;
	if (win_hWnd == nullptr) {
		MessageBox(NULL, L"g_hWnd가 nullptr입니다.", L"오류", MB_OK);
	}
	m_FrontBufferDC = GetDC(win_hWnd); //윈도우 클라이언트 영역의 DeviceContext얻기,지정 창의 클라이언트 영역을 업데이트함
	m_BackBufferDC = CreateCompatibleDC(m_FrontBufferDC); // 호환되는 DeviceContext 생성
	m_BackBufferBitmap = CreateCompatibleBitmap(m_FrontBufferDC, win_width, win_height); // 메모리 영역생성
	SelectObject(m_BackBufferDC, m_BackBufferBitmap); // MemDC의 메모리영역 지정
	// GDI+ 초기화
	m_GdiPlusToken;
	
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&m_GdiPlusToken, &gsi, nullptr);
	graphics = Gdiplus::Graphics::FromHDC(m_BackBufferDC);
	if (graphics == nullptr) {
		MessageBox(NULL, L"graphics가 nullptr입니다", L"렌더 오류", MB_OK);
		return;
	}
}

//x, y	화면에 그릴 위치(좌측 상단 좌표)
//bitmap	그릴 이미지의 포인터(Gdiplus::Bitmap*)
//srcX, srcY	비트맵 내부에서 시작할 위치(자르기 시작 좌표)
//srcWidth, srcHeight	비트맵에서 잘라낼 너비와 높이





void Draw::Drow_Image(Gdiplus::Bitmap* bitmap, int im_width, int im_height, int locate_x, int locate_y, int srcX, int srcY)
{
	if (bitmap == nullptr) {
		MessageBox(NULL, L"Bitmap이 nullptr입니다.", L"오류", MB_OK);
		return;
	}
	PatBlt(m_BackBufferDC, 0, 0, win_width, win_height, BLACKNESS);
	//Renderer_Initalize();if (bitmap != nullptr)
	//int x, int y, Gdiplus::Bitmap* bitmap, int srcX, int srcY, int srcWitdh, int srcHeight
	
	Gdiplus::Rect srcRect(srcX, srcY, im_width, im_height); // 소스의 영역
	Gdiplus::Rect destRect(locate_x, locate_y, srcRect.Width, srcRect.Height); // 화면에 그릴 영역
	// 소스의 일부분만을 그린다. 
	Gdiplus::Status status = graphics->DrawImage(bitmap, destRect, srcRect.X, srcRect.Y,  
		srcRect.Width, srcRect.Height, Gdiplus::UnitPixel);
	// Renderer::EndDraw()
	BitBlt(m_FrontBufferDC, 0, 0, win_width, win_height, m_BackBufferDC, 0, 0, SRCCOPY);
}

void Draw::Drow_End() {
	DeleteObject(m_BackBufferBitmap);
	DeleteDC(m_BackBufferDC);
	ReleaseDC(win_hWnd, m_FrontBufferDC);
}
