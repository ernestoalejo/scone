
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_COLLISIONS_POINTS_H_
#define INCLUDE_COLLISIONS_POINTS_H_


#include "collisions/sat.h"


namespace collisions {

struct Info {
  bool collides;
  sf::Vector2f escape;
};

Info PointRect(const sf::Vector2f& point, const Rect& rect);
};


#endif  // INCLUDE_COLLISIONS_POINTS_H_

