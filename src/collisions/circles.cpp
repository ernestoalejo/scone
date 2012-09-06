
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include "collisions/circles.h"
#include "collisions/utils.h"


using collisions::Circle;
using collisions::Info;


Info collisions::Circles(const Circle& a, const Circle& b) {
  Info info;
  info.collides = false;

  float radioTotal = (a.radio + b.radio);

  float dx = (b.center.x - a.center.x);
  float dy = (b.center.y - a.center.y);
  float d2 = (dx * dx + dy * dy);

  // Check if the distance between the centers squared is
  // larger than both radios squared
  if (d2 > radioTotal * radioTotal)
    return info;

  info.collides = true;
  info.direction = -normalize(Vector2f(dx, dy));

  float distance = radioTotal - sqrt(d2);

  // As a special case, two circles with the same center.
  // The A circle is expelled to the right (0 degrees).
  if (info.direction.x == 0 && info.direction.y == 0) {
    info.direction = Vector2f(1, 1);
    distance = a.radio;
  }

  info.escape = info.direction * distance;

  return info;
}
