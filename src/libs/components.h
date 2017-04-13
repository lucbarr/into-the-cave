#pragma once

#include "graphics.h" 
#include "constants.h"

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
      vel = Vec2(0,0);
      pos = p0;
      static int id_counter = 0;
      id_ = id_counter;
      id_counter ++;
    }
  ~GameObject() { 
    static int id_counter = 0 ;
    id_counter--; 
  }

  void update(World& world, sf::RenderWindow& window){
    input_->update(*this);
    physics_->update(*this, world);
    graphics_->update(*this, window);
  }

  InputComponent* getInput() const { return input_; }
  GraphicsComponent* getGraphics() const { return graphics_; };
  PhysicsComponent* getPhysics() const { return physics_; };
private:
  int id_;
  InputComponent* input_;
  GraphicsComponent* graphics_;
  PhysicsComponent* physics_;
};

