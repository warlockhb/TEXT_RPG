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

	void CreateMonster();
	void DeleteMonster();

	string GetName();
	int GetHp();
	int GetPower();
	void TakeDamage(int _damage);
};

