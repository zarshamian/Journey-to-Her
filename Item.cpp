#include "Item.h"
using namespace std;
    
//sets name of item 
void Item::setName(string n)
{
  name = n; 
}

//returns name of item 
string Item::getName() const
{
  return name; 
}

//sets price of item
void Item::setPrice(int i)
{
  price = i;
}

//returns price of item 
int Item::getPrice() const{
  return price;
}

void Item::setNumOfUsesLeft(int i)
{
  numOfUsesLeft = i;
}

//get number of times an item can be used 
int Item::getNumOfUsesLeft()
{
  return numOfUsesLeft;
}