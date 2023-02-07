#include "Player.h"

Player::Player(std::string name, int classType) : m_name(name), idTypePlayerClass(classType)
{
    std::cout << "Player Created\n\n";
}

Player::~Player()
{
    std::cout << "Player Dest\n";
}

void Player::getName()
{
    std::cout << m_name << std::endl;
}

void Player::addItemToInventory(Item *item)
{
    Inventory.push_back(item);
}

int Player::getPlayerType()
{
    return idTypePlayerClass;
}

Item *Player::CreateWeaponItem()
{
    Item *weapon = nullptr;

    if (getPlayerType() == WizardType)
    {
        Rod *rodPtr = new Rod("The Staff of Water");
        weapon = rodPtr;
        Inventory.push_back(weapon);
        // playerPtr->addItemToInventory(weapon);
    }
    else if (getPlayerType() == WarriorType)
    {
        Sword *swordPtr = new Sword("Long Sword");

        weapon = swordPtr;
        Inventory.push_back(weapon);
        // playerPtr->addItemToInventory(weapon);
    }
    else if (getPlayerType() == RogueType)
    {
        Dagger *daggerPtr = new Dagger("The Bloody Dagger");
        weapon = daggerPtr;
        Inventory.push_back(weapon);
        // playerPtr->addItemToInventory(weapon);
    }
   
    return weapon;
}

void Player::Attack()
{
}

Item *Player::FindWeaponTypeInInventory()
{
    Item *ptr = nullptr;
    for (auto it : Inventory)
    {
        if (it->getIdWeaponType() == getPlayerType())
        {
            ptr = dynamic_cast<Sword *>(it);
        }
        else if (it->getIdWeaponType() == getPlayerType())
        {
            ptr = dynamic_cast<Rod *>(it);
        }
        else if (it->getIdWeaponType() == getPlayerType())
        {
            ptr = dynamic_cast<Dagger *>(it);
        }
    }

    return ptr;
}

std::vector<Item *> &Player::getInventory()
{
    return Inventory;
}
