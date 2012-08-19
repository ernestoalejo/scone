
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include <string>

#include "sprites/platform.h"
#include "scone/resources-manager.h"


Platform::Platform(sf::FloatRect rect, string name)
  : size(rect.width, rect.height) {
  ResourcesManager::getInstance().loadTextures(sprite, name);

  sprite.setPosition(rect.left, rect.top);
  sprite.scale(rect.width / sprite.getLocalBounds().width,
               rect.height / sprite.getLocalBounds().height);
}


Platform::~Platform() {
  // vacio
}


void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite);
}
