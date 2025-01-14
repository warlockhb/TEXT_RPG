#pragma once
#include "Character.h"


class Inn {
public:
	const int cost = 10;

	void EnterInn(Character& character);
	void UseInn(Character& character);
};