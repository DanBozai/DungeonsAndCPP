#include <iostream>
#include "Misc.h"
#include "Scenes.h"
#include "Item.h"
#include "Sword.h"
#include "Orc.h"
#include "Goblin.h"
#include "Troll.h"

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
    MainMenuMusic.setLoop(true);
    std::cout << MainMenuMusic.getLoop();

    Player *player = nullptr;
    if (IntroText())
    {
        MainMenuMusic.play();

        player = SetupPlayer();
        MainMenuMusic.stop();
        CrossRoadsScene(player);
    }

    else
    {
    }

    std::cout << "Quit Game\n";
    system("pause");

    for (auto Item : player->getInventory())
    {
        InventoryClean(Item);
    }
    delete player;
    return 0;
}
