#pragma once

#include "components.h"

#include <iostream>

using namespace std;

class CharPhysics: public PhysicsComponent{
public:
  CharPhysics(int width, int height) {
    box_.setSize(sf::Vector2f(width,height));
    //Debugging purposes only.
    box_.setOutlineColor(sf::Color::Red);
    box_.setOutlineThickness(1);
  }
  virtual void update(GameObject& object, World& world){
    object.pos.x += object.vel.x;
    object.pos.y += object.vel.y;
    box_.setPosition(object.pos.x, object.pos.y);
    cerr << object.pos.x << " " << object.pos.y << endl;
    // ...
  }
private:
  sf::RectangleShape box_;
};

class CharGraphics: public GraphicsComponent{
public:
  CharGraphics():char_sprite_(Sprite("assets/gfx/block1.png", 0, 0, 24, 24)){}

  virtual void update(GameObject& object, sf::RenderWindow& window){
    cerr << object.pos.x << " " << object.pos.y << endl;
    char_sprite_.update(object.pos.x,object.pos.y, PIXELWISE);
    window.draw(char_sprite_);
  }
private:
  BlockPhysics* physics_;
  Sprite char_sprite_;
};

class CharInput: public InputComponent {
public:
  virtual void update (GameObject& object){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
      object.vel.x = -1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      object.vel.x = 1;
    } else {
      object.vel.x = 0;
    }
  }
};

GameObject* createChar(int x , int y, int width, int height) {
  return new GameObject(new CharInput(),
                        new CharGraphics(), 
                        new CharPhysics(width, height),
                        Vec2(x,y));
}
