#include "Player.h"

Player::Player(std::string name):m_name(name) 
{
    std::cout<<"Player Created\n\n";
    
    

}



Player::~Player()
{
    std::cout<<"Player Dest\n";
}

void Player::getName()
{
    std::cout<<m_name<<std::endl;
}

void Player::checkInventory(std::vector<Item*> &Inventory)
{   int i=1;
    std::cout<<"Your Inventory:\n";
    for(const auto& it:Inventory)
    {
        std::cout<< i<<". ";
        it->getItemName();
        i++;
    }
    
}



void Player::Attack()
{
    
}