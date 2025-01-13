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
	// 플레이어 레벨에 따라서 몬스터 생성.
	// monster = new Monster()
}

void MonsterManager::DeleteMonster()
{
	// monster 레벨에 따라서 랜덤으로 item drop.

	// monster 처치기록 저장
	if (monster != nullptr)
	{
		Logger::getInstance().recordMonsterDefeated(GetName());
	}

	// monster삭제

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
