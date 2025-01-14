
#pragma once
#include <string>

#include "ItemType.h"
#include "../Character.h"
using namespace std;

class Character;

struct StatModifier
{
    int LevelMod = 0;
    int MaxHpMod = 0;
    int ExpMod = 0;
    int AttackMod = 0;

    float LevelMult = 0.0f;
    float MaxHpMult = 0.0f;
    float ExpMult = 0.0f;
    float AttackMult = 0.0f;
};

class Item
{
protected:
    int ID = 0;
    string Name = "";
    int Price = 0;
    string Description = "";
    StatModifier StatModifier;

private:

    // 기본 모디파이 적용
    // void ApplyModifier(Character* Character);
    // void RemoveModifier(Character* Character);

    // 특수 효과 적용
    // virtual void ApplyEffect(Character* Character);
    // virtual void RemoveEffect(Character* Character);


public:
    Item() = default;
    virtual ~Item() = default;

    // 비교 연산자 : 캐릭터 HasItem에서 사용 가능
    bool operator==(const Item& other) const;
    
    void Apply(Character* Character);
    void Remove(Character* Character);

    // Get
    // int GetID() const;
    // string GetName() const;
    // int GetPrice() const;
    // string GetDescription() const;
};