#include "Labyrinth.h"
#include <iostream>

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
  bool spellbook, potion, wand;
  MazeCell * current = start;
  
  for(int i = 0; i < moves.length(); i++){
    /*std::cout << current << "\n";*/
    
    if(current == nullptr) return false;
    
    if(moves[i] == 'N') current = current->north;
    else if(moves[i] == 'S') current = current->south;
    else if(moves[i] == 'W') current = current->west;
    else if(moves[i] == 'E') current = current->east;
    
    if(current == nullptr) return false;

    if(current != nullptr){
      Item item = current->whatsHere;
      switch(item){
      case Item::SPELLBOOK : spellbook = true; break;
      case Item::POTION : potion = true; break;
      case Item::WAND : wand = true; break;
      case Item::NOTHING : break;
      }
    }
  }
  
  /*std::cout << spellbook << "\n" << potion << "\n" << wand << "\n";*/
  
  return(spellbook && potion && wand);
}
