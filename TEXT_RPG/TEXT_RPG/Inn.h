#pragma once
#include "Character.h"


class Inn {
public:
	const int INN_COST = 10;

	void EnterInn(Character& character);
	void UseInn(Character& character);
};