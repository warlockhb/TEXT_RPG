#pragma once
#include "Monster.h"
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

	//string GetName();
	//int GetHp();
	//int GetPower();
	//void TakeDamage(int _damage);
};

