#include <iostream>
#include <vector>
#include "Market.h"
#include "Item.h"
using namespace std;

 
//add a new item to the vector marketItems given its name, price and number of uses
void Market::addItemToMarket(string newName, int newPrice, int newNumOfUsesLeft)
{
  Item i;
  i.setName(newName);
  i.setPrice(newPrice);
  i.setNumOfUsesLeft(newNumOfUsesLeft);

  //add to vector 
  marketItems.push_back(i);
}

//initialize market with different items 
void Market::initializeMarket()
{
  addItemToMarket("Strength Chip", 60, 1);
  addItemToMarket("Memory Chip", 75, 1);
  addItemToMarket("Vision Chip", 80, 3);
  addItemToMarket("Speed Chip", 100, 3);
}

//display market on console 
void Market::displayItems()
{
  for (int i = 0; i < marketItems.size(); i++)
  {
    cout << "------------------------------------------" << endl;
    cout << i + 1 << ".) " << "Market item: " << marketItems[i].getName() << endl; 
    cout << "Price: " << marketItems[i].getPrice() << endl;
    cout << "Number of Uses: " << marketItems[i].getNumOfUsesLeft() << endl;
    
  }
  cout << "------------------------------------------" << endl;
}

//return market items 
std::vector<Item> Market::getMarket()
{
  return marketItems; 
} 