
#pragma once
#include <string>

#include "ItemType.h"
#include "../Character.h"
using namespace std;

class Character;

class StatModifier
{
private:
    int LevelMod = 0;
    int HpMod = 0;
    int MaxHpMod = 0;
    int ExpMod = 0;
    int AttackMod = 0;
    int GoldMod = 0;
    
    float HpMult = 0.0f;
    float MaxHpMult = 0.0f;
    float AttackMult = 0.0f;

public:
    StatModifier() = default;
    ~StatModifier() = default;
    
    // Get 함수
    int GetLevelMod() const { return LevelMod; }
    int GetHpMod() const { return HpMod; }
    int GetMaxHpMod() const { return MaxHpMod; }
    int GetExpMod() const { return ExpMod; }
    int GetAttackMod() const { return AttackMod; }
    int GetGoldMod() const { return GoldMod; }

    float GetHpMult() const { return HpMult; }
    float GetMaxHpMult() const { return MaxHpMult; }
    float GetAttackMult() const { return AttackMult; }
};

class Item
{
protected:
    int ID = 0;
    string Name = "";
    int Price = 0;
    string Description = "";

    StatModifier* Mod = new StatModifier();
    StatModifier* ModStage = new StatModifier();


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
    StatModifier* GetMod() const { return Mod; }
    StatModifier* GetModStage() const { return ModStage; }
};