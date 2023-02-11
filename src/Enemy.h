#ifndef ENEMY_H
#define ENEMY_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>

enum EnemyType
{
    OrcType = 1,
    TrollType,
    GoblinType

};
class Enemy
{
public:
    Enemy(std::string enemy_name,int baseAttackEnemy,int baseHealthEnemy, std::string AttackAnimationName);
    virtual ~Enemy();
    virtual void printEnemyName();
    int Attack();
    int generateRandomEnemy();
    std::string getAnimationName();
    void EnemyAppear();
    
private:
    const std::string AnimationTextFileName;

protected:
    const std::string enemyName;
    int enemyHealth;
    int enemyAttack;

    enum EnemyBaseHealth
    {
        OrcHealth=600,
        GoblinHealth=700,
        TrollHealth=1000
    };
    enum EnemyBaseAttack
    {
        OrcAttack=50,
        GoblinAttack=65,
        TrollAttack=95,
    };
};

#endif