#pragma once
#include "../Item.h"
#include "../../Character.h"

class Character;

enum class EEquipmentSlotType
{
    HEAD = 0,
    BODY = 1,
    ARM = 2,
    FOOT = 3,
    WEAPON =4
};

class Equipment : public Item
{
private:
    
    EEquipmentSlotType SlotType;
    
public:
    Equipment() {}
    
    int GetSlotType() const { return static_cast<int>(SlotType); }
};
