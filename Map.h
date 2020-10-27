#pragma once
#include <array>
//for a real game this should be set to at least 100 but to keep the presentation short we will leave it at 30
const int MAP_SIZE = 30;

class Map
{
  private:
  //empty array of 30 elements 
  std::array<char,MAP_SIZE> mapArray; 
  public:
  //writes random letters to a map.txt file 
  void fillMap(); 
  //reading in from text file to 
  //fill map array 
  void createMap();

  //set the map array
  void setMapArray(std::array<char, MAP_SIZE> a);

  //will display the values of the
  //next 12 elements of array 
  void  showSneakPeek(int position, int vision);
  //returns char at array index 
  char getMapCharAt(int index); 
};