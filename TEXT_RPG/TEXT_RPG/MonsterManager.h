#pragma once
#include "Monster.h"
#include "DropManager.h"

using namespace std;

class MonsterManager
{
private:
	Monster* _Monster;
	DropManager* _DropManager;
	std::mt19937 gen;		// random engine


public:
	MonsterManager();
	~MonsterManager();

	Monster* CreateNormalMonster();
	Monster* CreateBossMonster();
	void DeleteMonster(Monster* _monster, bool _isSuccessful);

	void HuntComplete(Monster* _monster);
	void HuntFailed(Monster* _monster);
};