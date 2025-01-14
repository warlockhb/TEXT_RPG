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

		if (IsDead(TempHealth))
		{
			EndBattle();
			break;
		}
		
		TurnCount++;
	}
}

void BattleManager::AttackCharacter(Monster* Monster)
{
	cout << "---- 몬스터가 플레이어를 공격합니다.----" << endl;
	int Damage = Monster->GetPower();
	cout << "---- 데미지 : "<<  Damage << " ----" << endl;
	Character::GetInstance()->SetMinusHp(Damage);
	TempHealth = Character::GetInstance()->GetHealth();
	cout << "캐릭터 남은 체력 : " << TempHealth << endl;
}

void BattleManager::AttackMonster(Monster* Monster)
{
	cout << "---- 플레이어가 몬스터를 공격합니다.----" << endl; 
	int Damage = Character::GetInstance()->GetAttack();
	cout <<"---- 데미지 : " <<  Damage << " ----" << endl;
	Monster->TakeDamage(Damage);
	TempHealth = Monster->GetHp();
	cout <<"몬스터 남은 체력 : " << TempHealth << endl;
}

void BattleManager::ManualBattle()
{
	
}

void BattleManager::EndBattle()
{
	cout << "---- 전투 종료 ----" << endl;
}

bool BattleManager::IsDead(int Health)
{
	return Health <= 0;
}



