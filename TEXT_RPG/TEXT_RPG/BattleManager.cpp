#include "BattleManager.h"
#include <cstdlib>

using namespace std;

BattleManager::BattleManager()
{
}

void BattleManager::Battle()
{
	bool CanAttackFirst = rand() % 2 == 0;
	int TurnCount = 1;

	if (CanAttackFirst)
	{
		cout << "캐릭터 선제 공격" << endl;
	}
	else
	{
		cout << "몬스터 선제 공격" << endl;
	}
}

void BattleManager::AttackEachOther(Character* character, Monster* monster, int turn)
{
	
}
