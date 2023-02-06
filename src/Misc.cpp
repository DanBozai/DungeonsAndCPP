#include "Misc.h"

bool IntroText()
{
    std::string askPlayerWantToPlay;
    bool isValid = false;
    std::cout << "Intro Text\n";
    std::cout << "Do you want to play?\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No\n";
    std::cin >> askPlayerWantToPlay;
    if (askPlayerWantToPlay == "Yes" || askPlayerWantToPlay == "yes" || askPlayerWantToPlay == "1")
    {
        isValid = true;
    }

    else if (askPlayerWantToPlay == "No" || askPlayerWantToPlay == "no")
    {
        std::cout << "Thank you!\n";
        isValid = false;
    }
    return isValid;
}
Player *SetupPlayer()
{
    std::string playerName;
    std::string askPlayerClass;
    int characterClass = 0;
    Player *chooseClassCharacterPtr;

    ClearTerminal();
    std::cout << "Bun venit in lumea fantastica\n";

    std::cout << "Choose a name for your character\n";
    std::cin >> playerName;
    ClearTerminal();
    std::cout << "What hero type you want to choose\n";
    std::cout << "1. Wizard\n";
    std::cout << "2. Warrior\n";
    std::cout << "3. Rogue\n";
    std::cin >> askPlayerClass;
    if (askPlayerClass == "Wizard" || askPlayerClass == "wizard" || askPlayerClass == "1")
    {
        ClearTerminal();
        chooseClassCharacterPtr = new Wizard(playerName);
    }
    else if (askPlayerClass == "Warrior" || askPlayerClass == "warrior" || askPlayerClass == "2")
    {
        ClearTerminal();
        chooseClassCharacterPtr = new Warrior(playerName);
    }
    else if (askPlayerClass == "Rogue" || askPlayerClass == "rogue" || askPlayerClass == "3")
    {
        ClearTerminal();
        chooseClassCharacterPtr = new Rogue(playerName);
    }

    return chooseClassCharacterPtr;
}

void ClearTerminal()
{

    system("CLS");
}

Weapon *AddWeaponToInventory(Player *playerPtr, std::vector<Item *> &inventory)
{
    Weapon *weapon = nullptr;
    if (typeid(*playerPtr) == typeid(Warrior))
    {
        Sword *swordPtr = new Sword("Warrior Sword");
        weapon = swordPtr;
        inventory.push_back(swordPtr);
    }
    else if (typeid(*playerPtr) == typeid(Rogue))
    {
        Dagger *DaggerPtr = new Dagger("Rogue Dagger");
        weapon = DaggerPtr;
        inventory.push_back(DaggerPtr);
    }
    else if (typeid(*playerPtr) == typeid(Wizard))
    {
        Rod *RodPtr = new Rod("Wizard Rod");
        weapon = RodPtr;
        inventory.push_back(RodPtr);
    }
    return weapon;
}

Weapon *FindWeaponTypeInInventory(Player* &playerPtr, std::vector<Item *> &inventory)
{
    Weapon *ptr = nullptr;
    if (typeid(*playerPtr) == (typeid(Warrior)))
    {
        for (auto it : inventory)
        {
            if (typeid(*it) == typeid(Sword))
            {
                ptr = dynamic_cast<Weapon*>(it);
            }
        }
    }
    else if (typeid(*playerPtr) == (typeid(Wizard)))
    {
        for (auto it : inventory)
        {
            if (typeid(*it) == typeid(Rod))
            {
                ptr = dynamic_cast<Weapon*>(it);
            }
        }
    }
    if (typeid(*playerPtr) == (typeid(Rogue)))
    {
        for (auto it : inventory)
        {
            if (typeid(*it) == typeid(Dagger))
            {
                ptr =dynamic_cast<Weapon*>(it);
            }
        }
    }

    return ptr;
}

int generateRandomNum()
{
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distribNum(1, 3);
    int randomNumber=distribNum(gen);
    
    return randomNumber;
}
