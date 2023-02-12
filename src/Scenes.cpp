#include "Scenes.h"

void ForestScene(Player *&playerPtr, sf::Music &musicP)
{

    std::cout << "You entered in Forest" << std::endl;
    if (chestScene())
    {
        playerPtr->CreateWeaponItem();
        playerPtr->equipWeapon();
    }
    BattleScene(playerPtr, musicP);
}

void VillageScene(Player *&playerPtr, sf::Music &musicP)
{
    std::cout << "You entered in Village" << std::endl;
    if (chestScene())
    {
        playerPtr->CreateWeaponItem();
        playerPtr->equipWeapon();
    }
    BattleScene(playerPtr, musicP);
}

void CaveScene(Player *&playerPtr, sf::Music &musicP)
{

    std::cout << "You entered in Cave" << std::endl;

    if (chestScene())
    {
        playerPtr->CreateWeaponItem();
        playerPtr->equipWeapon();
        BattleScene(playerPtr, musicP);
    }
}

bool BattleScene(Player *&playerPtr, sf::Music &musicParamB)
{
    musicParamB.stop();
    sf::Music BattleMusic;
    BattleMusic.openFromFile("BattleFinal.wav");
    BattleMusic.setVolume(50);
    BattleMusic.setLoop(true);
    BattleMusic.play();

    bool battleResult = false;
    Enemy *Monster = CreateEnemy();
    int playerHp = playerPtr->getPlayerHealth();
    int monsterHp = Monster->getEnemyHp();

    do
    {
        playerAttackAnimation(playerPtr, Monster);
        monsterHp -= playerPtr->getPlayerAttack();
        std::cout << "You attack " << Monster->printEnemyName() << " with " << playerPtr->getPlayerAttack() << " damage\n";
        std::cout << Monster->printEnemyName() << " HP " << monsterHp << "/" << Monster->getEnemyHp() << "\n";
        system("pause");
        if (monsterHp <= 0)
        {
            std::cout << "You won!"
                      << "\n";
            battleResult = true;
            break;
        }

        EnemyAttackAnimation(Monster, playerPtr);
        playerHp -= Monster->getEnemyAttack();

        std::cout << Monster->printEnemyName() << " attacked you with " << Monster->getEnemyAttack() << " damage\n";
        std::cout << " Your HP " << playerHp << "/" << playerPtr->getPlayerHealth() << "\n";
        system("pause");

        if (playerHp <= 0)
        {
            std::cout << "Defeat \n";
            battleResult = false;
            break;
        }
    } while (!playerHp <= 0 || monsterHp <= 0);
    BattleMusic.stop();
    delete Monster;
    return battleResult;
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
    sf::Music ExploringMusic;

    ExploringMusic.openFromFile("Exploring.wav");
    ExploringMusic.setVolume(50);
    ExploringMusic.setLoop(true);
    ExploringMusic.play();

    std::string askTravel;
    std::cout << "You are at crossroads, where you want to go?\n";
    std::cout << "1. Forest\n";
    std::cout << "2. Village\n";
    std::cout << "3. Cave\n";
    std::cin >> askTravel;

    if (askTravel == "1" || askTravel == "Forest" || askTravel == "forest")
    {
        CleanTerminal();
        ForestScene(playerP, ExploringMusic);
    }
    else if (askTravel == "2" || askTravel == "Village" || askTravel == "village")
    {
        CleanTerminal();
        VillageScene(playerP, ExploringMusic);
    }
    else if (askTravel == "3" || askTravel == "Cave" || askTravel == "cave")
    {
        CleanTerminal();
        CaveScene(playerP, ExploringMusic);
    }
}
