#ifndef TROLL_H
#define TROLL_H

#pragma once
#include "Enemy.h"
class Troll : public Enemy
{
public:
    Troll();
    ~Troll();
    void printEnemyName() override;

private:
};

#endif