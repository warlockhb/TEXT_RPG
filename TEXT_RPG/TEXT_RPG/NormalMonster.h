#pragma once
#include "Monster.h"

class NormalMonster : public Monster
{
private:

public:
	NormalMonster(string _name, int _hp, int _power);
	~NormalMonster();

	string GetName() override;
	int GetHp() override;
	int GetPower() override;
	void TakeDamage(int _damage) override;
};

