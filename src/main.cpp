#include <iostream>
#include <SFML/Audio.hpp>
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

    sf::Music music;
    music.openFromFile("Main_Menu.wav");
    music.setVolume(60);

    Player *player = nullptr;
        if (IntroText())
    {
        music.play();

        player = SetupPlayer();
        std::cout << player->getPlayerType() << std::endl;
        CrossRoadsScene(player, player->getInventory());
    }

    else
    {
        music.stop();
    }

    std::cout << "Clear Memory\n";
    system("pause");

    for (auto Item : player->getInventory())
    {
        InventoryClean(Item);
    }
    return 0;
}
