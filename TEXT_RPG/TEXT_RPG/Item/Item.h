
#pragma once
#include <string>

#include "ItemType.h"
#include "../Stat.h"
#include "../Character.h"
using namespace std;

class Character;

class Item
{
protected:
    int ID = 0;
    string Name = "";
    int Price = 0;
    string Description = "";
    
    StatModifier StaticStat = StatModifier();
    StatModifier EveryTurnStat = StatModifier();
    StatModifier StackStat = StatModifier();
    int DynamicStack = 0;

    

public:
    Item() = default;
    // 복사 생성자

    Item(const Item& other)
    {
        ID = other.ID;
        Name = other.Name;
        Price = other.Price;
        Description = other.Description;
        StaticStat = other.StaticStat;
        EveryTurnStat = other.EveryTurnStat;
        StackStat = other.StackStat;
        DynamicStack = other.DynamicStack;
    }

    virtual ~Item() = default;

    // 비교 연산자 : 캐릭터 HasItem에서 사용 가능
    bool operator==(const Item& other) const { return ID == other.ID;}


    // Get
    int GetID() const { return ID; }
    string GetName() const { return Name; }
    int GetPrice() const { return Price; }
    string GetDescription() const { return Description; }

    StatModifier GetStaticStat() const { return StaticStat; }
    StatModifier GetEveryTurnStat() const { return EveryTurnStat; };
    StatModifier GetStackStat() const { StatModifier temp = StackStat; temp *= DynamicStack; return temp; }

    int GetStack() const { return DynamicStack; }

    // Set
    void UpdateStack(int value) {DynamicStack += value; }
};