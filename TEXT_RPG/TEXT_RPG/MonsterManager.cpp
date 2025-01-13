#include "MonsterManager.h"
#include "Logger.h"
#include "Calculator.h"


MonsterManager::MonsterManager()
	: monster(nullptr)
{
}

MonsterManager::~MonsterManager()
{
}

void MonsterManager::CreateMonster()
{
	// �÷��̾� ������ ���� ���� ����.
	// monster = new Monster()
}

void MonsterManager::DeleteMonster()
{
	// monster ������ ���� �������� item drop.

	// monster óġ��� ����
	if (monster != nullptr)
	{
		Logger::getInstance().recordMonsterDefeated(GetName());
	}

	// monster����

}

string MonsterManager::GetName()
{
	if (monster != nullptr)
		return monster->GetName();

	return string();
}

int MonsterManager::GetHp()
{
	if (monster != nullptr)
		return monster->GetHp();

	return 0;
}

int MonsterManager::GetPower()
{
	if (monster != nullptr)
		return monster->GetPower();

	return 0;
}

void MonsterManager::TakeDamage(int _damage)
{
	if (monster != nullptr)
		monster->TakeDamage(_damage);
}
