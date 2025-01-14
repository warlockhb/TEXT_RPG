#pragma once
#include "../Item.h"
#include "../../Character.h"

class Character;

class Equipment : public Item
{
public:
    void Equip(Character* Character);
    void Unequip(Character* Character);
};
