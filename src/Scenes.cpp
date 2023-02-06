#include "Scenes.h"

void ForestScene(Player *&playerPtr, std::vector<Item *> &inventoryPtr)
{

    std::cout << "You entered in Forest" << std::endl;
    if (chestScene())
    {
        AddWeaponToInventory(playerPtr, inventoryPtr);
    }
    BattleScene();
}

void VillageScene(Player *&playerPtr, std::vector<Item *> &inventoryPtr)
{
    std::cout << "You entered in Village" << std::endl;
    if (chestScene())
    {
        AddWeaponToInventory(playerPtr, inventoryPtr);
    }
    BattleScene();

}

void CaveScene(Player *&playerPtr, std::vector<Item *> &inventoryPtr)
{
    std::cout << "You entered in Cave" << std::endl;

    if (chestScene())
    {
        AddWeaponToInventory(playerPtr, inventoryPtr);
    }
    BattleScene();

}

bool chestScene()
{
    bool IsValid = false;
    std::string askPlayerIfOpenChest;
    std::cout << "In front of you is a chest. Do you want to open it?\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No\n";

    std::cin >> askPlayerIfOpenChest;
    if (askPlayerIfOpenChest == "1" || askPlayerIfOpenChest == "Yes" || askPlayerIfOpenChest == "yes")
    {
        std::cout << "You open the chest\n";
        IsValid = true;
    }
    else
    {
        IsValid = false;
    }
    return IsValid;
}

void CleanTerminal()
{
    system("CLS");
}

void CrossRoadsScene(Player *&playerP, std::vector<Item *> &inventoryPtr)
{
    std::string askTravel;

    std::cout << "You are at crossroads, where you want to go?\n";
    std::cout << "1. Forest\n";
    std::cout << "2. Village\n";
    std::cout << "3. Cave\n";
    std::cin >> askTravel;

    if (askTravel == "1" || askTravel == "Forest" || askTravel == "forest")
    {
        CleanTerminal();
        ForestScene(playerP, inventoryPtr);
    }
    else if (askTravel == "2" || askTravel == "Village" || askTravel == "village")
    {
        CleanTerminal();
        VillageScene(playerP, inventoryPtr);
    }
    else if (askTravel == "3" || askTravel == "Cave" || askTravel == "cave")
    {
        CleanTerminal();
        CaveScene(playerP, inventoryPtr);
    }
}

void BattleScene()
{
    int monsterId = generateRandomNum();
    Enemy *ptrEnemy = nullptr;
    switch (monsterId)
    {
    case 1:
        ptrEnemy = new Orc();
        break;
    case 2:
        ptrEnemy = new Troll();

        break;
    case 3:
        ptrEnemy = new Goblin();

        break;
    default:
        break;
    }

    ptrEnemy->printEnemyName();
    ptrEnemy->printEnemyAttack();
    delete ptrEnemy;
}