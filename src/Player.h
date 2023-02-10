#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include <iostream>
#include <string>

#include <chrono>
#include <thread>
#include "Item.h"
#include "Sword.h"
#include "Rod.h"
#include "Dagger.h"

enum playerTypeClass
{
    WizardType = 1,
    WarriorType = 2,
    RogueType = 3
};
class Player
{
public:
    Player(std::string name, int classType,std::string AttackAnimationName);
    virtual ~Player();


    void getName();
    std::vector<Item *> &getInventory();
    void addItemToInventory(Item *item);
    int getPlayerType();
    Item *CreateWeaponItem();
    virtual std::string getNameAnimation();
    void equipWeapon();
    

private:
    const int idTypePlayerClass;
    unsigned int Health;
    virtual void Attack();
    const std::string m_name;

    std::vector<Item *> Inventory;
    Item *WeaponSlot=nullptr;
    const std::string AnimationTextFileName;
    void FindWeaponTypeInInventory();
    

protected:
};

#endif
