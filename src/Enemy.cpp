#include "Enemy.h"
/// @brief 
/// @param enemy_name string parameter for enemy name
/// @param baseAttackEnemy int type parameter for the base Attack enemy(should be declared in enum EnemyBaseAttack)
/// @param baseHealthEnemy int type parameter for the base Health enemy(should be declared in enum EnemyBaseHealth)
/// @param AttackAnimationName string type parameter for text file wich contains the ASCII draw note: all the text file should be written like "classNameAttack (" and the .txt file need to be included in the build directory like "classNameAttack (index).txt", index will be called in the playerAttackAnimation(Player *&player, Enemy *&en) function wich contains the int index and concatenated with std::tostring() and increment the index 


Enemy::Enemy(std::string enemy_name, int baseAttackEnemy, int baseHealthEnemy, std::string AttackAnimationName) : AnimationTextFileName(AttackAnimationName), enemyAttack(baseAttackEnemy), enemyHealth(baseHealthEnemy), enemyName(enemy_name)
{
}

Enemy::~Enemy()
{
}
/// @brief getter method for enemyName attribute (declared private access)
/// @return  string type value  
std::string Enemy::getEnemyName()
{
    return enemyName;
}
/// @brief getter method for enemyAttack attribute (declared in private access)
/// @return int value type
int Enemy::Attack()
{
    return enemyAttack;
}
/// @brief display a message with the enemy name  
void Enemy::EnemyAppear()
{
    std::cout << "The " << enemyName << " appear in front of you!\n";
}
/// @brief getter method for enemy Health (declared in protected enum EnemyBaseHealth)
/// @return int value 
int Enemy::getEnemyHp()
{
    return enemyHealth;
}
/// @brief getter method for the enemyAttack attribute( declared in protected access)
/// @return int type value
int Enemy::getEnemyAttack()
{
    return enemyAttack;
}
/// @brief generate a random number which corresponds with the value in enum enemyType
/// @return int type value 
int Enemy::generateRandomEnemy()
{

    std::random_device rd;
    std::mt19937 gen(rd());
    // insert the lowest and the higher number from enum enemyType
    std::uniform_int_distribution<> distribNum(OrcType, GoblinType);
    int randomNumber = distribNum(gen);

    return randomNumber;
}
/// @brief getters for the enemy name animation which contains the 
/// @return AnimationTextFileName string for animation text.file (return exemple "OrcdAttack (" / "TrollAttack (" )
std::string Enemy::getNameAnimation()
{
    return AnimationTextFileName;
}
