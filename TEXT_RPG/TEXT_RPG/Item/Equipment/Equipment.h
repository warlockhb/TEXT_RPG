#pragma once
#include "../Item.h"
#include "../../Character.h"

class Character;

enum class EEquipmentSlotType
{
    HEAD = 0,
    BODY = 1,
    ARMS = 2,
    FEET = 3,
};

class Equipment : public Item
{
private:
    
    EEquipmentSlotType SlotType;
    
public:
    Equipment(EEquipmentSlotType SlotType) : SlotType(SlotType) {}
    
    int GetSlotType() const { return static_cast<int>(SlotType); }
};
