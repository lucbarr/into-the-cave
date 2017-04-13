
#include "libs/graphics.h"
#include "libs/constants.h"
#include "libs/world.h"

#include <stdio.h>

int main(){
  sf::RenderWindow window(sf::VideoMode(SQUARE_SIZE*PIXELS_TILE_SIZE, SQUARE_SIZE*PIXELS_TILE_SIZE), "into the cave");
  window.setFramerateLimit(60);
  window.setVerticalSyncEnabled(true);
  window.clear(sf::Color(53,43,49));
  World world;
  while (window.isOpen()) {
    window.clear(sf::Color(53,43,49));
    // Event processing
    sf::Event event;
    while (window.pollEvent(event)) {
      // Request for closing the window
      if (event.type == sf::Event::Closed)
      window.close();
    }
    // Activate the window for OpenGL rendering
    window.setActive();
    // OpenGL drawing commands go here...
    // End the current frame and display its contents on screen
    world.drawTo(window);
    window.display();
  }
  return 0;
}
