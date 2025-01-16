#pragma once
#include "Monster.h"
#include <random>

class BossMonster : public Monster
{
private:
	std::mt19937 gen;		// random engine

public:
	BossMonster(string _name, int _hp, int _power);
	~BossMonster();

	string GetName() override;
	int GetHp() override;
	int GetPower() override;
	void TakeDamage(int _damage) override;
};

