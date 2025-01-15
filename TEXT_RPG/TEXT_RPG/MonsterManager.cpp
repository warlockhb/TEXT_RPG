#include "MonsterManager.h"
#include "Logger.h"
#include "Calculator.h"
#include "BossMonster.h"
#include "NormalMonster.h"
#include "Character.h"

MonsterManager::MonsterManager()
	: _Monster(nullptr)
	, gen(std::random_device{}( ))
	, _DropManager(new DropManager())
{
}

MonsterManager::~MonsterManager()
{
	if ( _Monster != nullptr )
	{
		delete _Monster;
		_Monster = nullptr;
	}

	delete _DropManager;
	_DropManager = nullptr;
}

Monster* MonsterManager::CreateNormalMonster()
{
	if (_Monster != nullptr)
		return _Monster;

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

	_Monster = new NormalMonster(monsterName, hp , power);

	return _Monster;
}

Monster* MonsterManager::CreateBossMonster()
{
	if (_Monster != nullptr)
		return _Monster;

	// Create BosslMonster.
	string monsterName = "Boss Monster";
	int hp = 10 * 500;
	int power = 10 *20;

	_Monster = new BossMonster(monsterName, hp , power);

	return _Monster;
}

void MonsterManager::DeleteMonster(Monster* _monster, bool _isSuccessful)
{
	if (_monster == nullptr)
		return;

	NormalMonster* normalMonster = dynamic_cast<NormalMonster*>( _monster );
	if ( normalMonster != nullptr )
	{
		if ( _isSuccessful )
			HuntComplete(_monster);
		else
			HuntFailed();
	}
	
	BossMonster* bossMonster = dynamic_cast<BossMonster*>( _monster );
	if ( bossMonster != nullptr )
	{
		if ( _isSuccessful )
			HuntComplete(_monster);
		else
			HuntFailed();
	}
	
	delete _monster;
	_monster = nullptr;
}

void MonsterManager::HuntComplete(Monster* _monster)
{
	// Item Drop
	Item* item = _DropManager->DropItem();

	if ( item != nullptr )
	{
		// Item을 Inventory에 넣어주기
	}

	// Drop Gold
	int gold = _DropManager->DropGold();
	Character::GetInstance()->AddGold(gold);

	// monster Recording
	Logger::GetInstance().RecordMonsterDefeated(_monster->GetName());
}

void MonsterManager::HuntFailed()
{
	// 사냥 실패
}

