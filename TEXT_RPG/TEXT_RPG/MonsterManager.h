#pragma once
#include "Monster.h"
#include "Item/Item.h"
#include <random>

class MonsterManager
{
private:
	Monster* monster;
	std::mt19937 gen;		// random engine

public:
	MonsterManager();
	~MonsterManager();

	Monster* CreateNormalMonster();
	Monster* CreateBossMonster();
	void DeleteMonster(Monster* _monster);

	Item* DropItem();
	int	DropGold();
};