#pragma once
#include "Player.h"
#include "Monster.h"
#include "Human.h"
#include "Market.h"
#include "Map.h"
#include "Item.h"
#include <string>
#include "Dialogue.h"

class Game
{
  public:
  //constructor 
    Game(Player, Map, Dialogue);
    //contains game code 
    void gameLoop();
    //lets user view their stats, use items in inventory 
    void userInput();
    //saves game to a text file 
    void saveGame();
    //loads a saved game from a text file 
    void loadGame();
    Player player;
    Map map;
    Dialogue dialogue;
};