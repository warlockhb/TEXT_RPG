#include "MonsterManager.h"
#include "Logger.h"
#include "Calculator.h"
#include "BossMonster.h"
#include "NormalMonster.h"
#include "Character.h"
#include "./Item/Equipment/Equipment.h"
#include "./Item/PassiveItem/PassiveItem.h"
#include "Inventory.h"
#include "EquipmentSlot.h"
#include <cmath>


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
	std::uniform_int_distribution<> dist1(20 , 30); 
	int randomHp = dist1(gen);

	std::uniform_int_distribution<> dist2(5 , 10); 
	int randomAtk = dist2(gen);

	int playerLv = Character::GetInstance()->GetLevel();
	int ratio = pow(playerLv , 1.2);

	int hp = randomNum * ratio;
	int power = randomAtk * ratio;

	_Monster = new NormalMonster(monsterName, hp , power);
	cout << monsterName << " 등장!!" << endl;

	return _Monster;
}

Monster* MonsterManager::CreateBossMonster()
{
	if (_Monster != nullptr)
		return _Monster;

	// Create BosslMonster.
	string monsterName = "Boss Monster";
	int hp = 10 * 300;
	int power = 10 *10;

	_Monster = new BossMonster(monsterName, hp , power);
	cout << monsterName << " 등장!!" << endl;

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
			HuntFailed(_monster);
	}
	
	BossMonster* bossMonster = dynamic_cast<BossMonster*>( _monster );
	if ( bossMonster != nullptr )
	{
		if ( _isSuccessful )
			HuntComplete(_monster);
		else
			HuntFailed(_monster);
	}
	
	delete _Monster;
	_Monster = nullptr;
}

void MonsterManager::HuntComplete(Monster* _monster)
{
	// Item Drop
	Item* item = _DropManager->DropItem();
	
	PassiveItem* passiveitem = dynamic_cast<PassiveItem*>(item);
	if ( passiveitem != nullptr )
	{
		cout << _monster->GetName() << "이(가) " << passiveitem->GetName() << "을(를) 드랍했습니다!" << endl;

		PassiveItem* refPassiveItem = new PassiveItem(*passiveitem);
		Character::GetInstance()->GetInventory()->AddItem(refPassiveItem);
	}
	Equipment* equipment = dynamic_cast<Equipment*>( item );
	if ( equipment != nullptr )
	{
		cout << _monster->GetName() << "이(가) " << equipment->GetName() << "을(를) 드랍했습니다!" << endl;

		Equipment* refEquipment = new Equipment(*equipment);
		Character::GetInstance()->GetEquipmentSlot()->AddItem(refEquipment);
	}

	// Drop Gold
	int gold = _DropManager->DropGold();
	cout << _monster->GetName() << "이(가) " << gold << "gold를 드랍했습니다" << endl;
	Character::GetInstance()->AddGold(gold);
	Logger::GetInstance().AddGold(gold);

	// monster Recording
	Logger::GetInstance().RecordMonsterDefeated(_monster->GetName());
}

void MonsterManager::HuntFailed(Monster* _monster)
{
	// 사냥 실패
	cout << _monster->GetName() << " 사냥에 실패하였습니다.."<< endl;
}

