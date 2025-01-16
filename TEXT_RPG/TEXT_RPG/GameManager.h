#pragma once
#include "Character.h"
#include "BattleManager.h"
#include "Village.h"
class GameManager
{
public:
	void StartGame();
	void GenerateCharacter();
	bool ShowMenu();
private:
	Character* MyCharacter = nullptr;
	BattleManager* battleManager = new BattleManager();
	Village village;
};

