#include "Dagger.h"

Dagger::Dagger(std::string item_name):Item(item_name,DaggerType)
{
std::cout<< "Dagger Crea\n";

}

Dagger::~Dagger()
{
std::cout<< "Dagger Dest\n";

}