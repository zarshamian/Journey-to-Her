#include "Dialogue.h"
#include "Monster.h"
#include "Player.h"
#include <vector> 
#include <iostream>
#include <random>
#include <chrono>
#include <functional>
using namespace std;

int NUM_FLASHBACKS = 15;
int NUM_MONSTER_ATTACKS = 6;
int NUM_MONSTER_HITS = 5;

//random number generator
auto seed3 = static_cast<default_random_engine::result_type>( chrono::high_resolution_clock::now().time_since_epoch().count());

 auto engine3 = default_random_engine(seed3);

//get a random int 1 to num flashbacks
 auto gen1toNumFlashbacks = bind(uniform_int_distribution<>{1, NUM_FLASHBACKS}, engine3);

// get a random int to number of monster attacks
  auto gen1toNumMonsterAttacks = bind(uniform_int_distribution<>{1, NUM_MONSTER_ATTACKS}, engine3);

  // get a random int to number of monster hits
  auto gen1toNumMonsterHits = bind(uniform_int_distribution<>{1, NUM_MONSTER_HITS}, engine3);

//cout a random flashback string from the vector of flashbacks and erase it from the vector so that it can't be used again
void Dialogue::flashback()
{
  //if random number is 
  //greater than number of 
  //available flashbacks,
  //choose last flashback
  //in vector 
  int i = gen1toNumFlashbacks();
  if (i > NUM_FLASHBACKS)
  {
    i = NUM_FLASHBACKS; 
  }
  //outputs flashback 
  string fb = flashbacks[i - 1];
  cout << fb;
  //erases flashback from 
  //vector to avoid repeats 
  flashbacks.erase(flashbacks.begin() + (i - 1));
  NUM_FLASHBACKS -= 1;
}

vector<string> Dialogue::getFlashbacks(){
  return flashbacks;
}

//prints opening sequence 
void Dialogue::printOpening()
{
  cout << openingAndClosingSequences[0] << endl;
}

//fill up vector with all 15 flashbacks
void Dialogue::addFlashBacksToVector()
{
  flashbacks.push_back("You hear word of a sanctuary far from here. You hesitate. It is worth the risk to leave the cottage to get the medicine she needs? Seeing no other way to save her life, you decide to try.\n\n");

  flashbacks.push_back("“If we ever get separated, you’ll wait for me at the cottage in the woods. Promise me,” you remember asking her on a night of rain and cold wind.\n\n.You remember the confused look on her face. “We’ll never be apart, you know that. I’ll go with you anywhere you go.” Her innocence made you smile. \n\nYou notice now that she never promised.\n\n");
    
  flashbacks.push_back("Before he is turned, before he becomes the monster he despises, he asks you for a promise.\n\n'Stay with her. If anything ever happens to me, you’ll stay with her. Protect her. You only have each other in this world.' \n\nYou promise, not realizing you will fail to keep it.\n\n");  

  flashbacks.push_back("You think about a night long before the Lost War, before the world was invaded by monsters and Departed and Robos.\n\nA night with her, sitting on the swings at a park. A night of meaningless conversation, competing to see who could swing the highest. You hear her laugh in your mind even after the memory fades away.\n\n"); 
  
  flashbacks.push_back("Today is her birthday. You remember last year,the glow from the candles in her eyes and the way she scrunched them closed while she made a wish.\n\nYou wonder what she’s wishing for today, all alone in the cottage. If she’s even there.\n\n");

  flashbacks.push_back("The full moon makes you think about a night on the run together. Watching the stars, talking about a future you might never see. Making plans for tomorrow, and the next day. Together.\n\n");

  flashbacks.push_back("You enter her garden, the place she goes when she wants to be alone. You have seen it grow from a single daisy to the large plot in front of you. Working in her garden helps her forget, and watching her work helps you forget, too. If only for a little while.\n\n");

  flashbacks.push_back("You hear her sleepy voice in your ear, the way you have so many times before.\n\nYou smile as you wake. You open your eyes, but you don’t see her. Realization hits you as you gain consciousness. Her absence pierces your heart. You must get back to her.\n\n");
  
  flashbacks.push_back("You use the last of the remaining medical supplies to stitch the gash on her leg. The infection spreads, causing her temperature to rise at an alarming rate. You think through your options, you don’t know what to do. You curse yourself for not protecting her, for not fulfilling your promise.\n\n");

  flashbacks.push_back("You notice the food supply is running low. You offer her your last cupcake, the store bought kind she loved before all of the destruction. She gives you a smile that makes all your hunger go away.\n\n");
  
  flashbacks.push_back("She isn’t as excited as you expected after hearing about the rumored sanctuary. She wears devastation on her face, clear as day, at the idea of you leaving her behind.\n\nYou explain to her that she can’t travel in her state, that she would slow you down. She reluctantly agrees, and says she’ll wait for you.\n\n");

  flashbacks.push_back("In the quiet of the night, you try to recreate her singing in your mind to fill the empty silence. She sings the song you both share, quietly when she thinks you’re not listening. But you always listen. The sound fills you with hope.\n\n");

  flashbacks.push_back("He tells you to hide after hearing some sounds in the distance. You say you won't leave him to fight alone. You watch as he is turned into the very thing he hates, the very monster he protects you from. You grab her hand and run as fast as you can. You never look back.\n\n");

  flashbacks.push_back("The cold overwhelms you. You hope you’re able to reach your destination soon. You see the toll the journey takes on her, and see the wince she tries to hide from you with each step. Her Robo injury is worse than she wants you to realize, but you see her struggle. You would do anything to take her pain away.\n\n");
  
  flashbacks.push_back("You feel your heart beat out of your chest as you see the Robo approach, gaze fixated on her. You move to save her, but you’re not fast enough.\n\nThe Robo’s laser cuts through her thigh, and the sound of her scream is deafening. Blind with rage, you grab the rock near you and smack the Robo’s circuit.\n\nYou carry her to safety, the sounds of her pained cries filling your ears the whole way.\n\n");
}

