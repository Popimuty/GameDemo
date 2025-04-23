#pragma once
#include "Scene.h"
#include "enemy.h"
class PlayScene : public Scene
{
private:
	Gdiplus::Bitmap* storage_enemy;
	int width_enemy = 0;
	int height_enemy = 0;
	Gdiplus::Bitmap* storage_player;
	int width_player = 0;
	int height_player = 0;
	enemy enemy_tmp;
public:
	virtual void Scene_init() override;
	virtual void Update() override;
	virtual void Render()override;
};

