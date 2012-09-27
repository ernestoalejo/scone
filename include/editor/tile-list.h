
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_EDITOR_TILE_LIST_H_
#define INCLUDE_EDITOR_TILE_LIST_H_

#include <string>

#include "scone/common.h"
#include "common/drawable.h"

class TileList : public Drawable {
public:
  TileList();
  ~TileList();
  void Load(string name);

  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void event(const sf::Event& event);
  void update(float diff);

private:
  int columnas, filas;
  sf::Sprite sprites[15];
  sf::Texture* textura;
  int selected;
};

#endif  // INCLUDE_EDITOR_TILE_LIST_H_
