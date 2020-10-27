#include "Game.h"
#include "Dialogue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

Game::Game(Player p, Map m, Dialogue d){
  player = p;
  map = m;
  dialogue = d;

  //print game title and creator names
  cout << "------------------------------------------" << endl;
  cout << "JOURNEY TO HER" << endl;
  cout << "By Anthony Ndunda, Zarsha Mian and Louisa Izydorczak" << endl;
  cout << "------------------------------------------" << endl;

  //asks user for their name 
  string name;
  cout << "Enter your name to begin your journey." << endl;
  cin >> name;
  player.setName(name);
  cout << endl; 

  // Main Menu when the game begins
  // Gives choice to start new game or load a game 
  int beginningChoice; 
  cout << "MAIN MENU: " << endl;
  cout << "1. Start new journey." << endl;
  cout << "2. Load saved journey." << endl; 
  cout << "Press the number corresponding to your choice." << endl; 
  cin >> beginningChoice; 

  //while invalid input 
   while (beginningChoice != 1 && beginningChoice != 2)
   {
     //user is asked to try again 
     cout << "Try again. (1/2)" << endl;
     cin >> beginningChoice; 
     cout << endl; 
   }
      cout << "------------------------------------------" << endl;
  //if user input is 1 
  //a new game is started 
   if (beginningChoice == 1)
   {
     //play new game 
     gameLoop(); 
   }
   //if user input is 2 
   //an existing game is loaded 
   if (beginningChoice == 2)
   {
     //load existing game 
     loadGame(); 
     //play existing game 
     gameLoop(); 
   }

}

//loop that contains all
//game code 
void Game::gameLoop()
{ 
  //prints opening sequence 
  dialogue.printOpening();
  cout << "Hurry, " << player.getName() << ". Find her before it's too late. " << endl;  
  
  //get user input to begin game
  char start = 'a';
  while(start != 'b')
  { 
    cout << "Type 'b' to begin your journey." << endl;
    cin >> start;
  }
  
   cout << "------------------------------------------" << endl;
  //while player is not dead
  //aka while player's strength or motivation > 0
  while (player.getStrength() > 0 && 
  player.getMotivation() > 0 && player.getDidWin() == false)
  {
    //player rolls the dice 
    //moves them to new position on map
    player.diceRoll();

    //if position reaches end of game board, the player wins the game 
    if (player.getPosition() > MAP_SIZE)
      {
        player.setDidWin(true);
        break; 
      } 
    //show sneak peek of upcoming spots on map 
    map.showSneakPeek(player.getPosition(), player.getVision());
    //reset vision once you've peeked (vision chip temporarily increases vision so this resets it to normal)
    player.setVision(12);

    //return the letter inside the map
    //at the player's current location 
    int temp = player.getPosition();
    char letter = map.getMapCharAt(temp);
  
    
    //switch statement based on map's letter 
    switch (letter)
    {
      case 'T':
      //player finds treasure based on random number 
      player.findTreasure();
      cout << "------------------------------------------" << endl; 
      break;
      case 'H':
      //player encounters a human
      Human h;
      //pseudo-randomize whether the human is good or bad based on whether player's position is even or odd 
      if (player.getPosition() % 2 == 0)
      {
        //good human helps player
        h.setIsHelpful(true);
        h.help(player);
        cout << "------------------------------------------" << endl; 
      }
      else 
      {
        //bad human steals from player
        h.setIsHelpful(false);
        h.steal(player);
        cout << "------------------------------------------" << endl; 
      }
      break;
      //flashback dialogue is output; no effect on player's stats 
      case 'F':
      {
        cout << "A memory overwhelms you..." << endl; 
        dialogue.flashback();
        cout << "------------------------------------------" << endl; 
        cout << endl; 
        break; 
      }
      case 'M':
      {
      //initializes market, lets player buy items   
      cout << "You stumble upon a market selling microchips." << endl;
      Market m;
      m.initializeMarket();
      m.displayItems();
      cout << "Do you want to buy anything? (y/n)" << endl;
      char choice;
      cin >> choice;
      //loop so player can buy any number of items they want
      while (choice != 'n')
      {
        if (choice == 'y'){
          player.buyItemFromMarket(m);
        cout << "Anything else? (y/n)" << endl;
        }
        else{
          cout << "Try again. (y/n)" << endl;
        }
        cin >> choice;
      }
      cout << "You leave the market. Hopefully you found something useful.\n" << endl;
      cout << "------------------------------------------" << endl; 
      break;
      }
      case 'B':
      {
      //encounter a monster 
      dialogue.printMonsterAttack();
      
      //create the monster 
      Departed d;
      d.setName("Departed");
      d.setStrength(50);
      Mutant m;
      m.setName("Mutant");
      m.setStrength(15);
      Robo r;
      r.setName("Robo");
      r.setStrength(30);

      //different monster attacks based on player's position 
      if (player.getPosition() % 3 == 0)
      {
      dialogue.addMonsterHits(d);
      dialogue.printMonsterHit();
      d.taunt();
      d.battle(player);
      cout << "------------------------------------------" << endl; 
      }
      else if (player.getPosition() % 3 == 1)
      {
        dialogue.addMonsterHits(m);
        dialogue.printMonsterHit();
        m.taunt();
        m.battle(player);
        cout << "------------------------------------------" << endl; 
      }
      else 
      {
        dialogue.addMonsterHits(r);
        dialogue.printMonsterHit();
        r.taunt(); 
        r.battle(player);
        cout << "------------------------------------------" << endl; 
      }
      break;
      }
      default:
      cout << "Something went wrong." << endl;
      break;
    } 
    //show user options. 
    //options: see health (strength, motivation) 
    //or see inventory (money, items)
    //or use item
    //or continue
    userInput(); 
  }
    //at end of while loop, closing sequence is printed based on user's stats (did they win? did they lose all their strength or motivation?)
    dialogue.printClosing(player); 
}

