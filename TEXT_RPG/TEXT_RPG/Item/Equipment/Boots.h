#pragma once
#include "Equipment.h"

class FootLeatherBoots : public Equipment
{
public:
    FootLeatherBoots()
    {
        SlotType = FOOT;
        ID = ID_FOOT_LEATHER_BOOTS;
        Name = "가죽 부츠";
        Price = 80;
        StaticStat.MaxHpMod = 15;
        Description = "최대 체력 " + to_string(StaticStat.MaxHpMod) + " 을 얻는다.";
    }
};


class FootIronBoots : public Equipment
{
public:
    FootIronBoots()
    {
        SlotType = FOOT;
        ID = ID_FOOT_IRON_BOOTS;
        Name = "철 부츠";
        Price = 150;
        StaticStat.MaxHpMod = 25;
        Description = "최대 체력 " + to_string(StaticStat.MaxHpMod) + " 을 얻는다.";
    }
};

class FootSwiftBoots : public Equipment
{
public:
    FootSwiftBoots()
    {
        SlotType = FOOT;
        ID = ID_FOOT_SWIFT_BOOTS;
        Name = "신속의 부츠";
        Price = 300;
        StaticStat.MaxHpMult = -0.1f;
        EveryTurnStat.ExpMod = 100;
        Description = "기본 최대 체력을 "+ to_string(StaticStat.MaxHpMod) + "% 잃고, 매 스테이지 마다 " + to_string(EveryTurnStat.ExpMod) + " 을 얻는다.";
    }
};

class FootDragonBoots : public Equipment
{
public:
    FootDragonBoots()
    {
        SlotType = FOOT;
        ID = ID_FOOT_DRAGON_BOOTS;
        Name = "드래곤 부츠";
        Price = 600;
        StaticStat.MaxHpMult = 0.2f;
        Description = "기본 최대 체력을 "+ to_string(StaticStat.MaxHpMod) + "% 얻는다.";
    }
};