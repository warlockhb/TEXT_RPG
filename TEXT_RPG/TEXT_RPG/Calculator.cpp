#include "Calculator.h"
#include <cstdlib>
#include <cmath>

using namespace std;

int Calculator::GetCharacterHealth(int characterlevel)
{
	//Do Something
	int health = characterlevel * 100;

	return health;
}

int Calculator::GetMonsterHealth(int characterlevel)
{
	//Do Something
	int health = characterlevel * 100;

	return health;
}

bool Calculator::HasDroppedItem(float probability)
{
	//Do Something
	bool result = rand() % 1000 + 1 >= probability * 1000;

	return result;
}

int Calculator::GetItemSalePrice(int price)
{
	//Do Something
	int salePrice = floor(price * salePriceRatio);

	return salePrice;
}