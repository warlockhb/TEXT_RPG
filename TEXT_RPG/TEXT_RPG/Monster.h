#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Monster
{
private:
	string _Name;
	int _Hp;
	int _Power;

public:
	Monster(string _name, int _hp, int _Power);
	~Monster();

	virtual string GetName();
	virtual int GetHp();
	virtual int GetPower();
	virtual void TakeDamage(int _damage);
};