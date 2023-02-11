#include "Enemy.h"

Enemy::Enemy(std::string enemy_name, int baseAttackEnemy,int baseHealthEnemy, std::string AttackAnimationName) : AnimationTextFileName(AttackAnimationName), enemyAttack(baseAttackEnemy),enemyHealth(baseHealthEnemy), enemyName(enemy_name)
{
}

Enemy::~Enemy()
{
}

void Enemy::printEnemyName()
{
    std::cout << enemyName << std::endl;
}

int Enemy::Attack()
{
    return enemyAttack;
}

void Enemy::EnemyAppear()
{
    std::cout << "The " << enemyName << " appear in front of you!\n";
}

int Enemy::generateRandomEnemy()
{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribNum(OrcType, GoblinType);
    int randomNumber = distribNum(gen);

    return randomNumber;
}

std::string Enemy::getAnimationName()
{
    return AnimationTextFileName;
}
