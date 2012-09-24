
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#include "collisions/circles.h"
#include "collisions/utils.h"


using collisions::Circle;
using collisions::Info;


Info collisions::Circles(const Circle& a, const Circle& b) {
  Info info;
  info.collides = false;

  float radiototal = a.radio + b.radio;
  float dx = (b.center.x - a.center.x);
  float dy = (b.center.y - a.center.y);
  if (dx * dx + dy * dy > radiototal * radiototal) {
    return info;
  }

  info.collides = true;
  info.direction = normalize(sf::Vector2f(dx, dy));
  float espacio = radiototal - sqrt(dx * dx + dy * dy);
  info.escape = info.direction * espacio;

  return info;
}
