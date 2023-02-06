#ifndef ORC_H
#define ORC_H

#pragma once
#include "Enemy.h"

class Orc : public Enemy
{
public:
    Orc();
    ~Orc();
    virtual void printEnemyName() override;
    virtual void printEnemyAttack() override;


private:
const std::string enemyName;
const unsigned int Attack=5;

};

#endif