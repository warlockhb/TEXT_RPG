#include "BossMonster.h"

BossMonster::BossMonster(string _name, int _hp, int _power)
	: Monster(_name, _hp, _power)
	, gen(std::random_device{}( ))

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
	//std::uniform_real_distribution<> dist1(1 , 5);
	//int randomNum = dist1(gen);

	return _Power;
}

void BossMonster::TakeDamage(int _damage)
{
	_Hp -= _damage;
}
