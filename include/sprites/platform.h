
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef __SPRITES_PLATFORM_H__
#define __SPRITES_PLATFORM_H__

#include "scone/common.h"
#include "scone/sprite.h"

class Platform : public Sprite {
public:
  Platform(sf::FloatRect rect, string name);
  ~Platform();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
  sf::Vector2f size;

};

#endif
