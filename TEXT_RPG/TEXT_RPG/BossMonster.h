#pragma once
#include "Monster.h"

class BossMonster : public Monster
{
private:

public:
	BossMonster(string _name, int _hp, int _power);
	~BossMonster();

	string GetName() override;
	int GetHp() override;
	int GetPower() override;
	void TakeDamage(int _damage) override;
};

