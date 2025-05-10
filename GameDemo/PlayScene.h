#pragma once
#include "Scene.h"
#include "enemy.h"
#include "enemy_manager.h"
#include "player.h"
class PlayScene : public Scene
{
private:

	enemy enemy;
	player player_tmp;
	double playTime;
public:
	virtual void Scene_init() override;
	virtual void Update() override;
	virtual void Render()override;
};

