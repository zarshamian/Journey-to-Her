#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include <chrono>
#include <random>
#include <functional>
using namespace std;

auto seed4 = static_cast<default_random_engine::result_type>( chrono::high_resolution_clock::now().time_since_epoch().count() );

auto engine4 = default_random_engine(seed4);

//get a random int 1 to 5
auto gen1to5 = bind(uniform_int_distribution<>{1, 5}, engine4);

//function to randomly fill in the map with characters
void Map::fillMap()
{
  string myMapLetters = "";

  ofstream outfile; 
  //open file, and clear the current contents of the file before adding new content
  outfile.open("Map.txt", ofstream::trunc);
  //random number generator to add letters to string 
  for (int i = 0; i<MAP_SIZE; i++)
  {
    int temp = gen1to5();
    // randomly generated number is assigned to the possible locations on the map
    switch (temp)
    {
      case 1:
        myMapLetters += 'T';
        break;
      case 2:
        myMapLetters += 'H';
        break;
      case 3:
        myMapLetters += 'F';
        break;
      case 4:
        myMapLetters += 'M';
      case 5:
        myMapLetters += 'B';
        break;
      default:
      cout << "Map generation error." << endl;
      break;
      }
    }
  //write to file
  outfile << myMapLetters; 
  //close file
  outfile.close();
}

//will read in from text file to 
//create the map 
void Map::createMap(){
  string myMapText; 

  //reads from file 
  ifstream infile; 
  infile.open("Map.txt");
  getline(infile, myMapText);
  infile.close();
  //fills elements of array with characters 
  //from file 
  for (int i = 0; i < MAP_SIZE; i++)
  {
    mapArray[i] = myMapText[i];
  }

}

void Map::setMapArray(array<char, MAP_SIZE> a)
{
  mapArray = a;
}

//show the next (int vision) elements of the mapArray based on the current position
void Map::showSneakPeek(int position, int vision){ 
    cout << endl; 
    cout << "Up ahead, you see...\n";


  for (int i = position + 1; i < position + vision + 2; i++)
  {
    //once the end of the map is reached, print a message about that and leave the loop
    if (i >= mapArray.size()) {
      cout << "X" << endl;
      break;
    } 
    cout << mapArray[i] << " "; 
  }
    cout << "\n------------------------------------------" << endl; 
  cout << endl;
}

//gets letter found at a certain map array index 
char Map::getMapCharAt(int index){
  return mapArray[index];
}
  