#pragma once
#include <map>
#include "Character.h"
#include "./Item/PassiveItem/Potion.h"
#include "./Item/PassiveItem/Amulet.h"
#include "./Item/PassiveItem/PassiveItem.h"
#include "./Item/Equipment/Equipment.h"


class Shop {
private:
	//items : 아이템 저장할 곳
	std::map<int, PassiveItem*> amulets;
	std::map<int, PassiveItem*> potions;
	
	std::map<int, Equipment*> armors;
	std::map<int, Equipment*> boots;
	std::map<int, Equipment*> guards;
	std::map<int, Equipment*> heads;
	std::map<int, Equipment*> weapons;

	
public:
	Shop();
	~Shop();
	void EnterShop(Character& character);

	//PassiveItem용
	void ShowItems(const std::map<int, PassiveItem*>& map_item);
	void BuyLogic(Character& character, const std::map<int, PassiveItem*>& map_item);
	//Equipment용
	void ShowItems(const std::map<int, Equipment*>& map_item);
	void BuyLogic(Character& character, const std::map<int, Equipment*>& map_item);
	
	void BuyItem(Character& character);
	void SellItem(Character& character);
};