#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Monster
{
protected:
	string _Name;
	int _Hp;
	int _Power;

public:
	Monster(string _name, int _hp, int _power);
	~Monster();

	virtual string GetName() = 0;
	virtual int GetHp() = 0;
	virtual int GetPower() = 0;
	virtual void TakeDamage(int _damage) = 0;
};