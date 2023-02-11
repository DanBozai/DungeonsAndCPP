#include "Orc.h"

Orc::Orc() : Enemy("Orc",OrcAttack,OrcHealth,"OrcAttack (")
{
}

Orc::~Orc()
{
}

void Orc::printEnemyName()
{
    std::cout<<enemyName<<std::endl;
    
}


