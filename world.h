#pragma once

#include <array>
#include <vector>
#include "constants.h"
#include "components.h"

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
    for (int i = 0; i < SQUARE_SIZE; ++i){
      for (int j = 0; j < SQUARE_SIZE; ++j){
        switch (level[i][j]){
          case 0:
            tile_map[i][j] = FREE;
            break;
          case 1:
            tile_map[i][j] = SOLID;
        }
      }
    }
  }
  int getSize() const { return SQUARE_SIZE; }
  std::array< std::array<TileType, SQUARE_SIZE>, SQUARE_SIZE> tile_map;
private:
  std::vector<GameObject*> field_objects;
};
