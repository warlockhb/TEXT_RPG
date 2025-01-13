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
	//싱글톤
	static Character* instance;

	//수치 파라미터
	string name;
	int level;
	int health;
	int maxhealth;
	int attack;
	int exp;
	int maxExp;
	int gold;

	//인벤토리
	vector<PassiveItem*> inventory;
	size_t max_inventory_size = 7;
	//장비칸
	vector<Equipment*> equipment_inventory;
	const size_t max_skill_size = 5;

	Character(string Name);

	Character(const Character&) = delete;
	Character& operator = (const Character&) = delete;

public:
	//싱글톤 생성
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

