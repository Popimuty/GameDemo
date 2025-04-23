#include "pch.h"
#include "enemy_manager.h"
#include "enemy.h"



void enemy_manager::Create_enemy(int num)
{
	for (int i = 0; i < num; i++) {
		p_enemy = new enemy();
		p_enemy->pos.x = rand() % 850 + 50;
		p_enemy->pos.y = rand() % 600 + 50;
		p_enemy_list.push_back(p_enemy);
		p_enemy->enemy_num = p_enemy_list.size() - 1;
	}
	
}

void enemy_manager::enemy_Render() {
	for (int i = 0; i < p_enemy_list.size() - 1; i++) {
		p_enemy_list[i]->Render();
	}
}

void enemy_manager::Destroy_enemy(int enemy_num)
{
	p_enemy = new enemy();
	p_enemy_list.push_back(p_enemy);
	p_enemy->enemy_num = p_enemy_list.size() - 1;
}

