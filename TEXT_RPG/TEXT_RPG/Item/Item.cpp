#include "Item.h"

Item::Item(int code, string name, int price, string desc)
{
}

bool Item::operator==(const Item& other) const
{
    return ID == other.ID;
}
