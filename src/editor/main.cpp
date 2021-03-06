
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include "scone/common.h"
#include "editor/tile-list.h"


int main(int argc, char* argv[]) {
  sf::RenderWindow screen(sf::VideoMode(800, 600), "Editor de niveles");
  screen.setVerticalSyncEnabled(true);

  TileList list;

  sf::Clock clock;
  while (screen.isOpen()) {
    sf::Event event;
    while (screen.pollEvent(event)) {
      if (event.type == sf::Event::Closed ||
          (event.type == sf::Event::KeyPressed &&
           event.key.code == sf::Keyboard::Escape)) {
        screen.close();
      }

      list.event(event);
    }

    float diff = clock.getElapsedTime().asMilliseconds();
    clock.restart();

    list.update(diff);

    screen.clear();

    screen.draw(list);

    screen.display();
  }

  return EXIT_SUCCESS;
}
