#pragma once
#include "enemy.h"
class enemy_manager
{
private:
	std::vector<enemy*> p_enemy_list;
	enemy* p_enemy = nullptr;
public:
	void Destroy_enemy(int enemy_num);
	void Create_enemy(int);
	void enemy_Render();
};

