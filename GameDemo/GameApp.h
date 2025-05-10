#pragma once
#include <windows.h>
#include <string>
#include "WinCreateLoop.h"
class GameApp : public WinCreateLoop
{
private:

public:
	GameApp() = default;
	~GameApp() = default;

	virtual void Initialize() override;
	virtual void Shutdown() override;
};

