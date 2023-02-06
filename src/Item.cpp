#include "Item.h"

Item::Item(std::string item_name) : itemName(item_name)
{
    std::cout << "Item Crea\n";
}

Item::~Item()
{
    std::cout << "Item Dest\n";
}

void Item::getItemName()
{
    std::cout << itemName << std::endl;
}