#ifndef BATTLE_MANAGER_H_
#define BATTLE_MANAGER_H_

#include "Monster.h"
#include "Character.h"

class BattleManager
{
public:
	BattleManager();

	void StartBattle();
	void AttackCharacter(Monster* monster);
	void AttackMonster(Monster* monster);

private:

};

#endif