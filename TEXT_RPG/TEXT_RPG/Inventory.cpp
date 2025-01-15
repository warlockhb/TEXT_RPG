#include "Inventory.h"

#include <iostream>

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
    for (size_t i = 0; i < ItemsInventory.size(); i++)
    {
        if (ItemsInventory[i] == nullptr)
        {
            ItemsInventory[i] = item;
            ApplyStats.Apply(ItemsInventory);
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
    ApplyStats.Apply(ItemsInventory);
}

void Inventory::RemoveItem(PassiveItem* item)
{
    // 벡터에서 제거
    auto it = find(ItemsInventory.begin(), ItemsInventory.end(), item);
    if (it != ItemsInventory.end())
    {
        ItemsInventory.erase(it);
    }

    ApplyStats.Apply(ItemsInventory);
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
    ApplyStats.Apply(ItemsInventory);
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
    ApplyStats.Apply(ItemsInventory);
    ApplyStats.UpdateEveryTurnStat(ItemsInventory);
}


void Inventory::DisplayItemStat(int index)
{
}

