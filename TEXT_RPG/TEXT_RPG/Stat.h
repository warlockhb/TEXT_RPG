#pragma once
#include <vector>

#include "Character.h"


struct Stat
{
    int Level = 0;
    int Health = 0;
    int MaxHealth = 0;
    int Attack = 0;
    int Exp = 0;
    int MaxExp = 0;
    int Gold = 0;
};

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

    StatModifier& operator+=(const StatModifier& other)
    {
        LevelMod += other.LevelMod;
        HpMod += other.HpMod;
        MaxHpMod += other.MaxHpMod;
        AttackMod += other.AttackMod;
        ExpMod += other.ExpMod;
        GoldMod += other.GoldMod;
        MaxHpMult += other.MaxHpMult;
        AttackMult += other.AttackMult;
        return *this;
    }
    StatModifier& operator=(const StatModifier& other)
    {
        if (this != &other)
        {
            LevelMod = other.LevelMod;
            HpMod = other.HpMod;
            MaxHpMod = other.MaxHpMod;
            AttackMod = other.AttackMod;
            ExpMod = other.ExpMod;
            GoldMod = other.GoldMod;
            MaxHpMult = other.MaxHpMult;
            AttackMult = other.AttackMult;
        }
        return *this;
    }
    
    StatModifier& operator*=(const int value)
    {
        LevelMod = LevelMod * value;
        HpMod = HpMod * value;
        MaxHpMod = MaxHpMod * value;
        AttackMod = AttackMod * value;
        ExpMod = ExpMod * value;
        GoldMod = GoldMod * value;
        MaxHpMult *= value;
        AttackMult *= value;
        return *this;
    }
};

class StatManager
{
private:
    Character* Owner;
    
    Stat TotalStaticStat;
    Stat TotalEveryTurnStat;
    Stat TotalStackStat;

public:
    StatManager(Character* Ower) : Owner(Ower) {}
    
    template<typename T>
    void UpdateStaticStat(const std::vector<T*>& Items);
    
    template<typename T>
    void UpdateEveryTurnStat(const std::vector<T*>& Items);
    
    template<typename T>
    void UpdateStackStat(const std::vector<T*>& Items);
    
};