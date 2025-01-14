#include "MonsterManager.h"
#include "Logger.h"
#include "Calculator.h"
#include "BossMonster.h"
#include "NormalMonster.h"
#include "Character.h"

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

	std::uniform_int_distribution<> dist(0, 5); // 0 ~ 5
	int randomNum = dist(gen); // �옖�뜡 踰덊샇 �깮�꽦

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

	// �뵆�젅�씠�뼱 �젅踰⑥뿉 �뵲�씪 紐ъ뒪�꽣 �뒪�뀒�씠�꽣�뒪 蹂�寃쏀빐二쇨린.
	monster = new NormalMonster(monsterName, 100, 100);

	return monster;
}

Monster* MonsterManager::CreateBossMonster()
{
	if (monster != nullptr)
		return monster;

	// 異붽���옉�뾽.
	string monsterName = "Boss Monster";
	monster = new BossMonster(monsterName, 100, 100);

	return monster;
}

void MonsterManager::DeleteMonster(Monster* _monster)
{
	if (_monster == nullptr)
		return;

	// Item Drop
	Item* item = DropItem();

	if ( item != nullptr )
		item->Apply(Character::GetInstance());


	// monster Recording
	Logger::GetInstance().RecordMonsterDefeated(_monster->GetName());
	
	// monster�궘�젣
	delete _monster;
	_monster = nullptr;
}

Item* MonsterManager::DropItem()
{
	std::uniform_int_distribution<> dist(0 , 4); // 0 ~ 4
	int randomNum = dist(gen); 

	// 20%
	if ( randomNum == 4 )
	{
		// return Item;
	}


	return nullptr;
}

int MonsterManager::DropGold()
{
	return 0;
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
