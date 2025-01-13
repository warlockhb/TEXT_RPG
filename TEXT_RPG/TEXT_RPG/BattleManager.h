#ifndef BATTLE_MANAGER_H_
#define BATTLE_MANAGER_H_

#include "Monster.h"
#include "Character.h"


class BattleManager
{
public:
	BattleManager();

	void StartBattle();
	void AttackCharacter(Character* character, Monster* monster);
	void AttackMonster(Character* character, Monster* monster);

private:

};

#endif