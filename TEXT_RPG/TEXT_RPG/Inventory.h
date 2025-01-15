#pragma once
#include <map>
#include <vector>
#include "Item/PassiveItem/PassiveItem.h"
#include "Character.h"
#include "Stat.h"

using namespace std;



class PassiveItem;
class Character;

class Inventory
{
private:

	// 멤버 변수
	Character* Owner;

	size_t Max_Inventory_size = 7;
	vector<PassiveItem*> ItemsInventory;

	Stat TotalStaticStat;
	Stat TotalEveryTurnStat;
	Stat TotalStackStat;
	
	// 멤버 메서드
	void UpdateStaticStat();
	void UpdateEveryTurnStat();
	void UpdateStackStat();


public:
	Inventory(Character* Ower) : Owner(Ower), ItemsInventory(Max_Inventory_size) {}
	~Inventory();

	void Apply();
	
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