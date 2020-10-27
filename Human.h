#pragma once
#include <vector>
#include "Player.h"

class Human
{
  public:
    //sets and gets if human is helpful. 
    void setIsHelpful(bool b);
    bool getIsHelpful();
    //human affects player based on whether they are good or evil 
    void steal(Player& p);
    void help(Player& p);

  private:
    bool isHelpful;
};