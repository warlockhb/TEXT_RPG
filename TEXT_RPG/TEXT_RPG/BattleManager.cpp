#include "BattleManager.h"
#include "MonsterManager.h"
#include "Character.h"
#include <cstdlib>

using namespace std;

BattleManager::BattleManager()
{
}

void BattleManager::StartBattle()
{
	//Todo : 자동공격 & 수동공격
	cout << "1. 자동 전투 ___ 2. 수동 전투" << endl;
	int BattleType = 0;
	cin >> BattleType;
	cout << endl;

	switch (BattleType)
	{
	case 1:
		cout << "자동전투" << endl;
		AutoBattle();
		break;
	case 2:
		cout << "수동전투인데 구현 안됐으니 자동전투하세요." << endl;
		ManualBattle();
		break;
	default:
		cout << "그냥 자동전투하세요.";
		break;
	}
}

void BattleManager::AttackCharacter(Monster* Monster)
{
	cout << "---- 몬스터가 플레이어를 공격합니다.----" << endl;
	cout << "---- 데미지 : "<< Monster->GetPower() << "----" << endl;
	
	
}

void BattleManager::AttackMonster(Monster* Monster)
{
	cout << "---- ----" << endl; 

}

void BattleManager::AutoBattle()
{
	MonsterManager* _MonsterManager = new MonsterManager();

	Monster* Monster = _MonsterManager->CreateNormalMonster();

	int TurnCount = 0;
	while (true)
	{
		if (TurnCount % 2 == 0)
		{
			AttackMonster(Monster);
		}
		else
		{
			AttackCharacter(Monster);
		}
	}
}

void BattleManager::ManualBattle()
{

}

void BattleManager::EndBattle()
{
}



