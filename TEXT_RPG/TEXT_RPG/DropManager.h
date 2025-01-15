#pragma once
#include "Item/Item.h"
#include <vector>
#include <iostream>
#include <random>


class DropManager
{
private:
	vector<Item*> _Items;
	vector<float> _Probability;
	std::mt19937 gen;		// random engine

public:
	DropManager();
	~DropManager();

	Item* DropItem();
	int DropGold();
};

