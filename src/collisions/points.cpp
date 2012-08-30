
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include "collisions/points.h"


using collisions::Info;
using collisions::Rect;


Info collisions::PointRectangle(const sf::Vector2f& point, const Rect& rect) {
  Info info;
  info.collides = false;

  sf::Vector2f p(rect.getInverse().transformPoint(point));

  if (p.x < rect.size.x && p.x > 0 && p.y < rect.size.y && p.y > 0) {
    info.collides = true;

    float halfx = rect.size.x / 2.;
    float halfy = rect.size.y / 2.;

    info.escape = sf::Vector2f(
                    p.x < halfx ? -p.x : (rect.size.x - p.x),
                    p.y < halfy ? -p.y : (rect.size.y - p.y));
  }

  return info;
}
