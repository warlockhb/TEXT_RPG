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
    std::cout << "==== Inventory ====" << std::endl;
    // 인벤토리가 비었는지 확인
    if (ItemsInventory.empty()) 
    {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    // 인벤토리 아이템 출력
    for ( size_t i = 0; i < ItemsInventory.size(); ++i ) 
    {
        PassiveItem* item = ItemsInventory[i];
        if (item != nullptr) 
        {
            // 아이템의 정보를 출력 (이름, 속성 등)
            std::cout << i + 1 << ". " << item->GetName() << std::endl;
        }
        else 
        {
            std::cout << i + 1 << ". Empty Slot" << std::endl;
        }
    }
    std::cout << "===================" << std::endl;
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

    if (ItemsInventory.size() >= Max_Inventory_size)
    {
        cout << "아이템 보관함이 가득차서, 아이템을 담을 수 없습니다." << endl;
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

void Inventory::ExpandItemInventory()
{
    static int ExpandCount = 0;
    const int MaxExpandCount = 2;

    if (ExpandCount >= MaxExpandCount)
    {
        cout << "인벤토리 크기 최대 확장되어 더이상 확장 불가." << endl;
    }
    switch (ExpandCount)
    {
    case 0:
        ItemsInventory.resize(ItemsInventory.size() + 3);
        break;
    case 1:
        ItemsInventory.resize(ItemsInventory.size() + 5);
        break;
    default:
        break;
    }

    ExpandCount++;
    cout << "현재 인벤토리 사이즈 : " << GetMaxItemInventorySize() << endl;
}

int Inventory::GetItemInventoryEmptySize()
{
    int index = 0;
    for (int i = 0; i < ItemsInventory.size(); i++)
    {
        if (ItemsInventory[i] == nullptr)
        {
            index++;
        }
    }
    return index;
}

int Inventory::GetMaxItemInventorySize()
{
    return ItemsInventory.size();
}



