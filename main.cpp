#include "graphics.h"
#include <stdio.h>

int main(){
  sf::RenderWindow window(sf::VideoMode(SQUARE_SIZE*PIXELS_TILE_SIZE, SQUARE_SIZE*PIXELS_TILE_SIZE), "into the cave");
  window.setFramerateLimit(60);
  window.clear(sf::Color(53,43,49));
  while (window.isOpen()) {
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
    window.display();
}

  return 0;
}
