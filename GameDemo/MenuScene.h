#pragma once

#include "Scene.h"
#include "Input.h"

class MenuScene : public Scene
{	
private:
	Gdiplus::Bitmap* storage_stay;
	int width_stay = 0;
	int height_stay = 0;
public:
	virtual void Scene_init() override;
	virtual void Update() override;
	virtual void Render()override;
};

