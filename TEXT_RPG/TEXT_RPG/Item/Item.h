
#pragma once
#include <string>

#include "ItemType.h"
#include "../Character.h"
using namespace std;

class Character;

class Item
{
protected:
    struct StatModifier
    {
        int LevelMod = 0;
        int HpMod = 0;
        int MaxHpMod = 0;
        int ExpMod = 0;
        int AttackMod = 0;
        int GoldMod = 0;
    
        float HpMult = 0.0f;
        float MaxHpMult = 0.0f;
        float AttackMult = 0.0f;
    };
    
    int ID = 0;
    string Name = "";
    int Price = 0;
    string Description = "";

    StatModifier Mod;
    StatModifier Stage;


    

public:
    Item() = default;
    ~Item() = default;

    // 비교 연산자 : 캐릭터 HasItem에서 사용 가능
    bool operator==(const Item& other) const { return ID == other.ID;}
    
    //Get
    int GetID() const { return ID; }
    string GetName() const { return Name; }
    int GetPrice() const { return Price; }
    string GetDescription() const { return Description; }

    // Get mod
    int GetModLevel() const { return Mod.LevelMod; }
    int GetModHp() const { return Mod.HpMod; }
    int GetModMaxHp() const { return Mod.MaxHpMod; }
    int GetModExp() const { return Mod.ExpMod; }
    int GetModAttack() const { return Mod.AttackMod; }
    int GetModGold() const { return Mod.GoldMod; }

    float GetModHpMult() const { return Mod.HpMult; }
    float GetModMaxHpMult() const { return Mod.MaxHpMult; }
    float GetModAttackMult() const { return Mod.AttackMult; }

    // Get stage mod
    //test
    int GetStageLevelMod() const { return Stage.LevelMod; }
    int GetStageHpMod() const { return Stage.HpMod; }
    int GetStageMaxHpMod() const { return Stage.MaxHpMod; }
    int GetStageExpMod() const { return Stage.ExpMod; }
    int GetStageAttackMod() const { return Stage.AttackMod; }
    int GetStageGoldMod() const { return Stage.GoldMod; }

    float GetStageHpMult() const { return Stage.HpMult; }
    float GetStageMaxHpMult() const { return Stage.MaxHpMult; }
    float GetStageAttackMult() const { return Stage.AttackMult; }
};