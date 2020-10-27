/*
Final C++ Project created by 
Anthony, Louisa, and Zarsha
during the last week of training.
October 19 - October 23, 2020 
*/

#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"
#include "Market.h"
#include "Human.h"
#include "Game.h"
using namespace std;

int main() {

  //instantiates map
   Map m; 
   //randomly fills map
   m.fillMap();
   //reads from text file 
   m.createMap(); 
  
  Player p;

  //instantiates Dialogue
  //adds all dialogues that 
  //will be output during
  //game 
   Dialogue d;
   d.addFlashBacksToVector();
   d.addOpeningAndClosingSequences();
   d.addMonsterAttacks();

  // //game constructor 
   Game g(p, m, d);
  

}