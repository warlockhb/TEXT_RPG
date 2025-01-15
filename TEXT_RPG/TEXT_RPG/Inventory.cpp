#include "Inventory.h"

#include <iostream>


void Inventory::UpdateStaticStat()
{
    Stat Stat;
    
    for (auto item : ItemsInventory)
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

void Inventory::UpdateStackStat()
{
    Stat Stat;
    
    for (auto item : ItemsInventory)
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

void Inventory::UpdateEveryTurnStat()
{
    Stat Stat;
    
    for (auto item : ItemsInventory)
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


Inventory::~Inventory()
{
    for (auto item : ItemsInventory)
    {
        delete item;
    }
}

void Inventory::Apply()
{
    Owner->SetCurrentMaxHealth(Owner->GetMaxHealth());
    Owner->SetCurrentAttack(Owner->GetAttack());
    
    UpdateStaticStat();
    UpdateStackStat();

    Owner->SetCurrentMaxHealth(Owner->GetMaxHealth() + TotalStaticStat.MaxHealth + TotalStackStat.MaxHealth);
    Owner->SetCurrentAttack(Owner->GetAttack() + TotalStaticStat.Attack + TotalStackStat.Attack);
}



void Inventory::DisplayInventory()
{
}

void Inventory::AddItem(PassiveItem* item)
{
    for (size_t i = 0; i < ItemsInventory.size(); i++)
    {
        if (ItemsInventory[i] == nullptr)
        {
            ItemsInventory[i] = item;
            Apply();
            return;
        }
    }
    
    if (ItemsInventory.size() < Max_Inventory_size)
    {
        ItemsInventory.insert(ItemsInventory.begin(), item);
    }
    else
    {
        cout << "인벤토리가 가득 차서 아이템을 추가할 수 없습니다." << endl;
    }
    Apply();
}

void Inventory::RemoveItem(PassiveItem* item)
{
    // 벡터에서 제거
    auto it = find(ItemsInventory.begin(), ItemsInventory.end(), item);
    if (it != ItemsInventory.end())
    {
        ItemsInventory.erase(it);
    }

    Apply();
}

void Inventory::RemoveItem(int index)
{
    // 검사
    if (index < 0 || index >= ItemsInventory.size()) return;
    
    // 벡터에서 제거
    auto it = ItemsInventory.begin() + index;
    if (it != ItemsInventory.end())
    {
        ItemsInventory.erase(it);
    }
    Apply();
}

PassiveItem* Inventory::GetItem(int index)
{
    // 검사
    if (index < 0 || index >= ItemsInventory.size()) return nullptr;
    return ItemsInventory[index];
}

void Inventory::UpdateStage()
{
    for (auto item : ItemsInventory)
    {
        if (item)
            item->UpdateStack(1);
    }
    Apply();
    UpdateEveryTurnStat();
}


void Inventory::DisplayItemStat(int index)
{
}

