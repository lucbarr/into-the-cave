#pragma once

#include "graphics.h" 
#include "constants.h"
#include "world.h"

class GameObject;
class World;

class PhysicsComponent{
public:
  virtual ~PhysicsComponent() {}
  virtual void update(GameObject& object, World& world) = 0;
private:
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
  GameObject(InputComponent* input, GraphicsComponent* graphics, PhysicsComponent* physics, Vec2 p0):
    input_(input),
    graphics_(graphics),
    physics_(physics){
      pos = p0;
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

