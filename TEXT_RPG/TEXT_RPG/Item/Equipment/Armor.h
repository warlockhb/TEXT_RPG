#pragma once
#include "Equipment.h"

class BodyLeatherCap : public Equipment
{
public:
    BodyLeatherCap()
    {
        SlotType = BODY;
        ID = ID_BODY_LEATHER_ARMOR;
        Name = "가죽 갑옷";
        Price = 100;
        StaticStat.MaxHpMult = 0.1f;
        Description = "기본 최대 체력의 " + to_string(StaticStat.MaxHpMult) + "% 얻는다.";
    }
};

class BodyChainArmor : public Equipment
{
public:
    BodyChainArmor()
    {
        SlotType = BODY;
        ID = ID_BODY_CHAIN_ARMOR;
        Name = "체인 깁옷";
        Price = 200;
        StaticStat.MaxHpMult = 0.15f;
        Description = "기본 최대 체력의 " + to_string(StaticStat.MaxHpMult) + "% 얻는다.";
    }
};

class BodyPlateArmor : public Equipment
{
public:
    BodyPlateArmor()
    {
        SlotType = BODY;
        ID = ID_BODY_PLATE_ARMOR;
        Name = "플레이트 깁옷";
        Price = 500;
        StaticStat.MaxHpMult = 0.15f;
        Description = "기본 최대 체력의 " + to_string(StaticStat.MaxHpMult) + "% 얻는다.";
    }
};

class BodyDragonArmor : public Equipment
{
public:
    BodyDragonArmor()
    {
        SlotType = BODY;
        ID = ID_BODY_DRAGON_ARMOR;
        Name = "드래곤 갑옷";
        Price = 1000;
        StaticStat.MaxHpMult = 0.20f;
        EveryTurnStat.HpMult = 0.02f;
        Description = "기본 최대 체력의 " + to_string(StaticStat.MaxHpMult) + "% 얻는다. 매 스테이지 마다 체력 " + to_string(EveryTurnStat.HpMult) + "% 회복한다.";
    }
};
    
    