#pragma once

#include "components.h"

const int CHAR_STD_SIZE = 24;

class CharPhysics: public PhysicsComponent{
public:
  CharPhysics(int width, int height) {
    box_.setSize(sf::Vector2f(width,height));
    //Debugging purposes only.
    box_.setOutlineColor(sf::Color::Red);
    box_.setOutlineThickness(1);
  }
  virtual void update(GameObject& object, World& world){
    box_.setPosition(object.pos.x, object.pos.y);
    auto blocks = world.getBlocks();
    object.vel.y += GRAVITY;
    auto bounds = box_.getGlobalBounds();
    auto bounds_i = sf::Rect<int> (bounds);
    sf::IntRect future(bounds_i.left+object.vel.x,bounds_i.top+object.vel.y, bounds.width, bounds.height);
    for (auto block : blocks){
    sf::IntRect block_bound = sf::Rect<int> (block->getPhysics()->getBox().getGlobalBounds());
      if (block_bound.intersects(future)){
        if (object.vel.y > 0) object.vel.y = 0;
      }
    }
    object.pos.x += object.vel.x;
    object.pos.y += object.vel.y;
    // ...
  }
};

class CharGraphics: public GraphicsComponent{
public:
  CharGraphics():char_sprite_(Sprite("assets/gfx/ekki.png", 0, 0, 24, 24)){}

  virtual void update(GameObject& object, sf::RenderWindow& window){
    char_sprite_.update(object.pos.x,object.pos.y);
    window.draw(char_sprite_);
  }
private:
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
    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
      object.vel.y = -1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      object.vel.y = 1;
    } else {
      object.vel.y = 0;
    }
    */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      object.vel.y = -5;

  }
};

GameObject* createChar(int x , int y, int width, int height) {
  return new GameObject(new CharInput(),
                        new CharGraphics(), 
                        new CharPhysics(width, height),
                        Vec2(x,y));
}
