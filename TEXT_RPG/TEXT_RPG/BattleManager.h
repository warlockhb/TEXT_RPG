#ifndef BATTLE_MANAGER_H_
#define BATTLE_MANAGER_H_

#include "Monster.h"
#include "MonsterManager.h"

class BattleManager
{
public:
	BattleManager();
	~BattleManager();
	void StartBattle();
private:
	void AttackCharacter(Monster& Monster);
	void AttackMonster(Monster& Monster);
	void AutoBattle();
	void ManualBattle();
	void EndBattle(bool IsPlayerWin);
	bool IsDead(int Health);

	MonsterManager* _MonsterManager;
	Monster* _Monster;
	
	bool IsBattleEnd;
};

#endif