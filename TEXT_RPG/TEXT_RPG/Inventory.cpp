#include "Inventory.h"

Inventory::Inventory()
{
	this->ItemsInventory.resize(Max_Inventory_size, nullptr);
}
