#pragma once
#include "Equipment.h"

class ArmLeatherGuard : public Equipment
{
public:
    ArmLeatherGuard()
    {
        SlotType = ARM;
        ID = ID_ARM_LEATHER_GUARD;
        Name = "가죽 팔목보호대";
        Price = 100;
        StaticStat.AttackMult = 0.05f;
        Description = "기본 공격력의 " + to_string(StaticStat.AttackMult) + "% 얻는다.";
    }
};


class ArmIronGuard : public Equipment
{
public:
    ArmIronGuard()
    {
        SlotType = ARM;
        ID = ID_ARM_IRON_GUARD;
        Name = "철 팔목보호대";
        Price = 250;
        StaticStat.AttackMult = 0.1f;
        Description = "기본 공격력의 " + to_string(StaticStat.AttackMult) + "% 얻는다.";
    }
};

class ArmMithrilGuard : public Equipment
{
public:
    ArmMithrilGuard()
    {
        SlotType = ARM;
        ID = ID_ARM_MITHRIL_GUARD;
        Name = "미스릴 팔목보호대";
        Price = 600;
        StaticStat.AttackMult = 0.25f;
        Description = "기본 공격력의 " + to_string(StaticStat.AttackMult) + "% 얻는다.";
    }
};

class ArmDragonGuard : public Equipment
{
public:
    ArmDragonGuard()
    {
        SlotType = ARM;
        ID = ID_ARM_DRAGON_GUARD;
        Name = "드래곤 팔목보호대";
        Price = 1500;
        StaticStat.AttackMult = 0.25f;
        EveryTurnStat.GoldMod = 20;
        Description = "기본 공격력의 " + to_string(StaticStat.AttackMult) + "% 얻는다. 매 스테이지 마다 골드" + to_string(EveryTurnStat.GoldMod) + " 얻는다.";
    }
};