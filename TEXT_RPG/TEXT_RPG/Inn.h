#pragma once
#include "Character.h"


class Inn {
public:
	//re: ���� �̿�� 10���(����)
	const int cost = 10;

	void EnterInn(Character& character);
	void UseInn(Character& character);
};