#include "Enemy.h"

Enemy::Enemy()
{
    std::cout << "Enemy Crea\n";
}

Enemy::~Enemy()
{
    std::cout << "Enemy Dest\n";
}

void Enemy::printEnemyName()
{
    std::cout << enemyName << std::endl;
}

void Enemy::printEnemyAttack()
{
}

int Enemy::generateRandomEnemy()
{
    
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distribNum(OrcType, GoblinType);
        int randomNumber = distribNum(gen);

        return randomNumber;
    
}
