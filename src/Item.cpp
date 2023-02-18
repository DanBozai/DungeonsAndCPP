#include "Item.h"

/// @brief 
/// @param item_name string type parameter for item name
/// @param itemType int type parameter for ItemType (use enums for itemType)
/// @param itemAttack  int type parameter for item which contains attack attribute
Item::Item(std::string item_name, int itemType, int itemAttack) : itemName(item_name), idTypeItem(itemType), weaponAtk(itemAttack)
{

}

Item::~Item()
{

}
/// @brief print itemName (private access)
void Item::printItemName()
{
    std::cout << itemName;
}
/// @brief getter for idTypeItem
/// @return int type value for the idTypeItem (declared in private access)
int Item::getIdWeaponType()
{
    return idTypeItem;
}
/// @brief getter for attribute weaponAtk (declared in private access)
/// @return  int type value
int Item::getWeaponAttack()
{

    return weaponAtk;
}