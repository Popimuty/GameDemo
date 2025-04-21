#pragma once

#include "Scene.h"
class MenuScene : Scene
{	
private:
	Gdiplus::Bitmap* storage_stay;
	int width_stay;
	int height_stay;
	virtual void Scene_init() override;
	virtual void Update() override;
	virtual void Render()override;
};

