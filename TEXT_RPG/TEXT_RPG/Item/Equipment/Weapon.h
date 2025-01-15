#pragma once
#include "Equipment.h"


class WeaponLongSword : public Equipment
{
public:
    WeaponLongSword()
    {
        SlotType = WEAPON;
        ID = ID_WEAPON_LONG_SWORD;
        Name = "롱소드";
        Price = 300;
        StaticStat.AttackMod = 10;
        StackStat.AttackMod = 1; 
        Description = "공격력 " + to_string(StaticStat.AttackMod) + " 을 얻는다. 매 스테이지 마다 1 스택을 얻는다. 스택 당 공격력 " + to_string(StackStat.AttackMod) + "을 얻는다.";
    }
};

class WeaponBattleAxe : public Equipment
{
public:
    WeaponBattleAxe()
    {
        SlotType = WEAPON;
        ID = ID_WEAPON_BATTLE_AXE;
        Name = "전투도끼";
        Price = 300;
        StaticStat.AttackMod = 70;
        StackStat.MaxHpMod = -2;
        Description = "공격력 " + to_string(StaticStat.AttackMod) + "을 얻는다. 매 스테이지 마다 1 스택을 얻는다. 스택 당 최대 체력 " + to_string(StackStat.MaxHpMod ) + "을 잃는다.";
    }
};

class WeaponLongBow : public Equipment
{
public:
    WeaponLongBow()
    {
        SlotType = WEAPON;
        ID = ID_WEAPON_LONG_BOW;
        Name = "장궁";
        Price = 300;
        StaticStat.AttackMult = 0.2f;
        EveryTurnStat.AttackMult = 0.05f;
        Description = "공격력 " + to_string(StaticStat.AttackMult) + "을 얻는다. 매 스테이지 마다 기본 공격력의 " + to_string(StackStat.MaxHpMod ) + "만큼 영구히 증가한다.";
    }
};

class WeaponMagicStaff : public Equipment
{
public:
    WeaponMagicStaff()
    {
        SlotType = WEAPON;
        ID = ID_WEAPON_MAGIC_STAFF;
        Name = "지팡이";
        Price = 300;
        StaticStat.AttackMod = 5;
        EveryTurnStat.ExpMod = 50;
        EveryTurnStat.HpMod = 30;
        Description = "공격력 " + to_string(StaticStat.AttackMult) + "을 얻는다. 매 스테이지 마다 체력 " + to_string(EveryTurnStat.HpMod) + "만큼 회복하고, 경험치 " + to_string(EveryTurnStat.ExpMod)+ "만큼 증가한다.";
    }
};