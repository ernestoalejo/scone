
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include "editor/tile-list.h"
#include <string>

TileList::TileList() {
  filas = 0;
  columnas = 0;
  selected = 0;
  textura = NULL;
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
    int x = (i == 7) ? 750 : 760;
    sprites[i].setPosition(x, 40 * i);
    sprites[i].setTexture(*textura, true);
  }
}

void TileList::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  for (int i = 0 ; i < 15 ; i++) {
    target.draw(sprites[i]);
  }
}

void TileList::event(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed) {
    switch(event.key.code){
      case sf::Keyboard::L:
        if (textura == NULL){
          Load("prueba");
        }
        break;

      case sf::Keyboard::W:
        selected--;
        if (selected < 0)
          selected = columnas * filas;
        break;

      case sf::Keyboard::S:
        selected++;
        selected = selected % (columnas * filas);
        break;

      default:
        break;
    }
  }
}

void TileList::update(float diff){
  if (columnas == 0 && filas == 0)
    return;

  int total = columnas * filas;

  int n = selected - 7;
  if (n < 0)
    n += total;

  for (int i = 0 ; i < 15 ; i++) {
    int j = n + i;
    if (j > total)
      j -= total;

    sprites[i].setTextureRect(sf::IntRect((j % columnas) * 32,
                                          (j / columnas) * 32, 32, 32));
  }
}
