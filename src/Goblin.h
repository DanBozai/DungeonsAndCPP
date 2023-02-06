#ifndef GOBLIN_H
#define GOBLIN_H

#pragma once
#include "Enemy.h"
class Goblin : public Enemy
{
public:
    Goblin();
    ~Goblin();
    virtual void printEnemyName() override;
    virtual void printEnemyAttack() override;


private:
    const std::string enemyName;
    const unsigned int Attack = 5;
};

#endif