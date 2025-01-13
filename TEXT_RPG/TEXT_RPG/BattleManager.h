#ifndef BATTLE_MANAGER_H_
#define BATTLE_MANAGER_H_

#include "Monster.h"
#include "Character.h"


class BattleManager
{
public:
	BattleManager();

	void Battle();
	void AttackEachOther(Character* character, Monster* monster, int turn);

private:

};

#endif