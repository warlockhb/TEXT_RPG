#include "MonsterManager.h"
#include "Logger.h"
#include "Calculator.h"
#include "BossMonster.h"
#include "NormalMonster.h"


MonsterManager::MonsterManager()
	: monster(nullptr)
	, gen(std::random_device{}())
{
}

MonsterManager::~MonsterManager()
{
}

Monster* MonsterManager::CreateNormalMonster()
{
	if (monster != nullptr)
		return monster;

	std::uniform_int_distribution<> dist(0, 5); // 0 ~ 3
	int randomNum = dist(gen); // ���� ��ȣ ����

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

	// �÷��̾� ������ ���� ���� �������ͽ� �������ֱ�.
	monster = new NormalMonster(monsterName, 100, 100);

	return monster;
}

Monster* MonsterManager::CreateBossMonster()
{
	if (monster != nullptr)
		return monster;

	// �߰��۾�.
	string monsterName = "Boss Monster";
	monster = new BossMonster(monsterName, 100, 100);

	return monster;
}

void MonsterManager::DeleteMonster(Monster* _monster)
{
	if (_monster == nullptr)
		return;

	// monster ������ ���� �������� item drop.

	// monster óġ��� ����
	Logger::GetInstance().RecordMonsterDefeated(_monster->GetName());
	
	// monster����
	delete _monster;
	_monster = nullptr;
}

//string MonsterManager::GetName()
//{
//	if (monster != nullptr)
//		return monster->GetName();
//
//	return string();
//}
//
//int MonsterManager::GetHp()
//{
//	if (monster != nullptr)
//		return monster->GetHp();
//
//	return 0;
//}
//
//int MonsterManager::GetPower()
//{
//	if (monster != nullptr)
//		return monster->GetPower();
//
//	return 0;
//}
//
//void MonsterManager::TakeDamage(int _damage)
//{
//	if (monster != nullptr)
//		monster->TakeDamage(_damage);
//}
