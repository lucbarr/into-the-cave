#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

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
  void update(int i, int j){
    this->setPosition(sf::Vector2f(i*width_,j*height_));
  }
private:
  sf::Texture texture_;
  int width_, height_;
};

