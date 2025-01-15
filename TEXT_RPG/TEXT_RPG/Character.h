#pragma once
#include <string>
// #include "Inventory.h"
using namespace std;

class Inventory;

class Character
{
private:
	static Character * instance;

	//baseState
	string Name;
	int Level;
	int Health;
	int MaxHealth;
	int Attack;
	int Exp;
	int MaxExp;
	int Gold;

	//currentState
	int CurrentHealth;
	int CurrentMaxHealth;
	int CurrentAttack;

	Inventory* inventory;

	Character(string New_name);

	Character(const Character&) = delete;
	Character& operator = (const Character&) = delete;
public:
	//싱글톤
	static Character * GetInstance(string New_name = "");

	Inventory* GetInventory();

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

	//Get
	string GetName() const;
	int GetLevel() const;
	int GetHealth() const;
	int GetMaxHealth() const;
	int GetAttack() const;
	int GetExp() const;
	int GetGold() const;
	int GetCurrentHealth() const;
	int GetCurrentMaxHealth() const;
	int GetCurrentAttack() const;
	
	//Set
	void SetHealth(int health);
	void SetMaxHealth(int maxhealth);
	void SetAttack(int attack);
	void SetExp(int exp);
	void SetMaxExp(int maxexp);
	void SetGold(int gold);
	void SetCurrentHealth(int health);
	void SetCurrentMaxHealth(int maxhealth);
	void SetCurrentAttack(int atk);


	//기능구현
	//캐릭터 스테이트 보여주기
	void DisPlayStatus();
	//대미지 받음
	void TakeDamage(int damage);
	//회복 관련 이벤트
	void RecoverHealth(int health);
	//완전 회복 이벤트
	void AllRecoverHealth();
	//캐릭터 사망
	void PlayerDie();
	//경험치 증가
	void GainExp(int plusexp);
	//캐릭터 레벨업
	void LevelUp();
	//골드 추가
	void AddGold(int plusgold);
	//골드 감소
	void LoseGold(int minusgold);
};

