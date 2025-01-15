#include "EquipmentSlot.h"

#include <iostream>


void EquipmentSlot::AddItem(Equipment* Item)
{
    // 아이템 인지 확인
    if (!Item) return;
    
    // 보관함이 가득차지 않았다면,
    if (StorageSlots.size() < Max_Storage_size)
    {
        for (size_t i = 0; i < StorageSlots.size(); i++)
        {
            if (StorageSlots[i] == nullptr)
            {
                StorageSlots[i] = Item;
                SlotStats.Apply(ApplySlots);
                return;
            }
        }
    }
    else
    {
        cout << "장비 보관함이 가득 차서 아이템을 추가할 수 없습니다." << endl;
    }
    SlotStats.Apply(ApplySlots);
}

void EquipmentSlot::RemoveItem(int StorageSlot)
{
    // 검사
    if (StorageSlot < 0 || StorageSlot >= StorageSlots.size()) return;

    // 벡터에서 제거
    StorageSlots.erase(StorageSlots.begin() + StorageSlot);
    SlotStats.Apply(ApplySlots);
}

void EquipmentSlot::Equip(int StorageSlot)
{
    // 검사
    if (StorageSlot < 0 || StorageSlot >= StorageSlots.size()) return;

    // 아이템의 슬롯 타입 가지고 오기
    int SlotType = StorageSlots[StorageSlot]->GetSlotType();
    if (SlotType < 0 || SlotType >= 4) return;

    // 슬롯 타입으로 장착 슬롯 접근
    // 이미 존재한다면?
    if (ApplySlots[SlotType])
    {
        // 교체
        ChangeItem(SlotType, StorageSlot);
    }
    else
    {
        // 착용
        ApplySlots[SlotType] = StorageSlots[StorageSlot];
        // 해당 보관함 아이템 포인터 해제
        StorageSlots[StorageSlot] = nullptr;
    }
    SlotStats.Apply(ApplySlots);
}

void EquipmentSlot::Unequip(int ApplySlot)
{
    // 아이템 슬롯 존재 검사
    if (ApplySlots[ApplySlot] == nullptr) return;

    // 아이템 가져오기
    Equipment* Item = ApplySlots[ApplySlot];

    // 보관함이 가득차지 않았다면
    if (StorageSlots.size() < Max_Storage_size)
    {
        // 먼저 발견한 보관함 빈칸에 삽입
        for (size_t i = 0; i < StorageSlots.size(); i++)
        {
            if (StorageSlots[i] == nullptr)
            {
                StorageSlots[i] = Item;
                SlotStats.Apply(ApplySlots);
                return;
            }
        }
    }
    else
    {
        cout << "장비 보관함이 가득 차서, 장비를 해제할 수 없습이다." << endl;
    }
    SlotStats.Apply(ApplySlots);
}

void EquipmentSlot::ChangeItem(int ApplySlot, int StorageSlot)
{
    // 슬롯 검사
    if (ApplySlots[ApplySlot] == nullptr) return;
    if (StorageSlots[StorageSlot] == nullptr) return;
    
    ApplySlots[ApplySlot] = StorageSlots[StorageSlot];
    StorageSlots[StorageSlot] = nullptr;
    
    SlotStats.Apply(ApplySlots);
}

Equipment* EquipmentSlot::GetItem(int Slot, int Index)
{
    if (Slot < 0 || Slot >= 1) return nullptr;

    if (Slot == 0)
    {
        if (Index < 0 || Index >= StorageSlots.size()) return nullptr;
        if (StorageSlots[Index] == nullptr) return nullptr;
        
        return ApplySlots[Index];
    }
    else if (Slot == 1)
    {
        if (Index < 0 || Index >= ApplySlots.size()) return nullptr;
        if (ApplySlots[Index] == nullptr) return nullptr;
        
        return StorageSlots[Index];
    }
    
}

void EquipmentSlot::UpdateStage()
{
    for (auto item : ApplySlots)
    {
        if (item)
            item->UpdateStack(1);
    }
    SlotStats.Apply(ApplySlots);
    SlotStats.Apply(ApplySlots);
}

void EquipmentSlot::DisplayItemStat(int Slot)
{
}



