#include "Player.h"
/// @brief 
/// @param name string type parameter player for name
/// @param classType int type parameter player for class (prefer a value and name declaration stored in enum playerTypeClass located player.h) 
/// @param playerAttackBase int type parameter player for base attack(prefer a value and name declaration stored in enum playerBaseAttack located in playerh class as protected specifiers)
/// @param baseHealthClass int type parameter for player base attack(prefer a value and name declaration stored in enum playerBaseHealth located in player.h class as protected specifiers)
/// @param AttackAnimationName string type parameter for text file wich contains the ASCII draw note: all the text file should be written like "classNameAttack (" and the .txt file need to be included in the build directory like "classNameAttack (index).txt", index will be called in the playerAttackAnimation(Player *&player, Enemy *&en) function wich contains the int index and concatenated with std::tostring()
Player::Player(std::string name, int classType, int playerAttackBase, int baseHealthClass, std::string AttackAnimationName) : m_name(name),
                                                                                                                              playerAttack(playerAttackBase),
                                                                                                                              playerHealth(baseHealthClass),
                                                                                                                              idTypePlayerClass(classType),
                                                                                                                              AnimationTextFileName(AttackAnimationName)
{

}

Player::~Player()
{
}

/// @brief void print name
void Player::printName()
{
    std::cout << m_name << std::endl;
}

void Player::addItemToInventory(Item *item)
{
    Inventory.push_back(item);
}
/// @brief int type function 
/// @return int value (initialized in constructor derived classes )
int Player::getPlayerType()
{
    return idTypePlayerClass;
}
/// @brief Create Item obj on heap and add obj in Item Inventory 
/// @return void
void Player::CreateWeaponItem()
{
    Item *weapon = nullptr;
    //check classPlayerType
    if (getPlayerType() == WizardType)
    {
        //create weapon obj
        Rod *rodPtr = new Rod("The Dark Rod");
        weapon = rodPtr;
        //add to inventory
        Inventory.push_back(weapon);
    }
    else if (getPlayerType() == WarriorType)
    {
        Sword *swordPtr = new Sword("The Long Sword");

        weapon = swordPtr;
        Inventory.push_back(weapon);
    }
    else if (getPlayerType() == RogueType)
    {
        Dagger *daggerPtr = new Dagger("The Bloody Dagger");
        weapon = daggerPtr;
        Inventory.push_back(weapon);
    }
    else
    {
        std::cout<< "weapon can`t be create, check CreateWeaponItem()"<<std::endl;
        // avoid to pushback a nullptr in the Inventory vector Item list
    }

}
/// @brief std::string AnimationTextFileName should be initialized in the derived constructor classes
/// @return  AnimationTextFileName string for animation text.file(return exemple "WizardAttack (")
std::string Player::getNameAnimation()
{
    return AnimationTextFileName;
}


/// @brief private method to check if player has a weapon for chosen class and insert the address of weapon to Item *WeaponSlot if match the weapontype with classtype
void Player::FindWeaponTypeInInventory()
{
    for (auto it : Inventory)
    {
        if (it->getIdWeaponType() == WarriorType)
        {
            WeaponSlot = dynamic_cast<Sword *>(it);
        }
        else if (it->getIdWeaponType() == WizardType)
        {
            WeaponSlot = dynamic_cast<Rod *>(it);
        }
        else if (it->getIdWeaponType() == RogueType)
        {
            WeaponSlot = dynamic_cast<Dagger *>(it);
        }
        else
        {
            std::cout<< "your inventory doesn`t contains a weapon for your class \n";
        }
    }
    if (WeaponSlot != nullptr)
    {
        WeaponSlot->printItemName();
        std::cout << " equipped\n";
    }
}
/// @brief call the private method: FindWeaponTypeInInventory() ;
void Player::equipWeapon()
{
    FindWeaponTypeInInventory();
}
/// @brief return the private attribute for Health 
/// @return  int (initialized in constructor derived classType)
int Player::getPlayerHealth()
{
    return playerHealth;
}
/// @brief int type method which returns all Attack value(for future implementations of item with attack attribute add the getter in this method)
/// @return int value ,all attack value of a player 
int Player::getPlayerAttack()
{
    int weaponAttack = 0;
    if (WeaponSlot != nullptr)
    {
        weaponAttack = WeaponSlot->getWeaponAttack();
    }
    return playerAttack + weaponAttack;
}
/// @brief vector Item* method
/// @return  vector Inventory which access is in private 
std::vector<Item *> &Player::getInventory()
{
    return Inventory;
}
