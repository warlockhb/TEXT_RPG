#pragma once
#include "PassiveItem.h"

class AmuletOfStrngth : PassiveItem
{
public:
    AmuletOfStrngth()
    {
        ID = ID_AMULET_OF_STRENGTH;
        Name = "힘의 부적";
        Price = 200;
        StatModifier.MaxHpMod;
        Description = "체력을" + to_string(StatModifier.HpMod) + "회복시켜준다.";
    }
};
