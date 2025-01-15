#pragma once
#include "Item/Item.h"
#include <vector>
#include <iostream>

class DropManager
{
private:
	vector<Item*> items;

	DropManager();
	~DropManager();

public:
	DropManager(const DropManager&) = delete;
	DropManager* operator= (const DropManager) = delete;

	


};