//gives user choices to view their stats and use items from their inventory 
void Game::userInput()
{

  int choice = 0; 
  //while the user does not choose to continue their journey, display the menu
  while (choice != 6)
  {
  cout << "Check in on yourself, " << player.getName() << "." << endl;
  cout << "------------------------------------------" << endl; 
  cout << "1. View your health." << endl;
  cout << "2. View your inventory." << endl;
  cout << "3. View your available cash." << endl;
  cout << "4. Use an item from inventory." << endl;
  cout << "5. Save your game." << endl; 
  cout << "6. Continue your journey. " << endl;
  cout << "7. Quit your game." << endl;
  cout << endl;
  cout << "Enter the number corresponding to your choice." << endl;
  cin >> choice; 
  cout << endl; 
  
  //performs action based on user input 
  switch (choice)
  {
    case 1:
    // shows the current health status of the player to the user
      cout << "Your current health status. \n" << endl;
      cout << "=============================" << endl;
      cout << "Strength level: " << player.getStrength() << endl;
      cout << "Motivation level: " << player.getMotivation() << endl; 
      cout << endl; 
      break;
    case 2:
    // gives the user a look into the player's current inventory
      player.getInventory();
      break;
    case 3:
      //gives user a look into available cash
      cout << "Available cash: $" << player.getCash() << endl;
      cout << endl; 
      break;
    case 4:
    // checks the user inventory, if there are items in the player's inventory, the user can use an item of their choice, if not, it will print out that there are no available items in the inventory
      int secondChoice;
      player.getInventory();
      if (player.getPlayerItems().size() == 0)
      {
        cout << "You have no items in your inventory to use.\n" << endl;
      }
      else
      {
      cout << "Enter the number corresponding to the item you would like to use." << endl;
      cin >> secondChoice; 
      player.useItem(player.getPlayerItems()[secondChoice - 1]);
      }
      break;
    case 5:
      saveGame();
      char userInput; 
      cout << "Press 'q' to quit. Press 'c' to continue your game.\n" << endl;
      cin >> userInput;
      while(userInput != 'q' && userInput != 'c')
      {
        cout << "Try again. (q/c)" << endl;
        cin >> userInput; 
      }
      if (userInput == 'q')
      {
        exit(3);
      }
      else if (userInput == 'c')
      {
        cout << "------------------------------------------" << endl;
        break;
      }
      break; 
    case 6:
    // continue to the next turn 
      cout << "You continue on your journey. Every moment is critical." << endl; 
      cout << "------------------------------------------" << endl; 
      break;
    case 7:
      //get user confirmation that they want to quit without saving
      char quit;
      cout << "Do you want to quit the game without saving? Press y for yes, or press n to save before quitting." << endl;
      cin >> quit;
      while (quit != 'y' && quit != 'n')
      {
        cout << "Try again. (y/n)" << endl;
        cin >> quit; 
      }
      
      if (quit == 'y')
      {
        exit(3);
      }
      else if (quit == 'n')
      {
        saveGame();
        exit(3);
      }



      break; 
    default:
    break;
  }
  }
}


