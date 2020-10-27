#pragma once
#include <vector> 
#include <string>
#include "Item.h"


class Market
{
  public:
    //show market items on console
    void displayItems();  
    //fill market with items
    void initializeMarket(); 
    //add item to market 
    void addItemToMarket(std::string newName, int newPrice, int newNumOfUsesLeft);
    //return market items 
    std::vector<Item> getMarket(); 

  private:
    std::vector<Item> marketItems;

};