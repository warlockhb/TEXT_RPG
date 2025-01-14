#pragma once
#include <map>
#include <vector>
#include "Item/PassiveItem/PassiveItem.h"
#include "Character.h"
using namespace std;


struct Stat
{
	int Level = 0;
	int Health = 0;
	int MaxHealth = 0;
	int Attack = 0;
	int Exp = 0;
	int MaxExp = 0;
	int Gold = 0;
};


class PassiveItem;
class Character;

class Inventory
{
private:

	// 멤버 변수
	Character* Owner;

	size_t Max_Inventory_size = 7;
	vector<PassiveItem*> ItemsInventory;

	Stat TotalStat;
	
	// 멤버 메서드
	void Update();


public:
	Inventory(Character* Ower) : Owner(Ower), ItemsInventory(Max_Inventory_size) {}
	~Inventory();
	
	void DisplayInventory();
	
	void AddItem(PassiveItem* item);
	void RemoveItem(PassiveItem* item);
	void RemoveItem(int index);

	PassiveItem* GetItem(int index);

	//TODO: 스테이지 클리어 마다 외부에서 호출 바람
	void UpdateStage();

	//TODO: 디스플레이 함수 구현 해야함.
	void DisplayItemStat(int index);
};