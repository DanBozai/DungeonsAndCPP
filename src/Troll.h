#ifndef TROLL_H
#define TROLL_H

#pragma once
#include "Enemy.h"
class Troll:public Enemy
{
public:
    Troll();
    ~Troll();
    virtual void printEnemyName() override;
    virtual void printEnemyAttack() override;


private:
const std::string enemyName;
const unsigned int Attack=5;

};

#endif