#pragma once
#include "../Item.h"
#include "../../Character.h"

class Character;

enum EEquipmentSlotType
{
    HEAD = 0,
    BODY = 1,
    ARM = 2,
    FOOT = 3,
    WEAPON =4
};

class Equipment : public Item
{
protected:
    
    EEquipmentSlotType SlotType;
    
public:
    Equipment() = default;
    
    EEquipmentSlotType GetSlotType() const { return SlotType; }
};
