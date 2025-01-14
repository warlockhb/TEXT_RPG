#include "Item.h"


bool Item::operator==(const Item& other) const
{
    return ID == other.ID;
}


