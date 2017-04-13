#include "world.h"
#include "block.h"
#include "char.h"

World::World() {
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
          blocks_.push_back(createBlock(j*24,i*24,24,24));
      }
    }
  }
  char_ = createChar(24,24,24,24);
}

void World::drawTo(sf::RenderWindow& window){
  // sequence determines what overlays what...
  // I know, I know... kinda ugly.
  char_->update(*this, window);
  for (auto& block : blocks_)
    block->update(*this, window);
}


std::vector<GameObject*> World::getBlocks() const { return blocks_; }
