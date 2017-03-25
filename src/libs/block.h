#pragma once

#include "components.h"

class BlockPhysics : public PhysicsComponent{
public:
  BlockPhysics(int width, int height) {
    box_.setSize(sf::Vector2f(width,height));
    //Debugging purposes only.
    box_.setOutlineColor(sf::Color::Red);
    box_.setOutlineThickness(1);
  }
  virtual void update(GameObject& object, World& world){
    box_.setPosition(object.pos.x, object.pos.y);
    // ...
  }
private:
  sf::RectangleShape box_;
};

class BlockGraphics : public GraphicsComponent{
public:
  BlockGraphics():block_sprite_(Sprite("block1.png", 0, 0, 24, 24)){}

  virtual void update(GameObject& object, sf::RenderWindow& window){
    block_sprite_.update(object.pos.y, object.pos.x);
    window.draw(block_sprite_);
  }
private:
  BlockPhysics* physics_;
  Sprite block_sprite_;
};

class NullInput: public InputComponent {
public:
  virtual void update (GameObject& object){}
};

GameObject* createBlock(int x , int y, int width, int height) {
  return new GameObject(new NullInput(),
                        new BlockGraphics(), 
                        new BlockPhysics(width, height),
                        Vec2(x,y));
}
