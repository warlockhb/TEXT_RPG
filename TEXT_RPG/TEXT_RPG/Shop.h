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
	std::map<int, Item*> items;
	
public:
	Shop();
	~Shop();
	void EnterShop(Character& character);
	void ShowItems();
	void BuyItem(Character& character);
	void SellItem(Character& character);
};