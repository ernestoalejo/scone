
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#include "scone/sprite.h"

Sprite::Sprite() {
  // empty
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite);
}

void Sprite::update(float diff) {
}

void Sprite::event(const sf::Event& event) {
  // empty
}

sf::Vector2f Sprite::position() {
  return sprite.getPosition();
}
