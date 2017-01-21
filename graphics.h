#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "world.h"


class Sprite : public sf::Sprite {
public:
  Sprite(const std::string& sprite, int j, int i, int width, int height){
    if (!texture_.loadFromFile(sprite, sf::IntRect(0,0,width,height))){
      std::cerr << "ERROR: Couldn't load sprite file:" << sprite << std::endl;
    } else {
      this->setTexture(texture_);
      this->setPosition(sf::Vector2f(i*width,j*height));
    }
    width_ = width;
    height_ = height;
  }
  void update(int j, int i){
    this->setPosition(sf::Vector2f(i*width_,j*height_));
  }
private:
  sf::Texture texture_;
  int width_, height_;
};

//Change this later, shouldn't have global variables.
Sprite block1("block1.png", 0, 0, PIXELS_TILE_SIZE, PIXELS_TILE_SIZE);
Sprite block2("block2.png", 1, 0, PIXELS_TILE_SIZE, PIXELS_TILE_SIZE);

