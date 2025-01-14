#include "Inventory.h"


void Inventory::Update()
{
    Stat Stat;
    
    for (auto item : ItemsInventory)
    {
        
        if (item)
        {
            // 모디
            Stat.Level += item->GetStaticStat().LevelMod +
                item->GetDynamicStat().LevelMod;
            
            Stat.Health += item->GetStaticStat().HpMod +
                item->GetDynamicStat().HpMod;
            
            Stat.MaxHealth += item->GetStaticStat().MaxHpMod +
                  item->GetDynamicStat().MaxHpMod;

            Stat.Attack += item->GetStaticStat().AttackMod +
               item->GetDynamicStat().AttackMod;

            Stat.Exp += item->GetStaticStat().ExpMod +
                item->GetDynamicStat().ExpMod;

            Stat.Gold += item->GetStaticStat().GoldMod +
                item->GetDynamicStat().GoldMod;

            // 멀티
            Stat.MaxHealth += (Owner->GetMaxHealth() * item->GetStaticStat().MaxHpMult) +
                (Owner->GetMaxHealth() * item->GetDynamicStat().MaxHpMult);
            
            Stat.Attack += (Owner->GetMaxHealth() * item->GetStaticStat().AttackMult) +
                (Owner->GetMaxHealth() * item->GetDynamicStat().AttackMult);
        }
    }
}

Inventory::~Inventory()
{
    for (auto item : ItemsInventory)
    {
        delete item;
    }
}

void Inventory::DisplayInventory()
{
}

void Inventory::AddItem(PassiveItem* item)
{
    ItemsInventory.push_back(item);
    
    Update();
}

void Inventory::RemoveItem(PassiveItem* item)
{
    // 벡터에서 제거
    auto it = find(ItemsInventory.begin(), ItemsInventory.end(), item);
    if (it != ItemsInventory.end())
    {
        ItemsInventory.erase(it);
    }
    
    Update();
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

    Update();
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
        item->UpdateDynamic(1);
    }
    Update();
}


void Inventory::DisplayItemStat(int index)
{
}

