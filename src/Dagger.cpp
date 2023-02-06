#include "Dagger.h"

Dagger::Dagger(std::string item_name):Weapon(item_name)
{
std::cout<< "Dagger Crea\n";

}

Dagger::~Dagger()
{
std::cout<< "Dagger Dest\n";

}