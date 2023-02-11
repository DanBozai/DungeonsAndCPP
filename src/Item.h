#ifndef ITEM_H
#define ITEM_H

#pragma once
#include <iostream>
#include <string>
#include <vector>

enum WeaponTypeClass
{
    RodType = 1,
    SwordType,
    DaggerType
};

class Item
{
public:
    Item(std::string item_name, int itemType, int itemAttack);
    virtual ~Item();
    void getItemName();
    int getIdWeaponType();

    int getWeaponAttack();

private:
    const int idTypeItem;
    std::string itemName;
    const int weaponAtk;

protected:
    enum WeaponAttack
    {
        SwordBaseAtk = 120,
        RodBaseAtk = 150,
        DaggerBaseAtk = 200

    };
};

#endif