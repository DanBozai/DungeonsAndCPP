#include "Weapon.h"

Weapon::Weapon(std::string item_name):Item(item_name)
{
std::cout<< "Weapon Crea\n";
}

Weapon::~Weapon()
{
std::cout<< "Weapon Dest\n";

}