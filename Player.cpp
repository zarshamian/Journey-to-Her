#include "Player.h"
#include "Map.h"
#include "Market.h"
#include <random>
#include <chrono>
#include <functional>
#include <vector>

//using a random number generator 
auto seed = static_cast<default_random_engine::result_type>( chrono::high_resolution_clock::now().time_since_epoch().count() );

auto engine = default_random_engine(seed);

//get a random int 1 to 6
auto genDice = bind(uniform_int_distribution<>{1, 6}, engine);

//sets name of player 
void Player::setName(string n)
{
  name = n; 
}

//gets name of player
string Player::getName() const
{
  return name; 
}

//set strength of player 
void Player::setStrength(int s) {
  strength = s;
}

//return strength of player 
int Player::getStrength(){
  return strength;
} 

//return whether or not player's strength is zero
bool Player::isDead(){
  if (strength <= 0){
    return true;
  }
  return false;
} 


//return player position 
int Player::getPosition()
{
  return position;
} 

// set a player's position on the map 
void Player::setPosition(int pos)
{
  position = pos;
} 

// set the player's available cash
void Player::setCash(int i)
{
  cash = i;
}

// get the cash 
int Player::getCash()
{
  return cash; 
}

//set a player's motivation level
void Player::setMotivation(int i)
{
  motivation = i;
}

//return player's motivation level
int Player::getMotivation()
{
  return motivation; 
}

//set the speed of the player to given int
void Player::setSpeed(int i )
{
  speed = i;
}

//return speed of player
int Player::getSpeed()
{
  return speed; 
}

//set vision of player to a given int
void Player::setVision(int i)
{
  vision = i;
}

//return vision of player
int Player::getVision()
{
  return vision; 
}

//set whether the player has won yet
void Player::setDidWin(bool b)
{
  didWin = b; 
}

//get whether the player has won yet
bool Player::getDidWin()
{
  return didWin; 
}

//get the number of items in the player's inventory
int Player::getNumItems()
{
  return playerItems.size();
}

//remove the last item from the player's inventory (used when a theft occurs)
void Player::removeItem()
{
  playerItems.pop_back();
}

//get the vector of items in a player's inventory
vector<Item> Player::getPlayerItems(){
  return playerItems;
}

//using a random number generator to get an int 1 to 6 and add it to the player's positon (or end game if player moves off board)
void Player::diceRoll()
{
  //get a random roll
  int roll = genDice();
  //multiply the roll by the player's speed to get the distance they will travel
  int rollAtSpeed = roll * speed;
  //set the player's new position 
  setPosition(position + rollAtSpeed);
  //if the player passes the end of the map print how far they travel and that they have 0 miles left to go
  if ((MAP_SIZE - getPosition()) <= 0)
  {
    cout << "You travel " << rollAtSpeed << " miles with 0 miles left to go. You reach your destination." << endl; 
  }
  //otherwise print how far they travel and calculate how far they have to go still to reach their destination
  else 
  {
  cout << "You travel " << rollAtSpeed << " miles with " << MAP_SIZE - getPosition() << " miles left to go." << endl;
  }
    cout << "------------------------------------------" << endl; 
  //restore speed to one after a turn
  speed = 1;
}

//add a given item to the player's inventory
void Player::addItem(Item i)
{
  playerItems.push_back(i);
}

