#include "Scenes.h"

/// @brief present the forest scene and the player find a chest and the battle scene will start
/// @param playerPtr pointer reference for to player instance
/// @param musicP reference to the music (if want to stop and play another music)
void ForestScene(Player *&playerPtr, sf::Music &musicP)
{

    std::cout << "You entered in Forest" << std::endl;
    if (chestScene())
    {
        playerPtr->CreateWeaponItem();
        playerPtr->equipWeapon();
        system("pause");
    }
    BattleScene(playerPtr, musicP);
}
/// @brief present the Village scene and the player find a chest and the battle scene will start
/// @param playerPtr  pointer reference to the player instance
/// @param musicP reference to the music (if want to stop and play another music)
void VillageScene(Player *&playerPtr, sf::Music &musicP)
{
    std::cout << "You entered in Village" << std::endl;
    if (chestScene())
    {
        playerPtr->CreateWeaponItem();
        playerPtr->equipWeapon();
        system("pause");
    }
    BattleScene(playerPtr, musicP);
}
/// @brief present the Cave scene and the player find a chest and the battle scene will start
/// @param playerPtr  pointer reference to the player instance
/// @param musicP reference to the music (if want to stop and play another music)
void CaveScene(Player *&playerPtr, sf::Music &musicP)
{

    std::cout << "You entered in Cave" << std::endl;

    if (chestScene())
    {
        playerPtr->CreateWeaponItem();
        playerPtr->equipWeapon();
        system("pause");
    }
    BattleScene(playerPtr, musicP);
}
/// @brief the battle music and the fight mechanics will begin
/// @param playerPtr pointer reference to the player instance
/// @param musicP reference to the music (if want to stop and play another music)
/// @return boolean type value based the winner (true if player overpower the enemy)
bool BattleScene(Player *&playerPtr, sf::Music &musicP)
{
    /// stop the exploring music
    musicP.stop();
    // start the battlemusic
    sf::Music BattleMusic;
    BattleMusic.openFromFile("BattleFinal.wav");
    BattleMusic.setVolume(50);
    BattleMusic.setLoop(true);
    BattleMusic.play();

    bool battleResult = false;
    // create an enemy
    Enemy *Monster = CreateEnemy();
    // setup the player and the monster health
    int playerHp = playerPtr->getPlayerHealth();
    int monsterHp = Monster->getEnemyHp();

    do
    {
        // start the visual animation
        playerAttackAnimation(playerPtr, Monster);
        // decrease the monster health
        monsterHp -= playerPtr->getPlayerAttack();
        //
        std::cout << "You attacked the " << Monster->getEnemyName() << " with " << playerPtr->getPlayerAttack() << " damage\n";
        std::cout << Monster->getEnemyName() << " HP " << monsterHp << "/" << Monster->getEnemyHp() << "\n";
        system("pause");
        if (monsterHp <= 0)
        {
            std::cout << "You won!"
                      << "\n";
            battleResult = true;
            break;
        }
        // start the enemy animation
        EnemyAttackAnimation(Monster, playerPtr);
        playerHp -= Monster->getEnemyAttack();
        // display the enemy damage
        std::cout << "The " << Monster->getEnemyName() << " attacked you with " << Monster->getEnemyAttack() << " damage\n";
        // display your remaining health and max health
        std::cout << " Your HP " << playerHp << "/" << playerPtr->getPlayerHealth() << "\n";
        system("pause");

        if (playerHp <= 0)
        {
            std::cout << "Defeat \n";
            battleResult = false;
            break;
        }
    } while (!playerHp <= 0 || monsterHp <= 0);
    // after the fight stop the music
    BattleMusic.stop();
    // delete the enemy instance from the heap
    delete Monster;
    return battleResult;
}
/// @brief asks player if want to open the chest
/// @return boolean type value
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
        std::cout << "The chest will open\n";
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
/// @brief start the music and ask player where wants to go, based on the answer will start the next scene
/// @param playerP plaier pointer reference
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
