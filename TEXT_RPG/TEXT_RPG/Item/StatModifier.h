#pragma once

struct StatModifier
{
    int LevelMod = 0;
    int HpMod = 0;
    int MaxHpMod = 0;
    int ExpMod = 0;
    int AttackMod = 0;
    int GoldMod = 0;
        
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

    template <typename T>
    StatModifier& operator*(const T value)
    {
        LevelMod = static_cast<int>(LevelMod * value);
        HpMod = static_cast<int>(HpMod * value);
        MaxHpMod = static_cast<int>(MaxHpMod * value);
        AttackMod = static_cast<int>(AttackMod * value);
        ExpMod = static_cast<int>(ExpMod * value);
        GoldMod = static_cast<int>(GoldMod * value);
        MaxHpMult *= value;
        AttackMult *= value;
        return *this;
    }
};