#ifndef CALCULATOR_H_
#define CALCULATOR_H_

class Calculator
{
public:
	static int GetCharacterHealth(int characterlevel);
	static int GetMonsterHealth(int characterlevel);
	static bool HasDroppedItem(float probability);
	static int GetItemSalePrice(int price);

private:
	constexpr static float salePriceRatio = 0.6f;
};

#endif