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
    void UpdateStaticStat(const std::vector<T*>& Items)
    {
        Stat Stat;
    
        for (auto item : Items)
        {
            if (item)
            {
                StatModifier StaticStat = item->GetStaticStat();
                // 모디
                // 현재 체력 비례는 제외
                Stat.MaxHealth += StaticStat.MaxHpMod;
                Stat.Attack += StaticStat.AttackMod;

                // 멀티
                // 현재 체력 비례는 제외
                Stat.MaxHealth += (Owner->GetMaxHealth() * StaticStat.MaxHpMult);
                Stat.Attack += (Owner->GetAttack() * StaticStat.AttackMult);
            }
        }
        TotalStaticStat = Stat;
    }
    
    template<typename T>
    void UpdateEveryTurnStat(const std::vector<T*>& Items)
    {
        Stat Stat;
        
        for (auto item : Items)
        {
            if (item)
            {
                StatModifier EveryTurnStat = item->GetEveryTurnStat();
                // 모디
                // 현재 체력 비례는 제외
                Stat.Health += EveryTurnStat.HpMod;
                Stat.MaxHealth += EveryTurnStat.MaxHpMod;
                Stat.Attack += EveryTurnStat.AttackMod;
                Stat.Exp += EveryTurnStat.ExpMod;
                Stat.Gold += EveryTurnStat.GoldMod;

                // 멀티
                // 최대 체력 비례 회복 매커니즘
                Stat.Health += (Owner->GetMaxHealth() * EveryTurnStat.HpMult);
                Stat.MaxHealth += (Owner->GetMaxHealth() * EveryTurnStat.MaxHpMult);
                Stat.Attack += (Owner->GetAttack() * EveryTurnStat.AttackMult);
            }
            
        }
        TotalEveryTurnStat = Stat;

        // TODO: EveryTurn 스탯이 어떻게 쌓였는지 추적할수 있게 만들어야함
        // TODO: EveryTurn 스탯의 추적 불가로 인한, 문제점 생길 것으로 보임.
        // 아이템을 해제해도, 스택 형과 달리 영구히 증가함.
        Owner->SetExp(Owner->GetExp() + TotalEveryTurnStat.Exp);
        Owner->SetGold(Owner->GetGold() + TotalEveryTurnStat.Gold);
        Owner->SetCurrentMaxHealth(Owner->GetCurrentMaxHealth() + TotalEveryTurnStat.MaxHealth);
        Owner->SetCurrentHealth(Owner->GetCurrentHealth() + TotalEveryTurnStat.Health);
        Owner->SetCurrentAttack(Owner->GetCurrentAttack() + TotalEveryTurnStat.Attack);
    }
    
    template<typename T>
    void UpdateStackStat(const std::vector<T*>& Items)
    {
        Stat Stat;
    
        for (auto item : Items)
        {
            if (item)
            {
                StatModifier StackStat = item->GetStackStat();
                int Stack = item->GetStack();
            
                // 모디
                // 현재 체력 비례는 제외
                Stat.MaxHealth += StackStat.MaxHpMod;
                Stat.Attack += StackStat.AttackMod;

                // 멀티
                Stat.MaxHealth += static_cast<int>(Owner->GetMaxHealth() * StackStat.MaxHpMult);
                Stat.Attack += static_cast<int>(Owner->GetAttack() * StackStat.AttackMult);
            }
        }
        TotalStackStat = Stat;
    }

    template<typename T>
    void Apply(const std::vector<T*>& Items)
    {
        Owner->SetCurrentMaxHealth(Owner->GetMaxHealth());
        Owner->SetCurrentAttack(Owner->GetAttack());
    
        UpdateStaticStat(Items);
        UpdateStackStat(Items);

        Owner->SetCurrentMaxHealth(Owner->GetMaxHealth() + TotalStaticStat.MaxHealth + TotalStackStat.MaxHealth);
        Owner->SetCurrentAttack(Owner->GetAttack() + TotalStaticStat.Attack + TotalStackStat.Attack);
    }
    
};