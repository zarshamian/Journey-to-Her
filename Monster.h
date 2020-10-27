#pragma once
#include "Player.h"
//only 3 monsters right now but could change this number in the future
const int NUM_MONSTERS = 3;

class Monster
{
  private: 
  int strength; 
  std::string name;
  

  public:
  void setName(std::string n);
  std::string getName(); 
  void setStrength(int i);
  int getStrength();
  virtual void attack(Player& p) = 0;
  virtual void getAttacked(Player& p) = 0;
  void battle(Player& p);

};

//similar to a zombie- dead human that stuck around 
class Departed : public Monster
{
  private:
  public:
  void taunt();
  void attack(Player& p);
  void getAttacked(Player& p);
  
};

// experimented on person that was at some point a human but the experiment went wrong
class Mutant : public Monster
{
  private:
  public:
  void taunt();
  void attack(Player& p);
  void getAttacked(Player& p);
};

//half human half robot
class Robo : public Monster
{
  private: 
  public:
  void taunt();
  void attack(Player& p); 
  void getAttacked(Player& p);
};