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
            // std::cout << line;
            // std::getline(file2, line2);
            // std::cout << line2;
        }
        file.close();
        file2.close();
    }
}

void playerAttackAnimation(Player *&player, Enemy *&enemy)
{
    std::chrono::milliseconds ms(1);
    // WarriorAttack 88
    // WizardAttack 83
    // GoblinAttack 71
    std::string filename = player->getNameAnimation();
    std::string waitFrame = enemy->getAnimationName();

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
void EnemyAttackAnimation(Enemy *&enemy, Player *&player)
{
    std::chrono::milliseconds ms(1);
    // WarriorAttack 88
    // WizardAttack 83
    // GoblinAttack 71
    std::string filename = enemy->getAnimationName();

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
