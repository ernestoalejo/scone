
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#include "collisions/points.h"
#include "gtest/gtest.h"


using collisions::Info;
using collisions::Rect;


#define VECTOR_EQ(v1, v2) \
  EXPECT_FLOAT_EQ(v1.x, v2.x); \
  EXPECT_FLOAT_EQ(v1.y, v2.y);

/*
Test(PointsTest, CenterOfASquare) {
  Rect r;
  r.pos = Vector2f(5, 5);
  r.size = Vector2f(4, 4);
}*/
