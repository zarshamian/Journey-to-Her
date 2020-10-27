#pragma once
#include <string>

//base class 
class Item
{
  public:
  //set and get name of item 
    void setName(std::string n); 
    std::string getName() const;

    //set and get price of item 
    void setPrice(int i);
    int getPrice() const; 

    //set and get number of uses left for item 
    void setNumOfUsesLeft(int i);
    int getNumOfUsesLeft();

  private:
    std::string name; 
    int price; 
    int numOfUsesLeft;

};
