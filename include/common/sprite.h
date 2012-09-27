
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_COMMON_SPRITE_H_
#define INCLUDE_COMMON_SPRITE_H_

#include "scone/common.h"
#include "common/drawable.h"

class Sprite : public Drawable {
public:
  Sprite();

  // Implement the sf::Drawable interface
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  sf::Vector2f position();


protected:
  sf::Sprite sprite;


private:
  DISALLOW_COPY_AND_ASSIGN(Sprite);
};


#endif  // INCLUDE_COMMON_SPRITE_H_
