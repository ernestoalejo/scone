
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#include "collisions/circles.h"
#include "gtest/gtest.h"


using collisions::Circle;
using collisions::Info;


#define VECTOR_EQ(v1, v2) \
  EXPECT_FLOAT_EQ(v1.x, v2.x); \
  EXPECT_FLOAT_EQ(v1.y, v2.y);


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

  // Try first the A circle above
  a.radio = b.radio = 3;
  a.center = Vector2f(3, 3);
  b.center = Vector2f(3, 4);
  info = collisions::Circles(a, b);

  ASSERT_TRUE(info.collides);
  VECTOR_EQ(Vector2f(0, -5), info.escape);
  VECTOR_EQ(Vector2f(0, -1), info.direction);

  // And then the A circle below
  b.center = Vector2f(3, 2);
  info = collisions::Circles(a, b);

  ASSERT_TRUE(info.collides);
  VECTOR_EQ(Vector2f(0, 5), info.escape);
  VECTOR_EQ(Vector2f(0, 1), info.direction);
}


TEST(CirclesTest, SameYAxis) {
  Circle a, b;
  Info info;

  // Try first the A circle at the left
  a.radio = b.radio = 3;
  a.center = Vector2f(3, 3);
  b.center = Vector2f(4, 3);
  info = collisions::Circles(a, b);

  ASSERT_TRUE(info.collides);
  VECTOR_EQ(Vector2f(-5, 0), info.escape);
  VECTOR_EQ(Vector2f(-1, 0), info.direction);

  // And then the A circle at the right
  b.center = Vector2f(2, 3);
  info = collisions::Circles(a, b);

  ASSERT_TRUE(info.collides);
  VECTOR_EQ(Vector2f(5, 0), info.escape);
  VECTOR_EQ(Vector2f(1, 0), info.direction);
}



TEST(CirclesTest, FourthQuad) {
  Circle a, b;
  Info info;

  // Try first the A circle at the top-left
  a.radio = b.radio = 3;
  a.center = Vector2f(3, 3);
  b.center = Vector2f(4, 4);
  info = collisions::Circles(a, b);

  ASSERT_TRUE(info.collides);
  VECTOR_EQ(Vector2f(-3.2426405, -3.2426405), info.escape);
  VECTOR_EQ(Vector2f(-0.707107, -0.707107), info.direction);

  // And then the A circle at the bottom-right
  b.center = Vector2f(2, 2);
  info = collisions::Circles(a, b);

  ASSERT_TRUE(info.collides);
  VECTOR_EQ(Vector2f(3.2426405, 3.2426405), info.escape);
  VECTOR_EQ(Vector2f(0.707107, 0.707107), info.direction);
}
