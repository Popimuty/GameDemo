#include "pch.h"
#include "WinCreateLoop.h"


WinCreateLoop::WinCreateLoop()
	: m_hInstance(nullptr)
		, m_hWnd(nullptr)
	{
		m_pInstance = this;
}

WinCreateLoop::~WinCreateLoop()
{

}

WinCreateLoop* WinCreateLoop::m_pInstance = nullptr;

// wparam : 특정 키보드나 마우스의 어느 키가 눌리었을때 주로 사용
// iparam : x,y 좌표값을 사용할때 주소 사용
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WinCreateLoop* wThis = nullptr;
	// WM_NCCREATE: 윈도우 생성 아주 초기에, 프레임 생성 전에. WM_CREATE보다 이전에발생
	if (uMsg == WM_NCCREATE)
	{

		//reinterpret_cast<바꿀 타입>(대상) : 포인터 끼리의 타입 변환 함수
		CREATESTRUCT* tmp_s = reinterpret_cast<CREATESTRUCT*>(lParam);
		wThis = reinterpret_cast<WinCreateLoop*>(tmp_s->lpCreateParams);

		// HWND에 this 포인터 저장
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(wThis));
	}
	else {
		// WM_NCCREATE가 아닐 때는 HWND에서 this 포인터를 가져온다
		wThis = reinterpret_cast<WinCreateLoop*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	}


	// 멤버 함수 호출, 함수의 메세지 처리하는 가상함수를 호출을 해줘야함
	if (wThis)
		wThis->WndProc(hwnd, uMsg, wParam, lParam);

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
	//WndProc이 클래스의 맴버 변수로 들어가면서, 리턴값이 맞지 않음!!
}
void WinCreateLoop::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
}

// hInstance : 프로그램의 주소값
// lpCmdLine : 윈도우 명령에 사용되는 명령어를 넣는곳, 이것을 분기로 하여 코드를 짤 수 있음
// GetModuleFileNameA(NULL, szPath, MAX_PATH) : 현재 실행 중인 모듈(= EXE나 DLL)의 전체 경로를 반환
//												NULL을 주면 현재 실행 중인 EXE의 경로를 반환.
//GetCurrentDirectoryA(MAX_PATH, szPath) : 현재 프로세스의 작업 디렉토리 (working directory) 를 반환
//OutputDebugStringA(...) :디버그 콘솔에 문자열을 출력
//c_str() : string을 char* 형태로 바꿔주는 메서드
void WinCreateLoop::Initialize()
{
	char szPath[MAX_PATH] = { 0, };
	GetModuleFileNameA(NULL, szPath, MAX_PATH); // 현재 모듈의 경로
	m_ModulePath = szPath; // 모듈 경로
	GetCurrentDirectoryA(MAX_PATH, szPath); //작업 디렉토리
	m_WorkingPath = szPath; // 작업 디렉토리
	OutputDebugStringA(std::string(std::string(m_ModulePath) + std::string("\n")).c_str());
	OutputDebugStringA(std::string(std::string(m_WorkingPath) + std::string("\n")).c_str());
	//printf("Current Directory: %s\n", szPath);

	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = m_hInstance;
	wc.lpszClassName = m_szWinName.c_str();
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// 기본 커서 모양
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// 기본 아이콘 모양
	RegisterClass(&wc);
	// rect(왼,위,오,바닥)
	// 각각 화면에서의 좌표를 의미함
	// 원하는 크기가 조정되어 리턴
	RECT rcClient = { 0, 0, (LONG)m_Width, (LONG)m_Height };
	AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);

	// https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nf-winuser-createwindowexw
	// 매개변수4. https://kaspyx.tistory.com/32
	m_hWnd = CreateWindowExW(
		0,
		m_szWinName.c_str(),
		m_TitleName.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,//위치좌표 xy
		rcClient.right - rcClient.left, rcClient.bottom - rcClient.top,
		NULL, NULL, m_hInstance, this);

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);
	//각종 Initalize 넣기!!
}

	

void WinCreateLoop::Loop() {
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);// 메세지 전달
			DispatchMessage(&msg);// 메세지 처리 -> 여기 없는값 -> DefWindowProc : 윈도우에서 처리
		}

	}
	//up
	//ren
}


void WinCreateLoop::Update() {

}

void WinCreateLoop::Render() {

}