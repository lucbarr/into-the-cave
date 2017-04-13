#pragma once

#include <array>
#include <vector>
#include "components.h"


// Holds data from all things in the environment

enum TileType{
  SOLID,
  FREE
};

class World{
public:
  World();
  void drawTo(sf::RenderWindow& window); 
  int getSize() const { return SQUARE_SIZE; }
  std::vector<GameObject*> getBlocks() const ; 
  std::array< std::array<TileType, SQUARE_SIZE>, SQUARE_SIZE> tile_map;
private:
  std::vector<GameObject*> field_objects_;
  std::vector<GameObject*> blocks_;
  GameObject* char_;
};

