#pragma once
#include "Character.h"
#include "BattleManager.h"
class GameManager
{
public:
	void StartGame();
	void GenerateCharacter();
	bool ShowMenu();
private:
	Character* MyCharacter = nullptr;
	BattleManager* battleManager = new BattleManager();
};

