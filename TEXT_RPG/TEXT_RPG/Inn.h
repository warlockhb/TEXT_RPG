#pragma once
#include "Character.h"


class Inn {
public:
	//re: 여관 이용료 10골드(가정)
	const int cost = 10;

	void EnterInn(Character& character);
	void UseInn(Character& character);
};