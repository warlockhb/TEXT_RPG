﻿#pragma once
#include <vector>
#include "Item/Equipment/Equipment.h"
#include "Character.h"
#include "Stat.h"

class Character;

class EquipmentSlot
{
private:

    // 멤버 변수
    Character* Owner;

    size_t Max_Storage_size = 5;
    size_t Max_Apply_size = 4;
    vector<Equipment*> StorageSlots;
    vector<Equipment*> ApplySlots;

    StatManager SlotStats;

public:
    EquipmentSlot(Character* Ower) :
        Owner(Ower),
        StorageSlots(Max_Storage_size),
        ApplySlots(Max_Apply_size),
        SlotStats(Ower){}


    // 보관함 슬롯 함수
    // void DisplayStorage();
    void AddItem(Equipment* Item);
    void RemoveItem(int StorageSlot);

    // 착용 슬롯 함수
    // void DisplayApply();
    void Equip(int StorageSlot);
    void Unequip(int ApplySlot);
    void ChangeItem(int ApplySlot, int StorageSlot);

    //
    Equipment* GetItem(int Slot, int Index);

    //TODO: 스테이지 클리어 마다 외부에서 호출 바람 
    void UpdateStage();

    //TODO: 디스플레이 함수 구현 해야함.
    void DisplayItemStat(int Slot);
};
