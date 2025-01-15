#pragma once

#include "Stat.h"


template<typename T>
void StatManager::UpdateStaticStat(const std::vector<T*>& Items)
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
void StatManager::UpdateStackStat(const std::vector<T*>& Items)
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
void StatManager::UpdateEveryTurnStat(const std::vector<T*>& Items)
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
