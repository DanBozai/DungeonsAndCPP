#ifndef ITEM_H
#define ITEM_H

#pragma once
#include <iostream>
#include <string>
#include <vector>

class Item
{
public:
    Item(std::string item_name);
    virtual ~Item();
    void getItemName();

private:
    std::string itemName;
    
};

#endif