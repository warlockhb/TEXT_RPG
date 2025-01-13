#include "Item.h"

// void Item::ApplyEffect(Character* Character)
// {
// }
//
// void Item::RemoveEffect(Character* Character)
// {
// }

bool Item::operator==(const Item& other) const
{
    return ID == other.ID;
}

void Item::Apply(Character* Character)
{
}

void Item::Remove(Character* Character)
{
}
