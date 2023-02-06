#include "Sword.h"

Sword::Sword(std::string item_name):Weapon(item_name)
{
std::cout<< "Sword Crea\n";

}

Sword::~Sword()
{
std::cout<< "Sword Dest\n";

}