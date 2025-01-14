#pragma once
#include "Character.h"
//#include "Item.h"


class Shop {

public:
	void EnterShop(Character& character);
	void ShowItems(int choice);
	void BuyItem();
	void SellItem();
};