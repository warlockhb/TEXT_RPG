#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PassiveItem;
class Equipment;

class Character
{
private:
	//½Ì±ÛÅæ
	static Character* instance;

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
	size_t max_inventory_size = 7;
	//ÀåºñÄ­
	vector<Equipment*> equipment_inventory;
	const size_t max_skill_size = 5;

	Character(string Name);

	Character(const Chracter&) = delete;
	Character& operator = (const Character&) = delete;

public:
	//½Ì±ÛÅæ »ý¼º
	static Character* getInstance(string name = "");

	void displayStatus();

	void levelUp();

	void useItem(int index);

	void addItem(PassiveItem* item);

	void removeItem(PassiveItem* item);

	void skilluse(int index);

	void addskill(Equipment* skill);

	void removeskill(Equipment* skill);

	void byeInventory(int buycount);

	int getgold() const;

	void minusgold(int buymoney);

	void plusgold(int sellmoney);

	void setexp(int plusexp);
};

