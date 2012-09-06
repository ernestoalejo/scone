
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_COLLISIONS_UTILS_H_
#define INCLUDE_COLLISIONS_UTILS_H_


#include "scone/common.h"
#include "collisions/structs.h"


namespace collisions {


inline Vector2f normalize(const Vector2f& v) {
  float  length = sqrt(v.x * v.x + v.y * v.y);
  return length == 0 ? v : Vector2f(v.x / length, v.y / length);
}


inline Vector2f normal(const Vector2f& p1, const Vector2f& p2) {
  return normalize(Vector2f(p1.y - p2.y, p2.x - p1.x));
}


inline float dotProduct(const Vector2f& p1, const Vector2f& p2) {
  return p1.x * p2.x + p1.y * p2.y;
}


}   // namespace collisions


#endif  // INCLUDE_COLLISIONS_UTILS_H_
