#include <iostream>
#include <string> 
#include "Monster.h"
#include "Player.h"
using namespace std; 

//have definitions for functions associated with
//any type of monster, both base class and 
//inherited class.

//set name of monster 
void Monster::setName(std::string n)
{
  name = n;
}
//get name of monster 
std::string Monster::getName()
{
  return name; 
}

//set strength of monster 
void Monster::setStrength(int i){
  strength = i;
}

//return strength of monster 
int Monster::getStrength(){
  return strength;
} 
  
//monster battle with player 
void Monster::battle(Player& p)
{
  //saves player's current strength into temp variable
  int temp = p.getStrength();
  //while player or monster are not dead 
  while (p.getStrength() > 0 && getStrength() > 0)
  {
    //attacks occur 
    attack(p);
    getAttacked(p);

  }
  //if player's strength reaches 0
  if (p.getStrength() <= 0)
  {
    
    cout << "You lost the battle against the monster. You manage to escape from the monster despite your severe injuries.\n" << endl;
    //the battle is lost but the player does not
    //lose the game completely. they suffer a hit
    //to their strength level due to injuries. 
    p.setStrength(temp - 5);
  }
  else 
  {
    //the monster is defeated and the player 
    //gains strength as a reward. 
    cout << "The monster has been defeated. You are one step closer to seeing her again.\n" << endl; 
    p.setStrength(temp + 5); 
  }
}

// specific monster taunts/dialogue with the player
void Departed::taunt()
{
  cout << "The Departed says: “You really think you'll ever see her again? She's probably one of us by now.”\n" << endl; 
}

//attack function for departed
//decreases player strength by 10 and prints their new strength
void Departed::attack(Player& p)
{
  int temp = p.getStrength() - 10;
   p.setStrength(temp); 
   if (p.getStrength() < 0)
   {
     cout << "Your strength level has reached 0." << endl;
   }
   else 
   {
     cout << "Your strength level is: " << p.getStrength() << endl; 
   }
}

//departed gets attacked and loses 15 strength
void Departed::getAttacked(Player& p)
{
  cout << "You attack the Departed." << endl;
  int temp = getStrength() - 15;
  setStrength(temp);
}

//specific taunt function for mutant
void Mutant::taunt()
{
  cout << "The Mutant says: “You're gonna look uglier than me after this battle.”\n" << endl;
}

//specific attack function for mutant- player loses 5 strength
void Mutant::attack(Player& p)
{
  int temp = p.getStrength() - 5;
   p.setStrength(temp); 
   if (p.getStrength() < 0)
   {
     cout << "Your strength level has reached 0." << endl;
   }
   else 
   {
     cout << "Your strength level is: " << p.getStrength() << endl; 
   }
}

//mutant gets attacked and loses 15 strength
void Mutant::getAttacked(Player& p){
  cout << "You attack the mutant." << endl;
  int temp = getStrength() - 15;
  setStrength(temp);
}

//specific taunt function for robo
void Robo::taunt()
{
  cout << "The Robo says: “Feeling is so overrated, by the time I'm done with you, you'll despise those feelings! Bzzt! Bzzt!”\n" << endl;
}

//robo causes player to lose 15 strength
void Robo::attack(Player& p)
{ 
  int temp = p.getStrength() - 15;
  p.setStrength(temp); 
  if (p.getStrength() < 0)
   {
     cout << "Your strength level has reached 0." << endl;
   }
   else 
   {
     cout << "Your strength level is: " << p.getStrength() << endl; 
   }
  
}

//robo loses 15 strength
void Robo::getAttacked(Player &p)
{
  int temp = getStrength() - 15;
  setStrength(temp);
  cout << "The robo is attacked. System malfunction." << endl;
}