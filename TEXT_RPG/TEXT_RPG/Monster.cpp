#include "Monster.h"


Monster::Monster(string _name, int _hp, int _Power)
	: _Name(_name)
	, _Hp(_hp)
	, _Power(_Power)
{
}

Monster::~Monster()
{
}

string Monster::GetName()
{
	return _Name;
}

int Monster::GetHp()
{
	return (_Hp > 0) ? _Hp : 0;
}

int Monster::GetPower()
{
	return _Power;
}

void Monster::TakeDamage(int _damage)
{
	_Hp -= _damage;
}
