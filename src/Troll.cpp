#include "Troll.h"

Troll::Troll():enemyName("Troll"),Enemy("TrollAttack (")
{
    std::cout<< "Troll Crea\n";

}

Troll::~Troll()
{
    std::cout<< "Troll Dest\n";

}

void Troll::printEnemyName()
{
    std::cout<<enemyName<<std::endl;
    
}

void Troll::printEnemyAttack()
{
    std::cout<< enemyName<<" attacks you with "<< Attack <<" power!\n";
}