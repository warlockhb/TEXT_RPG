#ifndef BATTLE_MANAGER_H_
#define BATTLE_MANAGER_H_

#include "Monster.h"
#include "MonsterManager.h"

enum EBattleState
{
	EBS_NONE = 0,
	EBS_INPROGRESS = 1,
	EBS_PLAYER_WIN = 2,
	EBS_PLAYER_LOSE = 3,
};

class BattleManager
{
public:
	BattleManager();
	~BattleManager();
	void StartBattle();

	EBattleState GetBattleState() const;
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
	EBattleState _BattleState;
};

#endif