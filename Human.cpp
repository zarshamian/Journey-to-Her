#include "Human.h"
#include "Player.h"
#include "Item.h"
#include <iostream>
#include <string> 
#include <random>
#include <chrono>
#include <functional>
using namespace std;

//using a random number generator 
 auto seed2 = static_cast<default_random_engine::result_type>( chrono::high_resolution_clock::now().time_since_epoch().count() );

 auto engine2 = default_random_engine(seed2);

// //get a random int 1 to 6
 auto genDice2 = bind(uniform_int_distribution<>{1, 6}, engine2);

//sets whether or not a human is helpful 
void Human::setIsHelpful(bool b)
{
  isHelpful = b; 
}

//returns true or false 
bool Human::getIsHelpful()
{
  return isHelpful;
}

// steal from the player (meant for evil humans)
void Human::steal(Player& p)
{
  int roll = genDice2(); 
  //different outcome based on random number 
  switch (roll)
  {
    case 1:
    {
      cout << "You regret having trusted a stranger. After all you've seen, you should have known better. You frantically search your bag, but all of your money is gone.\n" << endl;
      p.setCash(0); //sets player cash to 0 
      break;
    }
    case 2:
    {
      cout << "Your only photo of her is stolen by a stranger. You don't know how much longer you'll be able to recall the delicate features of her face. You lose your will to continue.\n" << endl; 
      // decrease the player's motivation
      p.setMotivation(p.getMotivation() - 5);
      break;
    }
    case 3:
    {
      cout << "After your interaction with a stranger, your bag feels lighter than before. You feel no surprise.\n" << endl; 
      //remove item from inventory or remove $100 
      if (p.getNumItems() > 0){
        p.removeItem();
      }
      else {
        p.setCash(p.getCash() - 100);
      }
      break;
    }
     case 4:
     {
      cout << "You're attacked by a stranger trying to steal from you. He looks half starved. You're able to fight him off, but not without some injuries.\n" << endl; 
      //decrease player strength 
      p.setStrength(p.getStrength() - 40);
      break;
     }
    case 5:
    {
      cout << "Desperate from hunger, you eat some mysterious food given to you by a stranger. You feel sick and your vision is blurry. Your strength dwindles away.\n" << endl;
      //decrease player strength 
      p.setStrength(p.getStrength() - 35);
      break;
    }
    case 6:
    {
      cout << "A stranger tells you to stop looking for her. How does he know about her? Is this all a dream? You don't know how much longer you can go on.\n" << endl;
      //decreases player motivation 
      p.setMotivation(p.getMotivation() - 5);
      break;
    }
    default:
      cout << "A human says nothing to you. He looks crazed.\n" << endl;
      break;
  }

}

//help the given player
void Human::help(Player& p)
{
  int roll = genDice2(); 
  //perform different action based on random number 
  switch (roll)
  {
    case 1:
    {
      cout << "A stranger offers you $50 in exchange for some information. Maybe he's searching for someone too.\n" << endl;
      //add cash to player 
      p.setCash(p.getCash() + 50);
      break;
    }
    case 2:
    {
      cout << "A stranger smiles warmly at you. You haven't seen a smile like that in ages. It reminds you of her smile.\n" << endl; 
      // increase the player's motivation
      p.setMotivation(p.getMotivation() + 5);
      break;
    }
    case 3:
    {
      cout << "A stranger offers you a Vision Chip after you share your water with them.\n" << endl; 
      //add vision chip to inventory 
      Item i;
      i.setName("Vision Chip");
      i.setPrice(80);
      i.setNumOfUsesLeft(3);
      p.addItem(i);
      break;
    }
     case 4:
     {
      cout << "You're offered a Strength Chip by a stranger after he sees your wounds. The look of pity on his face is unmistakeable.\n" << endl; 
      //add strength chip to player inventory 
      Item i;
      i.setName("Strength Chip");
      i.setPrice(60);
      i.setNumOfUsesLeft(1);
      p.addItem(i);
      break;
     }
    case 5:
    {
      cout << "A stranger invites you to an underground bunker to celebrate a long forgotten holiday. You're in luck! There's amazing food and you eat to your heart's content. You wish she was here.\n" << endl;
      //increase strength 
      p.setStrength(p.getStrength() + 10);
      break;
    }
    case 6:
    {
      cout << "You see two strangers laughing together. You can't forget, you're doing all of this so that you can have that again. With her.\n" << endl;
      //increase motivation 
      p.setMotivation(p.getMotivation() + 10);
      break;
    }
    default:
      cout << "A stranger looks at you with kind eyes.\n" << endl;
      break;
  }

}
