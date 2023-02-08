#include "Item.h"

Item::Item(std::string item_name, int itemType) : itemName(item_name), idTypeItem(itemType)
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

int Item::getIdWeaponType()
{
    return idTypeItem;
}

int Item::getWeaponAttack()
{
    int item=0;
     
        return item; 
    
}