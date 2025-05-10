#pragma once
#include "enemy.h"
#include "SingleTone.h"


class enemy_manager : public SingleTon<enemy_manager>
	{
	friend class SingleTon<enemy_manager>;
private:
	enemy_manager() = default;			// 다른 생성을 통한 생성자 호출은 금지
	~enemy_manager() = default;
private:
	enemy* p_enemy = nullptr;
public:
	std::vector<enemy*> p_enemy_list ;
	void Destroy_enemy(int enemy_num);
	void all_Destroy_enemy();
	void Create_enemy(int);
	void enemy_Render();
	void Update();
};

