#include "pch.h"
#include "enemy_manager.h"
#include "enemy.h"



void enemy_manager::Create_enemy(int num)
{
	for (int i = 0; i <= num; i++) {
		p_enemy = new enemy();
		p_enemy->Initalize();
		p_enemy_list.push_back(p_enemy);
		p_enemy->enemy_num = p_enemy_list.size() - 1;
	}
}

void enemy_manager::enemy_Render() {
	for (int i = 0; i < p_enemy_list.size(); i++) {
		p_enemy_list[i]->Render();
	}
}

void enemy_manager::Destroy_enemy(int enemy_num)
{
	enemy* tmp = p_enemy_list[enemy_num];
	p_enemy_list.erase(p_enemy_list.begin() + enemy_num);
	free(tmp);
}

void enemy_manager::Update() {

}