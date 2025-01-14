#pragma once
#include <map>
#include "Character.h"
#include "./Item/PassiveItem/Potion.h"
#include "./Item/Equipment/Equipment.h"
#include "./Item/PassiveItem/Amulet.h"
#include "./Item/PassiveItem/PassiveItem.h"


class Shop {
private:
	//items : 아이템 저장할 곳
	std::map<int, Item*> potions;
	//작성 예정
	/*std::map<int, Item*> amulets;
	std::map<int, Item*> passiveItems;*/
public:
	Shop();
	~Shop();
	void EnterShop(Character& character);
	void ShowItems(int choice);
	void BuyItem();
	void SellItem();
};