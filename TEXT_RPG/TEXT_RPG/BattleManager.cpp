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
	bool CanAttackFirst = rand() % 2 == 0;
	int TurnCount = 1;

	if (CanAttackFirst)
	{
		cout << "ĳ���� ���� ����" << endl;
	}
	else
	{
		cout << "���� ���� ����" << endl;
	}

	//Monster* _Monster = MonsterManager::CreateMonster();

	while (true)
	{

	}
}

void BattleManager::AttackCharacter(Monster* Monster)
{

}

void BattleManager::AttackMonster(Monster* Monster)
{

}




