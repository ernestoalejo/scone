
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#include "collisions/circles.h"
#include "gtest/gtest.h"


using collisions::Circle;
using collisions::Info;


#define VECTOR_EQ(v1, v2) \
  EXPECT_EQ(v1.x, v2.x); \
  EXPECT_EQ(v1.y, v2.y);


TEST(CirclesTest, SamePositionAndSize) {
  Circle a, b;
  Info info;

  a.radio = b.radio = 3;
  a.center = b.center = Vector2f(1, 1);
  info = collisions::Circles(a, b);

  ASSERT_TRUE(info.collides);
  VECTOR_EQ(Vector2f(3, 3), info.escape);
  VECTOR_EQ(Vector2f(1, 1), info.direction);
}


TEST(CirclesTest, SameXAxis) {
  Circle a, b;
  Info info;

  // Try first the A circle below
  a.radio = b.radio = 3;
  a.center = Vector2f(1, 1);
  b.center = Vector2f(1, 2);
  info = collisions::Circles(a, b);

  ASSERT_TRUE(info.collides);
  VECTOR_EQ(Vector2f(0, -5), info.escape);
  VECTOR_EQ(Vector2f(0, -1), info.direction);

  // And then the A circle above
  b.center = Vector2f(1, 0);
  info = collisions::Circles(a, b);

  ASSERT_TRUE(info.collides);
  VECTOR_EQ(Vector2f(0, 5), info.escape);
  VECTOR_EQ(Vector2f(0, 1), info.direction);
}
