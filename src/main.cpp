#include <iostream>
#include "Misc.h"
#include "Scenes.h"
#include "Item.h"
#include "Weapon.h"
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

    Player *player = nullptr;
    Weapon *WeaponItem = nullptr;
    std::vector<Item *> Inventory;

    if (IntroText())
    {
        player = SetupPlayer();
        CrossRoadsScene(player, Inventory);
        WeaponItem = FindWeaponTypeInInventory(player, Inventory);
    }
    if (WeaponItem != nullptr)
    {
        WeaponItem->getItemName();
    }
    player->checkInventory(Inventory);

    std::cout << "Clear Memory\n";
    system("pause");

    for (auto Item : Inventory)
    {
        InventoryClean(Item);
    }
    delete player;
    return 0;
}
