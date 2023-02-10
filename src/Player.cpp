#include "Player.h"

Player::Player(std::string name, int classType,std::string AttackAnimationName) : m_name(name), idTypePlayerClass(classType),AnimationTextFileName(AttackAnimationName)
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
        Rod *rodPtr = new Rod("The Dark Rod");
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

std::string Player::getNameAnimation()
{
    return AnimationTextFileName;
}

void Player::Attack()
{
}

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
    }
    if (WeaponSlot != nullptr)
    {
        WeaponSlot->getItemName();
        std::cout << "\n";
    }
}

void Player::equipWeapon()
{
    FindWeaponTypeInInventory();
}

std::vector<Item *> &Player::getInventory()
{
    return Inventory;
}
