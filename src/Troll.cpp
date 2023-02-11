#include "Troll.h"

Troll::Troll():Enemy("Troll",TrollAttack,TrollHealth,"TrollAttack (")
{

}

Troll::~Troll()
{

}

void Troll::printEnemyName()
{
    std::cout<<enemyName<<std::endl;
    
}


