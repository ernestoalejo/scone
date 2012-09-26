
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_COLLISIONS_STRUCTS_H_
#define INCLUDE_COLLISIONS_STRUCTS_H_


#include "scone/common.h"


namespace collisions {


struct Info {
  bool collides;

  Vector2f escape;

  Vector2f direction;
};


struct Circle {
  sf::Vector2f center;
  float radio;
};


struct Rect {
  Vector2f pos, size, scale;
  float angle;
};


}   // namespace collisions


#endif  // INCLUDE_COLLISIONS_STRUCTS_H_
