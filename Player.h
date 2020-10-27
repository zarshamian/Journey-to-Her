#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Market.h"

using namespace std;

class Player
{
  private:
  //attributes of the player that are initialized to their values at the start of the game 
  string name;
  int strength = 30; 
  int motivation = 5; 
  int cash = 500; 
  int position = 0; 
  int speed = 1;
  int vision = 12;
  bool didWin = false;

  // empty vector of playerItems, filled as the player collects items through their journey
  vector<Item> playerItems; 
  

  public: 
  // getters and setters for player's name
  void setName(string n);
  string getName() const;

  // getter and setter for players strength
  void setStrength(int s);
  int getStrength(); 

  // getter and setter for the cash 
  void setCash(int i);
  int getCash();

  // determines if player is still alive
  bool isDead(); 

  // gets and sets the players position on the map
  int getPosition(); 
  void setPosition(int pos);

  // sets the players motivation attribute
  void setMotivation(int i);
  int getMotivation(); 

  // gets and sets the players speed attribute
  void setSpeed(int i);
  int getSpeed();

  // gets and sets the players vision attribute
  void setVision(int i);
  int getVision();

  // gets and sets the determination of the player winning the game
  void setDidWin(bool b);
  bool getDidWin(); 

  // function to buy from the market
  void buyItemFromMarket(Market& m);
  std::vector<Item> getInventory();
  int getNumItems();
  void removeItem();
  vector<Item> getPlayerItems();

  // player rolling dice function 
  void diceRoll(); 

  
  void findTreasure();

  void addItem(Item i); 
  void useItem(Item& i);
};