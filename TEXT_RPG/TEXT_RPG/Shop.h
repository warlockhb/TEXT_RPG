#pragma once
#include <map>
#include "Character.h"
#include "./Item/PassiveItem/Potion.h"
#include "./Item/PassiveItem/Amulet.h"
#include "./Item/PassiveItem/PassiveItem.h"


class Shop {
private:
	//items : 아이템 저장할 곳
	std::map<int, PassiveItem*> amulets;
	std::map<int, PassiveItem*> potions;
public:
	Shop();
	~Shop();
	void EnterShop(Character& character);
	void ShowItems(const std::map<int, PassiveItem*>& map_item);
	void BuyLogic(Character& character, const std::map<int, PassiveItem*>& map_item);
	void BuyItem(Character& character);
	void SellItem(Character& character);
};