#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "world.h"

class GameObject;
class World;

class PhysicsComponent{
public:
  virtual ~PhysicsComponent() {}
  PhysicsComponent(int width, int height, int x, int y) {
    box_.setSize(sf::Vector2f(width,height));
    box_.setPosition(x,y);
    // Color and thickness defined for debugging purposes. Not needed.
    box_.setOutlineColor(sf::Color::Red);
    box_.setOutlineThickness(1);
  }
  virtual void update(GameObject& object, World& world) = 0;
private:
  sf::RectangleShape box_; //All objects will be rectangles meanwhile
};

class GraphicsComponent {
public:
  virtual ~GraphicsComponent() {}
  virtual void update(GameObject& object, sf::RenderWindow& window) = 0;
private:

};

class InputComponent {
public:
  virtual ~InputComponent() {}
  virtual void update (GameObject& object) = 0;
private:

};

class GameObject{
public:
  Vec2 pos;
  Vec2 vel;
  GameObject(InputComponent* input, GraphicsComponent* graphics, PhysicsComponent* physics):
    input_(input),
    graphics_(graphics),
    physics_(physics){
      static int id_counter = 0;
      id_ = id_counter;
      id_counter ++;
    }

  void update(World& world, sf::RenderWindow& window){
    input_->update(*this);
    graphics_->update(*this, window);
    physics_->update(*this, world);
  }
private:
  int id_;
  InputComponent* input_;
  GraphicsComponent* graphics_;
  PhysicsComponent* physics_;
};
