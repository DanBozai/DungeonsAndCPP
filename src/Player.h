#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include <iostream>
#include <string>
#include "Weapon.h"
#include "Item.h"

class Player
{
public:
    Player(std::string name);
    virtual ~Player();
    void getName();
    void checkInventory(std::vector<Item*> &Inventory);

private:

    virtual void Attack();
    const std::string m_name;
    
    std::vector<Item*> inv;
   
protected:

};

#endif