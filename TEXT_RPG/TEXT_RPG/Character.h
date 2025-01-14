#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item//Item.h"
using namespace std;


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
	//vector<PassiveItem*> Inventory;
	//size_t Max_Inventory_Size = 7;
	//장비칸
	//vector<Equipment*> Equipment_Inventory;
	//const size_t Max_Skill_Size = 5;

	Character(string New_name);

	Character(const Character&) = delete;
	Character& operator = (const Character&) = delete;

public:
	//싱글톤
	static Character * GetInstance(string New_name = "");

	//플레이어스테이트보여주기
	void DisplayStatus();

	//캐릭터레벨업
	void LevelUp();

	//아이템사용&추가&제거
	//void UseItem(int index);
	//void AddItem(PassiveItem* item);
	//void RemoveItem(PassiveItem* item);

	//스킬사용&추가&제거
	//void SkillUse(int index);
	//void AddSkill(Equipment* skill);
	//void RemoveSkill(Equipment* skill);


	//인벤토리 추가
	//void ByeInventory(int buycount);

	//플레이어 사망
	void Die();

	//Get
	int GetAttack();
	int GetHealth();
	int Getgold();
	string GetName();
	int GetLevel();
	int GetMaxHealth();


	//Set
	//exp추가
	void SetExp(int plusexp);
	//골드추가&제거
	void SetMinusGold(int buymoney);
	void SetPlusGold(int sellmoney);
	//hp추가&제거
	void SetMinusHp(int minushp);
	void SetPlusHp(int plushp);
	//attack추가&제거
	void SetMinusAttack(int minusatk);
	void SetPlusAttack(int plusatk);

	
// Set functions implementation
// Set new attack value
void SetAttack(int newAttack) {
	Attack = newAttack < 0 ? 0 : newAttack;
}

// Set new health value
void SetHealth(int newHealth) {
	Health = (newHealth < 0 ? 0 : newHealth > MaxHealth ? MaxHealth : newHealth);
}

// Set new maximum health value
void SetMaxHealth(int newMaxHealth) {
	MaxHealth = newMaxHealth < 0 ? 0 : newMaxHealth;
	if (Health > newMaxHealth) {
		Health = newMaxHealth;
	}
}

// Set new gold value
void SetGold(int newGold) {
	Gold = newGold < 0 ? 0 : newGold;
}

// Set new experience value
void SetExpDirectly(int newExp) {
	Exp = newExp < 0 ? 0 : newExp;
}

// Set new maximum experience value
void SetMaxExp(int newMaxExp) {
	MaxExp = newMaxExp < 0 ? 0 : newMaxExp;
}

// Set new character name
void SetName(const string& newName) {
	Name = newName;
}

// Set character level directly
void SetLevel(int newLevel) {
	Level = newLevel < 0 ? 0 : newLevel;
}
	
};

