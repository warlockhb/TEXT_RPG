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
		cout << "ĳ���� ���� ����" << endl;
	}
	else
	{
		cout << "���� ���� ����" << endl;
	}
}

void BattleManager::AttackEachOther(Character* character, Monster* monster, int turn)
{
	
}
