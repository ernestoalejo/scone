
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include "editor/tile-list.h"
#include <string>

TileList::TileList() {
  filas = 0;
  columnas = 0;
  selected = 0;
}

TileList::~TileList() {
}

void TileList::Load(string name) {
  textura = new sf::Texture();
  string dir("assets/editor/tile-sheets/" + name + ".png");
  if (!textura->loadFromFile(dir))
    ERROR << "Error cargando imagen " << dir << endl;

  sprites[0].setTexture(*textura, true);
  sf::FloatRect bounds = sprites[0].getLocalBounds();
  columnas = bounds.width / 32;
  filas = bounds.height / 32;

  for (int i = 0 ; i < 15 ; i++) {
    sprites[i].setPosition(760, 284);
    sprites[i].setTexture(*textura, true);
    sprites[i].setTextureRect(sf::IntRect(i % columnas, i / columnas, 32, 32));
  }
}

void TileList::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  for (int i = 0 ; i < 15 ; i++) {
    target.draw(sprites[i]);
  }
}
