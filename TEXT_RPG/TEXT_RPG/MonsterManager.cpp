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
	int randomNum = dist(gen);

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

	// Create NormalMonster
	int hp = Character::GetInstance()->GetLevel() * 100;
	int power = Character::GetInstance()->GetLevel() * 10;

	monster = new NormalMonster(monsterName, hp , power);

	return monster;
}

Monster* MonsterManager::CreateBossMonster()
{
	if (monster != nullptr)
		return monster;

	// 異붽���옉�뾽.
	string monsterName = "Boss Monster";
	int hp = 10 * 500;
	int power = 10 *20;

	monster = new BossMonster(monsterName, hp , power);

	return monster;
}

void MonsterManager::DeleteMonster(Monster* _monster, bool _isSuccessful)
{
	if (_monster == nullptr)
		return;

	if ( _isSuccessful )
		HuntComplete(_monster);
	else
		HuntFailed();

	delete _monster;
	_monster = nullptr;
}

void MonsterManager::HuntComplete(Monster* _monster)
{
	// Item Drop
	Item* item = DropItem();

	if ( item != nullptr )
	{
		// Item을 Inventory에 넣어주기
	}

	// Drop Gold
	int gold = DropGold();
	Character::GetInstance()->SetPlusGold(gold);

	// monster Recording
	Logger::GetInstance().RecordMonsterDefeated(_monster->GetName());
}

void MonsterManager::HuntFailed()
{
	// 사냥 실패
}

Item* MonsterManager::DropItem()
{
	std::uniform_int_distribution<> dist(0 , 4); // 0 ~ 4
	int randomNum = dist(gen); 

	// 20%
	if ( randomNum == 4 )
	{
		// Random.
		// return Item;
	}


	return nullptr;
}

int MonsterManager::DropGold()
{
	std::uniform_int_distribution<> dist(1 , 5); // 0 ~ 4
	int randomNum = dist(gen);
	int gold = Character::GetInstance()->GetLevel() * randomNum;

	return gold;
}