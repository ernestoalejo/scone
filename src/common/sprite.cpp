
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#include "common/sprite.h"

Sprite::Sprite() {
  // empty
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite);
}

sf::Vector2f Sprite::position() {
  return sprite.getPosition();
}
