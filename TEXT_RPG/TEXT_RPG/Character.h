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
	static Character * instance;

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
	//싱글톤
	static Character * GetInstance(string name = "");

	//플레이어 스테이트 보여주기
	void DisPlayStatus();

	void LevelUp();

	void UseItem(int index);

	void AddItem(PassiveItem* item);

	void RemoveItem(PassiveItem* item);

	void SkillUse(int index);

	void AddSkill(Equipment* skill);

	void RemoveSkill(Equipment* skill);

	void ByeInventory(int buycount);

	void MinusGold(int buymoney);

	void PlusGold(int sellmoney);

	//Get
	int GetAttack();
	int GetHealth();
	int Getgold();

	//Set
	void SetExp(int plusexp);
};

