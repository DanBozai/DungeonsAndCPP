#include "Goblin.h"

Goblin::Goblin():enemyName("Goblin")
{
    std::cout<< "Goblin Crea\n";

}

Goblin::~Goblin()
{
    std::cout<< "Goblin Dest\n";

}

void Goblin::printEnemyName()
{
    std::cout<<enemyName<<std::endl;
    
}

void Goblin::printEnemyAttack()
{
    std::cout<< enemyName<<" attacks you with "<< Attack <<" power!\n";
    
}