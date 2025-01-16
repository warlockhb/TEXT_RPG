#pragma once
#include <string>
using namespace std;

class Inventory;
class EquipmentSlot;

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
	EquipmentSlot* equipmentSlot;

	Character(string New_name);
	~Character();

	Character(const Character&) = delete;
	Character& operator = (const Character&) = delete;
public:
	//싱글톤
	static Character * GetInstance(string New_name = "");

	Inventory* GetInventory();
	EquipmentSlot* GetEquipmentSlot();
	
	//Get
	//캐릭터의 Base 스텟과 CurrentHealth의 차이점
	//캐릭터가 버프를 받을때 변해야되는 수치때문에 currentHealth를 사용해주시는게 좋습니다.
	string GetName() const; //캐릭터 이름
	int GetLevel() const; //캐릭터 레벨
	int GetHealth() const; //캐릭터 Base 체력
	int GetMaxHealth() const; //캐릭터 Base 최대체력
	int GetAttack() const; //캐릭터 Base 공격력
	int GetExp() const; //캐릭터 경험치
	int GetGold() const; //캐릭터 골드
	int GetCurrentHealth() const; //캐릭터의 현재 체력 -> 이 함수를 사용하시는게 좋습니다.
	int GetCurrentMaxHealth() const; //캐릭터의 현재 최대 체력
	int GetCurrentAttack() const; //캐릭터의 현재 공격력
	
	//Set
	void SetHealth(int health); //캐릭터의 Base체력
	void SetMaxHealth(int maxhealth); //캐릭터의 Base 최대 체력
	void SetAttack(int attack); // 캐릭터의 Base 공격력
	void SetExp(int exp); // 캐릭터의 경험치
	void SetMaxExp(int maxexp); // 캐릭터의 최대 경험치 (딱히 건들일 일은 없는거 같습니다.)
	void SetGold(int gold); // 캐릭터의 골드
	void SetCurrentHealth(int health); // 캐릭터의 현재 체력
	void SetCurrentMaxHealth(int maxhealth); // 캐릭터의 현재 최대 체력
	void SetCurrentAttack(int atk); // 캐릭터의 현재 공격력


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

