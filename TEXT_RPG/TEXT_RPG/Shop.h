#pragma once
#include "Character.h"
//#include "Item.h"


class Shop {
public:
	void EnterShop(Character& character);
	//void ShowItems(Item& item);//re
	void BuyItem(Character& character);
	void SellItem(Character& character);
};