#include "pch.h"
#include "PlayScene.h"
#include "Draw.h"
#include "enemy.h"
#include "player.h"
#include "Timer.h"
#include "SceneMove.h"


void PlayScene::Scene_init() {
	playTime = 0;
	enemy_manager::Get().Create_enemy(8);
	player_tmp.Initalize();
}


void PlayScene::Update() {
	playTime += Timer::Get().deltaTime();
	enemy_manager::Get().Update();
	player_tmp.Update();
	if (playTime >= 10.0) {
		enemy_manager::Get().all_Destroy_enemy();
		SceneMove::Get().ChangeScene(2);
	}
	
}


void PlayScene::Render() {
	
	//Draw::Get().Drow_Image(storage_, width_stay, height_stay, 0, 0, 0, 0);
	enemy_manager::Get().enemy_Render();
	player_tmp.Render();
}