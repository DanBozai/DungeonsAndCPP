#include "Scenes.h"

void ForestScene(Player *&playerPtr)
{

    std::cout << "You entered in Forest" << std::endl;
    if (chestScene())
    {
        playerPtr->CreateWeaponItem();
        playerPtr->equipWeapon();
    }
    Enemy *Monster =CreateEnemy();
    playerAttackAnimation(playerPtr, Monster);

    EnemyAttackAnimation(Monster,playerPtr);
    delete Monster;
}

void VillageScene(Player *&playerPtr)
{
    std::cout << "You entered in Village" << std::endl;
    if (chestScene())
    {
        playerPtr->CreateWeaponItem();
        playerPtr->equipWeapon();
    }
    Enemy *Monster =CreateEnemy();
    playerAttackAnimation(playerPtr, Monster);

    EnemyAttackAnimation(Monster,playerPtr);
    delete Monster;
}

void CaveScene(Player *&playerPtr)
{
    std::cout << "You entered in Cave" << std::endl;

    if (chestScene())
    {
        playerPtr->CreateWeaponItem();
        playerPtr->equipWeapon();
        std::cout<< playerPtr->getPlayerAttack();
    }
    Enemy *Monster =CreateEnemy();
    playerAttackAnimation(playerPtr, Monster);

    EnemyAttackAnimation(Monster,playerPtr);
    delete Monster;
}

bool chestScene()
{
    bool IsValid = false;
    std::string askPlayerIfOpenChest;
    std::cout << "In front of you is a chest. Do you want to open?\n";
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

void CrossRoadsScene(Player *&playerP)
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
        ForestScene(playerP);
    }
    else if (askTravel == "2" || askTravel == "Village" || askTravel == "village")
    {
        CleanTerminal();
        VillageScene(playerP);
    }
    else if (askTravel == "3" || askTravel == "Cave" || askTravel == "cave")
    {
        CleanTerminal();
        CaveScene(playerP);
    }
}

