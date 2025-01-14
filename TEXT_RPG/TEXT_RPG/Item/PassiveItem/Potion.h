#pragma once
#include "PassiveItem.h"

class PotionHPSmall: public PassiveItem
{
public:
    PotionHPSmall()
    {
        ID = ID_POTION_HP_SMALL;
        Name = "소형 포션";
        Price = 30;
        Description = "체력을 회복시켜준다.";
        DynamicStat.HpMod = 20;
    }
};


class PotionHpMedium: public PassiveItem
{
public:
    PotionHpMedium()
    {
        ID = ID_POTION_HP_MEDIUM;
        Name = "중형 포션";
        Price = 70;
        Description = "체력을 회복시켜준다.";
    }
};

class PotionHpLarge: public PassiveItem
{
public:
    PotionHpLarge()
    {
        ID = ID_POTION_HP_LARGE;
        Name = "대형 포션";
        Price = 120;
        Description = "체력을 회복시켜준다.";
    }
};