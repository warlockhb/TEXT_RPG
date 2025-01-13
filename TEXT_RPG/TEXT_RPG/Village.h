#pragma once
#include "Inn.h"
#include "Shop.h"
#include "Character.h"

class Village {
private:
	Inn inn;
	Shop shop;
public:
	Village();
	void ShowChoice(Character& character);
};