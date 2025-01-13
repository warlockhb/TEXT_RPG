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
	string Name;	
	int Level;		
	int Health;		
	int MaxHealth;	
	int Attack;		
	int Exp;
	int MaxExp;
	int Gold;
	
	//인벤토리
	vector<PassiveItem*> Inventory;
	size_t Max_Inventory_Size = 7;
	//장비칸
	vector<Equipment*> Equipment_Inventory;
	const size_t Max_Skill_Size = 5;

	Character(string New_name);

	Character(const Chracter&) = delete;
	Character& operator = (const Character&) = delete;

public:
	//싱글톤 생성
	static Character* GetInstance(string name = "");

	void DisPlayStatus();

	void LevelUp();

	void UseItem(int index);

	void AddItem(PassiveItem* item);

	void RemoveItem(PassiveItem* item);

	void SkillUse(int index);

	void AddSkill(Equipment* skill);

	void RemoveSkill(Equipment* skill);

	void ByeInventory(int buycount);

	int Getgold();

	void MinusGold(int buymoney);

	void PlusGold(int sellmoney);

	void SetExp(int plusexp);

	void GetAttack();

	void GetHealth();
};

