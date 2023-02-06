#include "Orc.h"

Orc::Orc() : enemyName("Orc")
{
    std::cout << "Orc Crea\n";
}

Orc::~Orc()
{
    std::cout << "Orc Dest\n";
}

void Orc::printEnemyName()
{
    std::cout<<enemyName<<std::endl;
    
}

void Orc::printEnemyAttack()
{
    std::cout<< enemyName<<" attacks you with "<< Attack <<" power!\n";
    
}