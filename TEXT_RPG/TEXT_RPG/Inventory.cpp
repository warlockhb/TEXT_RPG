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
            Stat.MaxHealth += StackStat.MaxHpMod * Stack;
            Stat.Attack += StackStat.AttackMod * Stack;

            // 멀티
            Stat.MaxHealth += static_cast<int>(Owner->GetMaxHealth() * StackStat.MaxHpMult) * Stack;
            Stat.Attack += static_cast<int>(Owner->GetAttack() * StackStat.AttackMult) * Stack;
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

    // 현재 적용
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
    UpdateStaticStat();
    UpdateStackStat();

    Owner->SetCurrentMaxHealth(Owner->GetMaxHealth() + TotalStaticStat.MaxHealth + TotalStackStat.MaxHealth);
    Owner->SetCurrentAttack(Owner->GetAttack() + TotalStaticStat.Attack + TotalStackStat.Attack);
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
            Apply();
            return;
        }
    }

    if (ItemsInventory.size() >= Max_Inventory_size)
    {
        cout << "아이템 보관함이 가득차서, 아이템을 담을 수 없습니다." << endl;
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
    cout << "현재 인벤토리 사이즈 : " << GetItemInventorySize() << endl;
}

int Inventory::GetItemInventorySize()
{
    return ItemsInventory.size();
}


