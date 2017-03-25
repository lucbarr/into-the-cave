#pragma once

#include <array>
#include <vector>

#include "block.h"


// Holds data from all things in the environment

enum TileType{
  SOLID,
  FREE
};

class World{
public:
  World() {
    int level[3][3] = {
        {0,0,0},  
        {0,0,0},
        {1,1,1}   
    };
    for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 3; ++j){
        switch (level[i][j]){
          case 0:
            tile_map[i][j] = FREE;
            break;
          case 1:
            tile_map[i][j] = SOLID;
            blocks_.push_back(createBlock(i,j,24,24));
        }
      }
    }
 }
  int getSize() const { return SQUARE_SIZE; }
  std::array< std::array<TileType, SQUARE_SIZE>, SQUARE_SIZE> tile_map;
  void drawTo(sf::RenderWindow& window){
  for (auto& block : blocks_)
    block->update(*this, window);
  }
private:
  std::vector<GameObject*> field_objects;
  std::vector<GameObject*> blocks_;
};

