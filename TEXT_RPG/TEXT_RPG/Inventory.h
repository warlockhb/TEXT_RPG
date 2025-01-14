#pragma once
#include <vector>
using namespace std;

struct Stat
{
	int Level;
	int Health;
	int MaxHealth;
	int Attack;
	int Exp;
	int MaxExp;
	int Gold;
};

class PassiveItem;

class Inventory
{
private:
	vector< PassiveItem*> ItemsInventory;
	size_t Max_Inventory_size = 7;
	Stat ItemStats;

public:
	Inventory();
};