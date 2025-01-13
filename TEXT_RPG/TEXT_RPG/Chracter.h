#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PassiveItem;


class Chracter
{
private:
	//½Ì±ÛÅæ
	static Chracter* instance;

	//¼öÄ¡ ÆÄ¶ó¹ÌÅÍ
	string name;	
	int level;		
	int health;		
	int maxhealth;	
	int attack;		
	int exp;
	int maxExp;
	int gold;
	
	//ÀÎº¥Åä¸®
	vector<PassiveItem*> inventory;
	const size_t max_inventory_size = 7;
	//ÀåºñÄ­


	Chracter(string Name);

	Chracter(const Chracter&) = delete;
	Chracter& operator = (const Character&) = delete;

public:
	//½Ì±ÛÅæ »ý¼º
	static Chracter* getInstance(string name = "");

	void displayStatus();

	void levelUp();

	void useItem(int index);

	void addItem(PassiveItem* item);

	void removeItem(PassiveItem* item);

	void byeInventory(int buycount);

	int getgold() const;
	void setgold(int dealmoney);

	void setexp(int plusexp);


};

