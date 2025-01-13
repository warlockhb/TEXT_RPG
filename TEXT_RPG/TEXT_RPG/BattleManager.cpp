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
	//Todo : �ڵ����� & ��������
	cout << "1. �ڵ� ���� ___ 2. ���� ����" << endl;
	int BattleType = 0;
	cin >> BattleType;
	cout << endl;

	switch (BattleType)
	{
	case 1:
		cout << "�ڵ�����" << endl;
		AutoBattle();
		break;
	case 2:
		cout << "���������ε� ���� �ȵ����� �ڵ������ϼ���." << endl;
		ManualBattle();
		break;
	default:
		cout << "�׳� �ڵ������ϼ���.";
		break;
	}

	//bool CanAttackFirst = rand() % 2 == 0;
	//int TurnCount = 1;

	//if (CanAttackFirst)
	//{
	//	cout << "ĳ���� ���� ����" << endl;
	//}
	//else
	//{
	//	cout << "���� ���� ����" << endl;
	//}
}

void BattleManager::AttackCharacter(Monster* Monster)
{
	cout << "---- ���Ͱ� �÷��̾ �����մϴ�.----" << endl;
	cout << "---- ������ : "<< Monster->GetPower() << "----" << endl;
	
	
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




