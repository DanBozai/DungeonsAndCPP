#include "Misc.h"
/// @brief present the story and ask the player if wants to play
/// @return  boolean type value (yes-continue, no-exit)
bool IntroText()
{
    std::string askPlayerWantToPlay;
    bool isValid = false;
    std::cout << "Intro Text.................................\n";
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
/// @brief welcome message, choose a name for the character and presents the classes he can choose (the created class is invoked with new operator)
/// @return player pointer object for the dynamicaly allocated object(created class)
Player *SetupPlayer()
{
    std::string playerName;
    std::string askPlayerClass;
    int characterClass = 0;
    Player *chooseClassCharacterPtr;

    ClearTerminal();
    std::cout << "Welcome!\n";

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
/// @brief open the .txt file which contains the ASCII drawn frame
/// @param attackerAnimationNameFile string  reference name for the attacker (preferably add the getter from the player/enemy ->getEnemyName())
/// @param theOneAttacked string  reference name for the attacker (preferably add the getter from the player/enemy ->getEnemyName())
void readAndPrintTextAnimation(std::string &attackerAnimationNameFile, std::string &theOneAttacked)
{

    std::string line;
    std::string d_fileName = attackerAnimationNameFile + ").txt";
    std::ifstream file(d_fileName);
    std::string firstFrameFileNameEnemy = theOneAttacked + "1).txt";
    std::string line2;
    std::ifstream file2(firstFrameFileNameEnemy);
    // std::system("pause");

    if (file.is_open())
    {
        while (std::getline(file, line))
        {

            if (firstFrameFileNameEnemy == "WarriorAttack (1).txt" || firstFrameFileNameEnemy == "WizardAttack (1).txt" || firstFrameFileNameEnemy == "RogueAttack (1).txt")
            {
                std::getline(file2, line2);

                std::cout << line2;

                std::cout << line;
            }
            else
            {
                std::cout << line;
                std::getline(file2, line2);
                std::cout << line2;
            }
            
        }
        file.close();
        file2.close();
    }
}
/// @brief get the string animation name from the instantiated class object and  with a for loop increment the index display animation 
/// @param player player pointer reference for the instantiated class object 
/// @param enemy enemy pointer reference for the instantiated class object
void playerAttackAnimation(Player *&player, Enemy *&enemy)
{
    std::chrono::milliseconds ms(10);

    // WarriorAttack 88
    // WizardAttack 83
    // GoblinAttack 71
    //get the animation name from the type instantiated class (exemple "WarriorAttack (" / "WizardAttack (" / "TrollAttack (")
    std::string attackerAnimationTxtName = player->getNameAnimation();
    std::string waitFrame = enemy->getNameAnimation();

    std::string dynamicFileName;

    int indexNum = 1;

    for (int i = 1; i <= 83; i++)
    {
        // convert the int indexNum to a string
        std::string index = std::to_string(indexNum);
        //concatenate the string from attackerAnimationTxtName
        dynamicFileName += attackerAnimationTxtName;
        //concatenate the index number (exemple "WarriorAttack (index value")
        dynamicFileName += index;
        //read and display the ASCII drawn characters from the .txt file
        readAndPrintTextAnimation(dynamicFileName, waitFrame);
        //clear the index string value
        index.clear();
        //clear the string input for the function
        dynamicFileName.clear();
        //pause time for the ms value to run animation more fluid
        std::this_thread::sleep_for(ms);
        //clear screen
        system("CLS");
        //increment the index for the number  
        indexNum++;
    }
}

void EnemyAttackAnimation(Enemy *&enemy, Player *&player)
{
    std::chrono::milliseconds ms(1);
    // WarriorAttack 88
    // WizardAttack 83
    // GoblinAttack 71
    std::string filename = enemy->getNameAnimation();

    std::string waitFrame = player->getNameAnimation();

    std::string dynamicFileName;
    int indexNum = 1;

    for (int i = 1; i <= 83; i++)
    {

        std::string index = std::to_string(indexNum);

        dynamicFileName += filename;
        dynamicFileName += index;
        readAndPrintTextAnimation(dynamicFileName, waitFrame);
        index.clear();
        dynamicFileName.clear();
        std::this_thread::sleep_for(ms);
        system("CLS");
        indexNum++;
    }
}


/// @brief class pointer function that creates instances on the heap
/// @return return a pointer to the created instance
Enemy *CreateEnemy()
{
    Enemy *ptrEnemy = nullptr;
    int monsterId = ptrEnemy->generateRandomEnemy();

    switch (monsterId)
    {
    case OrcType:
        ptrEnemy = new Orc();
        break;
    case TrollType:
        ptrEnemy = new Troll();

        break;
    case GoblinType:
        ptrEnemy = new Goblin();

        break;
    default:
        break;
    }
    if (ptrEnemy != nullptr)
    {
        ptrEnemy->EnemyAppear();
    }
    return ptrEnemy;
}
