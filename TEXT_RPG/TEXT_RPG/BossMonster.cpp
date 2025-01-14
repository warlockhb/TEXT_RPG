#include "BossMonster.h"

BossMonster::BossMonster(string _name, int _hp, int _power)
	:Monster(_name, _hp, _power)
{
}

BossMonster::~BossMonster()
{
}

string BossMonster::GetName()
{
	return _Name;
}

int BossMonster::GetHp()
{
	return (_Hp > 0) ? _Hp : 0;
}

int BossMonster::GetPower()
{
	return _Power;
}

void BossMonster::TakeDamage(int _damage)
{
	_Hp -= _damage;
}
