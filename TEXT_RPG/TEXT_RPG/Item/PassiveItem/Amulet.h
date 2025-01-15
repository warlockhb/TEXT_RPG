#pragma once
#include "PassiveItem.h"

class AmuletOfStrngth : public PassiveItem
{
public:
    AmuletOfStrngth()
    {
        ID = ID_AMULET_OF_STRENGTH;
        Name = "힘의 부적";
        Price = 200;
        StackStat.AttackMod = 2;
        Description = "매 스테이지 마다 스택 1이 쌓이며, 스택 당 공격력 " + to_string(StackStat.AttackMod) + "만큼 증가한다.";
    }
};

class AmuletOfWisdom : public PassiveItem
{
public:
    AmuletOfWisdom()
    {
        ID = ID_AMULET_OF_WISDOM;
        Name = "지혜의 부적";
        Price = 200;
        EveryTurnStat.ExpMod = 10;
        Description = "매 스테이지 마다 경험치" + to_string(EveryTurnStat.ExpMod) + "만큼 얻는다.";
    }
};

class AmuletOfVitality : public PassiveItem
{
public:
    AmuletOfVitality()
    {
        ID = ID_AMULET_OF_VITALITY;
        Name = "생명력의 부적";
        Price = 300;
        EveryTurnStat.MaxHpMult = 0.01f;
        Description = "매 스테이지 마다 최대 체력 " + to_string(EveryTurnStat.MaxHpMult) + "% 만큼 영구히 증가한다.";
    }
};

class AmuletOfFortune : public PassiveItem
{
public:
    AmuletOfFortune()
    {
        ID = ID_AMULET_OF_FORTUNE;
        Name = "행운의 부적";
        Price = 200;
        EveryTurnStat.GoldMod = 10;
        Description = "매 스테이지 마다 골드" + to_string(EveryTurnStat.GoldMod) + "만큼 얻는다.";
    }
};
