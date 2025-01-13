
#pragma once
#include <string>
#include "..//Character.h"
using namespace std;

struct StatModifier
{
    int LevelMod = 0;
    int HpMod = 0;
    int MaxHpMod = 0;
    int ExpMod = 0;
    int AttackMod = 0;
    int GoldMod = 0;
};

class Item
{
private:
    int ID = 0;
    string Name = '';
    int Price = 0;
    string Description = '';
    StatModifier StatModifier;

public:
    Item(int code, string name, int price, string desc);

    // 비교 연산자 : 캐릭터 HasItem에서 사용 가능
    bool operator==(const Item& other) const;
    
    virtual void ApplyEffect(Character* character) = 0;
    virtual void RemoveEffect(Character* character) = 0;

    // Get
    int GetID() const;
    string GetName() const;
    int GetPrice() const;
    string GetDescription() const;
};