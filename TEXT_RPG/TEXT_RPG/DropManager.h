#pragma once
#include "Item/Item.h"
#include <vector>
#include <iostream>
#include <random>


class DropManager
{
private:
	vector<Item*> _Items;
	vector<int> _Probability;
	std::mt19937 gen;		// random engine
	int _TotalProbability;
public:
	DropManager();
	~DropManager();

	Item* DropItem();
	int DropGold();
};

