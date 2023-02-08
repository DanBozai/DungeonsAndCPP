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

void Player::playAnimation()
{
    std::chrono::milliseconds ms(15);

    const std::string filename = "WarriorAttack (";
    std::string dynamicFileName;
    int indexNum = 1;

    for (int i = 1; i <= 105; i++)
    {
        std::string index = std::to_string(indexNum);

        dynamicFileName += filename;
        dynamicFileName += index;
        openTextFile(dynamicFileName);
        index.clear();
        dynamicFileName.clear();
        std::this_thread::sleep_for(ms);
        system("CLS");
        indexNum++;
    }
}

void Player::equipWeapon()
{
    FindWeaponTypeInInventory();
}

void Player::openTextFile(std::string &file_name)
{
    std::string line;
    std::string d_fileName = file_name + ").txt";
    std::ifstream file(d_fileName);

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::cout << line << "\n";
        }
        file.close();
    }
}

std::vector<Item *> &Player::getInventory()
{
    return Inventory;
}
