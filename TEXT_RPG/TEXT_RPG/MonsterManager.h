#pragma once
#include "Monster.h"

class MonsterManager
{
private:
	Monster* monster;

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

