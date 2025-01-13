#pragma once
#include "PassiveItem.h"

class PotionHPSmal: public PassiveItem
{
public:
    PotionHPSmal()
    {
        ID = ID_POTION_HP_SMALL;
        Name = "소형 포션";
        Price = 30;
        StatModifier.HpMod = 10;
        Description = "체력을" + to_string(StatModifier.HpMod) + "회복시켜준다.";
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
        StatModifier.HpMod = 20;
        Description = "체력을" + to_string(StatModifier.HpMod) + "회복시켜준다.";
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
        StatModifier.HpMod = 30;
        Description = "체력을" + to_string(StatModifier.HpMod) + "회복시켜준다.";
    }
};