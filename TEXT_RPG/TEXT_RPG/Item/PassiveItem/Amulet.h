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
        EveryTurnStat.HpMod = 10;
        Description = "체력을" + to_string(EveryTurnStat.HpMod) + "회복시켜준다.";
    }
};
