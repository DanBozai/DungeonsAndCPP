#include "Sword.h"

Sword::Sword(std::string item_name):Item(item_name,SwordType)
{
std::cout<< "Sword Crea\n";

}

Sword::~Sword()
{
std::cout<< "Sword Dest\n";

}

int Sword::getWeaponAttack()
{
    return SwordAttack;
}