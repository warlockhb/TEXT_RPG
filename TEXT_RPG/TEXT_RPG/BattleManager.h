#ifndef BATTLE_MANAGER_H_
#define BATTLE_MANAGER_H_

#include "Monster.h"
#include "Character.h"

class BattleManager
{
public:
	BattleManager();

	void StartBattle();
private:
	void AttackCharacter(Monster& monster);
	void AttackMonster(Monster& monster);
	void AutoBattle();
	void ManualBattle();
	void EndBattle();
	bool IsDead(int Health);
	int TempHealth;
};

#endif