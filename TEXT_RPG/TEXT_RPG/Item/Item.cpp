#include "Item.h"

void Item::ApplyModifier(Character* Character)
{
}

void Item::RemoveModifier(Character* Character)
{
}

bool Item::operator==(const Item& other) const
{
    return ID == other.ID;
}

void Item::Apply(Character* Character)
{
    ApplyModifier(Character);
    ApplyEffect(Character);
}

void Item::Remove(Character* Character)
{
    RemoveModifier(Character);
    RemoveEffect(Character);
}
