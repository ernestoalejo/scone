
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include <string>
#include <vector>

#include "scone/level.h"


// Almacena la plataforma en vector.
Level::Level(string name) {
  LevelLoader datos(name);
  platform = datos.getPlatform();
  levelSize = datos.getLevelSize();
}

void Level::update(float diff) {
  // vacio
}

void Level::event(const sf::Event& event) {
  // vacio
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  for (unsigned int i = 0; i < platform.size(); i++) {
    platform[i]->draw(target, states);
  }
}

int Level::getLevelSize() {
  return levelSize;
}

vector<Platform*> Level::getPlatform() const {
  return platform;
}

