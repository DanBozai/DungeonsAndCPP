#include "Goblin.h"

Goblin::Goblin():Enemy("Goblin",GoblinAttack,GoblinHealth,"GoblinAttack (")
{

}

Goblin::~Goblin()
{

}

void Goblin::printEnemyName()
{
    std::cout<<enemyName<<std::endl;
    
}


