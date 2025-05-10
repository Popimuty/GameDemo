#pragma once
#include "Singletone.h"

class WinCreateLoop :public SingleTon<WinCreateLoop>
{
public:
	WinCreateLoop();
	virtual ~WinCreateLoop();
	static WinCreateLoop* m_pInstance;
private:
	HINSTANCE		m_hInstance;
	int				m_Width = 1024;
	int				m_Height = 768;
	std::wstring	m_szWinName = L"GDIEngineWindowClass";
	std::wstring	m_TitleName = L"GameTitle";
	std::string		m_ModulePath;
	std::string		m_WorkingPath;
	HWND			m_hWnd;
	
public:
	virtual void Initialize();
	virtual void Shutdown();
	virtual void WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void Loop();
private:
	void Update();
	void Render();
};