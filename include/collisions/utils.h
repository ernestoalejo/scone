
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_COLLISIONS_UTILS_H_
#define INCLUDE_COLLISIONS_UTILS_H_


#include "scone/common.h"
#include "collisions/structs.h"


namespace collisions {


inline Vector2f normalize(const Vector2f& v) {
  float length = sqrt(v.x * v.x + v.y * v.y);
  return length == 0 ? v : Vector2f(v.x / length, v.y / length);
}


}   // namespace collisions


#endif  // INCLUDE_COLLISIONS_UTILS_H_
