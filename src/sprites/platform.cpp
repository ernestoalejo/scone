
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include "sprites/platform.h"
#include "resources-manager.h"

Platform::Platform(sf::FloatRect rect, string name)
  : size(rect.width, rect.height) {
  ResourcesManager::getInstance().loadTextures(sprite, name);
  sprite.setPosition(rect.left, rect.top);
  sprite.scale(rect.width / sprite.getLocalBounds().width,
               rect.height / sprite.getLocalBounds().height);
}

Platform::~Platform() {

}

void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite);
}
