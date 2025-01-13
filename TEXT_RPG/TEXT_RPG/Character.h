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
<<<<<<< HEAD
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
=======
	//�̱���
	static Character* instance;

	//��ġ �Ķ����
	string name;	
	int level;		
	int health;		
	int maxhealth;	
	int attack;		
	int exp;
	int maxExp;
	int gold;
	
	//�κ��丮
	vector<PassiveItem*> inventory;
	size_t max_inventory_size = 7;
	//���ĭ
	vector<Equipment*> equipment_inventory;
	const size_t max_skill_size = 5;
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec

	Character(string New_name);

	Character(const Chracter&) = delete;
	Character& operator = (const Character&) = delete;

public:
<<<<<<< HEAD
	//싱글톤 생성
	static Character* GetInstance(string name = "");
=======
	//�̱��� ����
	static Character* getInstance(string name = "");
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec

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

