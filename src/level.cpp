
#include "level.h"


// Almacena la plataforma en vector.
Level::Level(string name) {
  LevelLoader datos(name);
  platform = datos.getPlatform();
  levelSize = datos.getLevelSize();
}

void Level::update(float diff) {

}

void Level::event(const sf::Event& event) {

}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {

  for (unsigned int i = 0; i < platform.size(); i++) {
    platform[i]->draw(target, states);
  }

}

int Level::getLevelSize() {
  return levelSize;
}
