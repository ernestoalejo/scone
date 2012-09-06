
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_COLLISIONS_STRUCTS_H_
#define INCLUDE_COLLISIONS_STRUCTS_H_


#include "scone/common.h"


namespace collisions {


struct Info {
  // True if the two shapes collide.
  bool collides;

  // The escape vector, that if added to the A shape, will
  // stop the collision.
  Vector2f escape;

  // The unitary vector showing the direction of movement.
  Vector2f direction;
};


struct Circle {
  sf::Vector2f center;
  float radio;
};


struct Rect {
  Vector2f pos, size, scale;
  float angle;

  sf::Transform getInverse() const {
    Vector2f center(size.x / 2, size.y / 2);

    sf::Transform t;
    t = t.scale(scale, center).getInverse();
    t.translate(-pos);

    if (angle != 0)
      t.rotate(-angle, center);

    return t;
  }
};


}   // namespace collisions


#endif  // INCLUDE_COLLISIONS_STRUCTS_H_
