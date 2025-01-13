#include "MonsterManager.h"
#include "Logger.h"
#include "Calculator.h"


MonsterManager::MonsterManager()
	: monster(nullptr)
	, gen(std::random_device{}())
{
}

MonsterManager::~MonsterManager()
{
}

void MonsterManager::CreateMonster()
{
	std::uniform_int_distribution<> dist(0, 5); // 0 ~ 3
	int randomNum = dist(gen); // 랜덤 번호 생성

	string monsterName = "";

	if (randomNum == 0)
		monsterName = "Troll";
	else if (randomNum == 1)
		monsterName = "Goblin";
	else if (randomNum == 2)
		monsterName = "Slime";
	else if (randomNum == 3)
		monsterName = "Skeleton";
	else if (randomNum == 4)
		monsterName = "Golem";
	else if (randomNum == 5)
		monsterName = "Zombie";

	// 플레이어 레벨에 따라 몬스터 스테이터스 변경해주기.
	monster = new Monster(monsterName, 100, 100);
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
	delete monster;
	monster = nullptr;
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