//adds opening and closing 
//sequences to vector 
void Dialogue::addOpeningAndClosingSequences()
{
  openingAndClosingSequences.push_back("The year is 2075. In a world overrun by monsters, the human population is small and scattered. Following the Lost War, many have banded together to continue the rebellion. Others fight day after day to stay alive. Watching their loved ones become Departed has made them cruel. Acts of kindness are scarce but those alone in the world vow to help those in need, the way they wish they had been helped.\n\nIn an abandoned cottage hidden deep in the woods, she waits for you. You have been gone longer than you promised. You must find her.\n\nAlong your journey, you will battle monsters (B), have the opportunity to buy supplies at underground markets (M), interact with other humans (H), find treasure (T), and experience flashbacks (F) of her.\n\n");

  openingAndClosingSequences.push_back("You see the abandoned cottage within view. You run to it, feeling the weight of the past few weeks lift from your shoulders with each step.\n\nSurrounding trees partly obscure the cottage from view. As you get closer, you notice smoke leaving the chimney, but not enough to draw attention. Your heart beats out of your chest.\n\nOpening the door, you step inside, tracking mud behind you. You hear the faint sound of her singing. You follow the sound to the end of the hall, into what used to be the room you shared.\n\nHer back is turned as she continues to hum a song you know all too well. As the sound of your footsteps, she turns to you. As your eyes meet, you see a smile begin to overtake her face.\n\nGAME OVER.\n");

  openingAndClosingSequences.push_back("As you walk along a long forgotten path, your vision begins to blur. You stop and abruptly lean against a tree for support. You are so tired. You see the abandoned cottage within view. Like a person stranded in the desert in search for water, you realize it’s simply an illusion. Still, you blink a few times in an effort to maintain the illusion for as long as possible.\n\n.Sadness creeps in, as you realize you will never make it back to her. Leaned against the tree, all alone, far from home, you feel your body temperature drop. Your heart rate slows, until it eventually stops altogether.\n\nGAME OVER\n");

  openingAndClosingSequences.push_back("You see a daisy on the path in front of you. You wait for feelings of longing to surface, but none do.\n\nYou begin to battle with yourself. What is all this pain and suffering for? Who is it for? You stop in your tracks, and you take a moment to rethink your plan. Your memories of her are more distant than they have ever been.\n\nYou steel yourself, and you turn around. You walk back the way you came. You never look back.\n\nGAME OVER.\n");

}

//prints different closing 
//sequence based on whether 
//or not user won the game 
void Dialogue::printClosing(Player& p)
{
  string temp = "";
  //if statement that chooses which ending
  //is printed 

  if (p.getDidWin() == true)
  {
    temp = openingAndClosingSequences[1];
  }
  else if (p.getDidWin() == false && p.getStrength() <= 0)
  {
    temp = openingAndClosingSequences[2];
  }
  //if motivation is 0 when the player loses 
  else
  {
    temp = openingAndClosingSequences[3];
  }
    cout << temp << endl; 

}

//adds monster attack scenarios
//to vector 
void Dialogue::addMonsterAttacks()
{
    monsterAttacks.push_back("You are grabbed by something behind you. It pulls on your neck harshly, and throws you to the ground.\n\n");

    monsterAttacks.push_back("You hear rustling in the bushes. You stop in your tracks and try to see what is hiding there. A monster jumps out at you.\n\n");

    monsterAttacks.push_back("A loud crash wakes you from your shallow sleep. You startle, looking in every direction for the source of the noise. A monster jumps on top of you.\n\n");

    monsterAttacks.push_back("The sun beats down on you as you continue on a deserted path. Without any warning, a monster stands before you and wraps its hand around your neck.\n\n");

    monsterAttacks.push_back("As you walk along a deserted path, you get the strange sense that you are not alone. You turn slowly, and see nothing amiss. As you face forward, there's a flash before your eyes. A monster gazes at you intently.\n\n");

    monsterAttacks.push_back("As you stop to take a drink from your canteen, it is knocked violently from your hands. The reflection of a monster looms in the puddle before you.\n\n");
}

//prints a random monster attack 
void Dialogue::printMonsterAttack()
{
  int i = gen1toNumMonsterAttacks();
  string ma = monsterAttacks[i - 1];
  cout << ma;
  
}

//adds monster hits to vector 
void Dialogue::addMonsterHits(Monster& monster)
{
  //clear vector originally 
  monsterHits.clear();
  //we decide which monster is in the string 
  string attack1 = "The " + monster.getName() + " slashes your arm violently.\n "; 
  monsterHits.push_back(attack1);

  string attack2 = "The " + monster.getName() + " attempts to paralyze you with its gaze.\n";
  monsterHits.push_back(attack2);

  string attack3 = "The " + monster.getName() + " makes an ear-splitting noise.\n";
  monsterHits.push_back(attack3);

  string attack4 = "The " + monster.getName() + " pins you to the ground. You are unable to breathe under its weight.\n "; 
  monsterHits.push_back(attack4);

  string attack5 = "The " + monster.getName() + " lunges at your chest at lightning speed.\n";
  monsterHits.push_back(attack5);
}

//prints random monster hit 
//during a battle 
void Dialogue::printMonsterHit()
{
  int i = gen1toNumMonsterHits();
  string mh = monsterHits[i - 1];
  cout << mh << endl; 
}