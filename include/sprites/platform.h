
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_SPRITES_PLATFORM_H_
#define INCLUDE_SPRITES_PLATFORM_H_


#include <string>

#include "scone/common.h"
#include "scone/sprite.h"
#include "collisions/sat.h"


class Platform : public Sprite {
public:
  Platform(sf::FloatRect rect, string name);
  ~Platform();

  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  collisions::Rect getCollisionRect();

private:
  sf::Vector2f size;
  collisions::Rect collisionRect;
};


#endif  // INCLUDE_SPRITES_PLATFORM_H_
