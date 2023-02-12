#include "Item.h"

Item::Item(std::string item_name, int itemType, int itemAttack) : itemName(item_name), idTypeItem(itemType), weaponAtk(itemAttack)
{
}

Item::~Item()
{
}

void Item::getItemName()
{
    std::cout << itemName;
}

int Item::getIdWeaponType()
{
    return idTypeItem;
}

int Item::getWeaponAttack()
{

    return weaponAtk;
}