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
    Enemy();
    virtual ~Enemy();
    virtual void printEnemyName();
    virtual void printEnemyAttack();
    int generateRandomEnemy();

private:
    const std::string enemyName;
};

#endif