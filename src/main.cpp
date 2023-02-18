#include <iostream>
#include "Misc.h"
#include "Scenes.h"
#include "Item.h"
#include "Sword.h"
#include "Orc.h"
#include "Goblin.h"
#include "Troll.h"
/// @brief delete items instances
/// @param invPtr Item pointer reference  
void InventoryClean(Item *&invPtr)
{
    delete invPtr;
}
int main()
{
    sf::Music ExplorationMusic;
    sf::Music MainMenuMusic;
    MainMenuMusic.openFromFile("Main_Menu.wav");
    MainMenuMusic.setVolume(50);
    //replay music 
    MainMenuMusic.setLoop(true);

    Player *player = nullptr;
    if (IntroText())
    {
        MainMenuMusic.play();

        player = SetupPlayer();
        //after the setupPlayer function ends stop the main_menu music and in crossroads function will call the Exploring music
        MainMenuMusic.stop();
        CrossRoadsScene(player);
    }

    else
    {

    }

    std::cout << "Quit Game\n";
    system("pause");
    //delete inventory instances created on the heap memory
    for (auto Item : player->getInventory())
    {
        InventoryClean(Item);
    }
    delete player;
    return 0;
}
