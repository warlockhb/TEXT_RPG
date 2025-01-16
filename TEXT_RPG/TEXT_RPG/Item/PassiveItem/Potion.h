#pragma once
#include "PassiveItem.h"

class PotionHPSmall: public PassiveItem
{
public:
    PotionHPSmall()
    {
        ID = ID_POTION_HP_SMALL;
        Name = "소형 포션";
        Price = 100;
        EveryTurnStat.HpMod = 100;
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
        Price = 300;
        EveryTurnStat.HpMod = 250;
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
        Price = 1500;
        EveryTurnStat.HpMult = 0.1f;
        EveryTurnStat.HpMod = 200;
        Description = "매 스테이지 마다 체력 "+to_string(EveryTurnStat.HpMod)+"와 최대 체력의 " + to_string(EveryTurnStat.HpMult * 100) + "% 을 회복시켜준다.";
    }
};