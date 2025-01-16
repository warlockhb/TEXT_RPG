#pragma once
#include "Equipment.h"

class HeadLeatherCap : public Equipment
{
public:
    HeadLeatherCap()
    {
        SlotType = HEAD;
        ID = ID_HEAD_LEATHER_HELMLET;
        Name = "가죽 투구";
        Price = 100;
        StaticStat.MaxHpMod = 20;
        Description = "최대 체력 " + to_string(StaticStat.MaxHpMod) + " 을 얻는다.";
    }
};


class HeadIronHelmet : public Equipment
{
public:
    HeadIronHelmet()
    {
        SlotType = HEAD;
        ID = ID_HEAD_IRON_HELMLET;
        Name = "철 투구";
        Price = 400;
        StaticStat.MaxHpMod = 50;
        Description = "최대 체력 " + to_string(StaticStat.MaxHpMod) + " 을 얻는다.";
    }
};

class HeadKnightHelmet : public Equipment
{
public:
    HeadKnightHelmet()
    {
        SlotType = HEAD;
        ID = ID_HEAD_KNIGHT_HELMLET;
        Name = "기사 투구";
        Price = 1500;
        StaticStat.MaxHpMod = 200;
        StaticStat.MaxHpMult = 0.05f;
        Description = "최대 체력 " + to_string(StaticStat.MaxHpMod) + " 및 기본 최대 체력의 " + to_string(StaticStat.MaxHpMult) +"% 을 얻는다.";
    }
};

class HeadDragonHelmet : public Equipment
{
public:
    HeadDragonHelmet()
    {
        SlotType = HEAD;
        ID = ID_HEAD_DRAGON_HELMLET;
        Name = "드래곤 투구";
        Price = 4000;
        StaticStat.MaxHpMod = 400;
        StackStat.MaxHpMod = 50;
        Description = "최대 체력 " + to_string(StaticStat.MaxHpMod) + "을 얻는다. 매 스테이지 마다 1 스택이 쌓이며, 1 스택 당 최대 체력" + to_string(StackStat.MaxHpMod) +" 얻는다.";
    }
};

