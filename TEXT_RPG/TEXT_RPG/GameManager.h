#pragma once
#include "Character.h"

class GameManager
{
public:
	void StartGame();
	void GenerateCharacter();
	void ShowMenu();
private:
	Character* MyCharacter = nullptr;
};