void Game::saveGame()
{
  cout << "You tire of your journey and stop to take a rest.\n " << endl;

  //sets the name of the file we're saving to 
  string filename = player.getName() + ".txt";

  //open an empty file of that name 
  ofstream outfile;
  outfile.open(filename, ofstream::trunc);

  //first, we'll save the player's stats 
  outfile << player.getName() << endl; 
  outfile << player.getStrength() << endl;
  outfile << player.getMotivation() << endl;
  outfile << player.getCash() << endl;
  outfile << player.getPosition() << endl;
  outfile << player.getSpeed() << endl;
  outfile << player.getVision() << endl;

  //playerItems vector needs to be saved into the outfile 
  outfile << player.getNumItems() << endl;
  for (int i = 0; i < player.getNumItems(); i++)
  {
    string temp = "";
    temp += player.getPlayerItems()[i].getName();
    outfile << temp << endl; 
    temp = "";
    temp += to_string(player.getPlayerItems()[i].getPrice());
    outfile << temp << endl; 
    temp = "";
    temp += to_string(player.getPlayerItems()[i].getNumOfUsesLeft());
    outfile << temp << endl; 
  }

  //next, we'll save the letters from the map so we can reuse it later
  //save letters from existing map into a temporary string 
  string mapLetters;
  ifstream infile;
  infile.open("Map.txt");
  getline(infile, mapLetters);
  infile.close(); 

  //we save that string into the outfile 
  outfile << mapLetters << endl; 

  //last, we'll save the vector items from flashbacks 
  int size = dialogue.getFlashbacks().size(); 
  outfile << size << endl; 
  for (int i = 0; i < size; i++)
  {
    string temp = "";
    temp += dialogue.getFlashbacks()[i]; 
    outfile << temp << endl; 
  }


  outfile.close(); 
  cout << "Your progress has been saved to the file " << filename << ".\n" << endl; 
  cout << "------------------------------------------" << endl; 
}

//load a saved game
void Game::loadGame()
{
  //set filename to the player's name + .txt
  string filename = player.getName() + ".txt";
  ifstream infile;

  //open the file
  infile.open(filename);
  //if you don't open the file, print a message before the game aborts
  if(infile.fail())
  {
  cout << "You have no existing journey to load. The game will now be aborted." << endl; 
  }

  //temporary variable
  string temp = "";

  //read in player's name from file and set it 
   getline(infile, temp);
    player.setName(temp);
    
  //read in player strength 
  getline(infile, temp);
  player.setStrength(stoi(temp));

  //read in player's motivation
  temp = "";
  getline(infile, temp);
  player.setMotivation(stoi(temp));
  
  //read in a player's cash
  temp = "";
  getline(infile, temp);
  player.setCash(stoi(temp));

  //read in a player's position
  temp = "";
  getline(infile, temp);
  player.setPosition(stoi(temp));
  
  //speed 
  temp = "";
  getline(infile, temp);
  player.setSpeed(stoi(temp));
  
  //vision
  temp = "";
  getline(infile, temp);
  player.setVision(stoi(temp));

  // getting the number of items saved to the file
  temp = "";
  getline(infile, temp);
  // temp = stoi(temp); //an int of how many items there are
  for (int i = 0; i < stoi(temp); i++)
  {
    //temporary string variables to hold item characteristics
    string tempName = "";
    string tempPrice = "";
    string tempUses = "";
    //create a new Item 
    Item item;

    //read in name, price, and uses from file
    //and set values for item you created 
    getline(infile, tempName);
    item.setName(tempName);
    getline(infile,tempPrice);
    item.setPrice(stoi(tempPrice));
    getline(infile, tempUses);
    item.setNumOfUsesLeft(stoi(tempUses));
    //add the item to the player's inventory
    player.addItem(item);
  }

      //next, we'll read in the map from the file
    //and fill in the mapArray with the letters
    getline(infile, temp);
    array<char, MAP_SIZE> mapArray; 
    for (int i = 0; i < MAP_SIZE; i++)
    {
      mapArray[i] = temp[i];
    }
    map.setMapArray(mapArray);

    //lastly, we need to load in the vector of flashbacks 
    //so flashback vector is filled before loadGame is called
    //so we can remove flashbacks we don't want 

    //initially clear vector of all flashbacks 
    dialogue.getFlashbacks().clear(); 

    //read in number of flashbacks from file 
    temp = "";
    getline(infile, temp);
    int numFlashbacks = stoi(temp);

    //for each flashback in the file,
    //save it in an index for the vector 
    //distinguish flashbacks from each other because they are separated by double new lines 
    for (int i = 0; i < numFlashbacks; i++)
    {
      temp = ""; 
      while (!temp.find("\n\n"))
      {
        string addingString = ""; 
        getline(infile, addingString);
        temp += addingString;
      }
      //push into vector 
      dialogue.getFlashbacks().push_back(temp);
    }

    cout << "You decide to continue your previous journey." << endl; 
    
  //close the file
  infile.close(); 
}