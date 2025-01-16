#include "NormalMonster.h"

NormalMonster::NormalMonster(string _name, int _hp, int _power)
	:Monster(_name, _hp, _power)
{
}

NormalMonster::~NormalMonster()
{
}

string NormalMonster::GetName()
{
	return _Name;
}

int NormalMonster::GetHp()
{
	return (_Hp > 0) ? _Hp : 0;
}

int NormalMonster::GetPower()
{
	return _Power;
}

void NormalMonster::TakeDamage(int _damage)
{
	_Hp -= _damage;
}
