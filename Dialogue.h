#pragma once
#include <vector>
#include <string>
#include "Monster.h"
#include "Player.h"


class Dialogue{
  private:
  //vectors of dialogues 
    std::vector<std::string> flashbacks;
    std::vector<std::string> openingAndClosingSequences;
    std::vector<std::string> monsterAttacks;
    std::vector<std::string> monsterHits;
    
  public:
  //output flashback to console 
   void flashback();
   //get flashbacks
   std::vector<std::string> getFlashbacks();
   //add a flashback to the vector 
   void addFlashBacksToVector();
   //add introduction and all potential story endings 
   void addOpeningAndClosingSequences(); 
   //print opening sequence
   void printOpening();
    //print closing sequence 
    void printClosing(Player&); 

   //adds random scenarios of monster attacks to vector 
   void addMonsterAttacks(); 
   void printMonsterAttack(); 

   //random moves the monster makes in battle 
  void addMonsterHits(Monster& monster);
  void printMonsterHit(); 
};
