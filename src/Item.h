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
    Item(std::string item_name, int itemType);
    virtual ~Item();
    void getItemName();
    int getIdWeaponType();

    virtual int getWeaponAttack();

private:
    const int idTypeItem;
    std::string itemName;

protected:
};

#endif