//use an item in the player's inventory
void Player::useItem(Item& i)
{
  if (i.getName() == "Strength Chip")
  {
    //perform the strength increase here
    setStrength(getStrength() + 20);
    cout << "You insert the Strength Chip into the slot in the back of your neck. You watch your injuries fade away as if they had never been there at all. You feel renewed.\n" << endl;
    
  }
  else if (i.getName() == "Memory Chip")
  {
      //set motivation to a higher number aka increase it
      setMotivation(getMotivation() + 20);
      //cout statement here about her memories
      cout << "You inject the Memory Chip into the slot in the back of your neck. A montage of your deeply buried memories of her play before your eyes as you continue to trek ahead.\n" << endl; 
      
  }
  else if (i.getName() == "Speed Chip")
  {
    
    //sets speed to double in order to move
    //twice as many spots on the board 
    cout << "Feeling increasingly anxious about the length of the journey ahead, you decide to use your Speed Chip. You gain the ability to travel twice as far.\n" << endl; 
      setSpeed(2); 
      
      
    
  }
  else if (i.getName() == "Vision Chip")
  {
    cout << "To better plan your route, you decide to use your Vision Chip. You hope to avoid any monsters on your way.\n" << endl; 
    //increase vision for sneak peek by two 
     setVision(getVision() * 2);
       
  }
  
    // when an item is used, the number of uses left for that item decreases, and if that item runs out, it gets removed from the inventory as well.

    for (int j = 0; j < playerItems.size(); j++)
    {
      if (playerItems[j].getName() == i.getName())
      {
        playerItems[j].setNumOfUsesLeft(playerItems[j].getNumOfUsesLeft() - 1);

        //removes the item from inventory once it has ran out
        if (playerItems[j].getNumOfUsesLeft() < 1)
        {
         cout << "You use your " << i.getName() << ". It is removed from your inventory.\n" << endl;
        playerItems.erase(playerItems.begin() + (j));
        }
        break;
      }  
    }
}

//allow the player to buy an item from a given market
void Player::buyItemFromMarket(Market& m)
{
  //get a choice from the player
  int choice; 
  cout << "Choose the corresponding number of the item you would like to buy." << endl;
  cin >> choice;

// checks if player has enough cash to purchase the item chosen, if so subtracts cash from the player's available cash 

  if (getCash() >= m.getMarket()[choice - 1].getPrice())
    {
      addItem(m.getMarket()[choice - 1]); 
      setCash(getCash()-m.getMarket()[choice - 1].getPrice());
    }
  else 
  {
    cout << "You don't have enough cash to purchase this item." << endl; 
  }
  
}

// shows the player's inventory on the console. This includes the items available and how many uses each item has left

std::vector<Item> Player::getInventory()
{
  cout << "Player Inventory: " << endl; 
  for (int i = 0; i < playerItems.size(); i++)
  {
    
    cout << i + 1 << ".) Item: " << playerItems[i].getName() <<
    " Uses Left: " << playerItems[i].getNumOfUsesLeft() << endl;
  }
  cout << endl; 
  return playerItems;
}

// when the player lands on a treasure spot on the map, the player will find a treasure based on a dice rolled by the game in the background

void Player::findTreasure()
{
  int roll = genDice();
  switch (roll)
  {
    case 1:
    {
      cout << "$100 are lying in the middle of the road. You'll be able to afford a meal tonight.\n" << endl;
      setCash(getCash() + 100);
      break;
    }
    case 2:
    {
      cout << "You find a daisy. She loved daisies. Loves daises.\n" << endl; 
      // increase the player's motivation
      setMotivation(getMotivation() + 10);
      break;
    }
    case 3:
    {
      cout << "You find a Memory Chip while walking along a obscured pathway. You decide to save it. The memory of her singing will help you fall asleep on a sleepless night.\n" << endl; 
      Item i;
      i.setName("Memory Chip");
      i.setPrice(75);
      i.setNumOfUsesLeft(1);
      addItem(i);
      break;
    }
     case 4:
     {
      cout << "You come across an old apple orchard. You decide it's worth the risk to sneak in and steal some apples. You feel stronger after eating some.\n" << endl; 
      setStrength(getStrength() + 15);
      break;
     }
    case 5:
    {
      cout << "You find a Speed Chip. You ignore the traces of blood on it. You put it in your bag. \n" << endl;
      Item i;
      i.setName("Speed Chip");
      i.setPrice(100);
      i.setNumOfUsesLeft(3);
      addItem(i);
      break;
    }
    case 6:
    {
      cout << "You steal a Vision Chip from an older stranger while they are not looking. You can hear her scolding you in your head.\n." << endl;
      Item i;
      i.setName("Vision Chip");
      i.setPrice(80);
      i.setNumOfUsesLeft(3);
      addItem(i);
      break;
    }
    default:
      cout << "You find nothing.\n" << endl;
      break;
  }

}