#pragma once

#include <array>
#include <vector>
#include "components.h"
#include "graphics.h"


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
  void drawTo(sf::RenderWindow& window){
    Sprite solid_sprite("block1.png" , 0 , 0 , 24, 24);
    for (int i = 0 ; i < 3; ++i ){
      for (int j = 0 ; j < 3 ; ++j ){
        if (tile_map[i][j] == SOLID){
          solid_sprite.update(i,j);
          window.draw(solid_sprite);
        }
      }
    }
  }
private:
  std::vector<GameObject*> field_objects;
};

