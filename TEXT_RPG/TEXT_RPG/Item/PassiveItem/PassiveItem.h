#pragma once
#include "..//Item.h"

class PassiveItem : public Item
{
public:
    virtual void ApplyEffect(Character* Character) override;
    virtual void RemoveEffect(Character* Character) override;
};

