#include "Rod.h"

Rod::Rod(std::string item_name):Item(item_name,RodType)
{
std::cout<< "Rod Crea\n";

}

Rod::~Rod()
{
std::cout<< "Rod Dest\n";

}

int Rod::getWeaponAttack()
{
    return rodAttack;
}