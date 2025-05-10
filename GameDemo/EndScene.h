#pragma once
#include "Scene.h"

class EndScene : public Scene
{
private:
	Gdiplus::Bitmap* storage_back;
	int width_back = 0;
	int height_back = 0;
	std::wstring tmp;
public:
	void Scene_init();
	void Update();
	void Render();
};

