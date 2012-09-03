
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include <string>

#include "sprites/platform.h"
#include "scone/resources-manager.h"


Platform::Platform(sf::FloatRect rect, string name)
  : size(rect.width, rect.height) {
  ResourcesManager::getInstance().loadTextures(sprite, name);
  calcSize();

  sprite.setPosition(rect.left, rect.top);
  sprite.scale(rect.width / sprite.getLocalBounds().width,
               rect.height / sprite.getLocalBounds().height);

  collisionRect.pos = sf::Vector2f(rect.left - size.x/2, rect.top - size.y/2);
  collisionRect.size = size;
  collisionRect.scale = sf::Vector2f(0, 0);
  collisionRect.angle = 0;
}


Platform::~Platform() {
  // vacio
}


void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite);
}


collisions::Rect Platform::getCollisionRect() {
  return collisionRect;
}
