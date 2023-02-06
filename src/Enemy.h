#ifndef ENEMY_H
#define ENEMY_H

#pragma once
#include <iostream>
#include <string>
#include <vector>

class Enemy
{
public:
    Enemy();
    virtual ~Enemy();
    virtual void printEnemyName();
    virtual void printEnemyAttack();
private:
const std::string enemyName;


};

#endif