#pragma once

#include "Scene.h"
#include <windows.h>
#include <objidl.h>
#include <stdlib.h>
#include <gdiplus.h> 
#pragma comment(lib, "gdiplus.lib")

class MenuScene : public Scene
{	
private:
	Gdiplus::Bitmap* storage_stay;
	int width_stay =0;
	int height_stay =0;
public:
	virtual void Scene_init() override;
	virtual void Update() override;
	virtual void Render()override;
};

