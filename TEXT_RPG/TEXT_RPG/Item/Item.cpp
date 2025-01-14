#include "Item.h"


bool Item::operator==(const Item& other) const
{
    return ID == other.ID;
}

int Item::GetID() const
{
    return ID;
}

string Item::GetName() const
{
    return Name;
}

int Item::GetPrice() const
{
    return Price;
}

string Item::GetDescription() const
{
    return Description;
}

StatModifier* Item::GetMod() const
{
    return Mod;
}

StatModifier* Item::GetModStage() const
{ 
    return ModStage;
}

