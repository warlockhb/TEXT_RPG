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
        EveryTurnStat.HpMod = 10;
        Description = "매 스테이지 마다 체력 " + to_string(EveryTurnStat.HpMod) + " 을 회복시켜준다.";
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
        EveryTurnStat.HpMod = 18;
        Description = "매 스테이지 마다 체력 " + to_string(EveryTurnStat.HpMod) + " 을 회복시켜준다.";
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
        EveryTurnStat.HpMult = 0.05f;
        EveryTurnStat.HpMod = 10;
        Description = "매 스테이지 마다 체력 "+to_string(EveryTurnStat.HpMod)+"와 최대 체력의 " + to_string(EveryTurnStat.HpMult * 100) + "% 을 회복시켜준다.";
    }
};