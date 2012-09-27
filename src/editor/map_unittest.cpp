
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include "editor/map.h"
#include "gtest/gtest.h"

TEST(MapTest, AddFila) {
  Map Prueba;
  EXPECT_EQ(Prueba.getFilas(), 1);
  Prueba.addFila(1);
  EXPECT_EQ(Prueba.getFilas(), 2);
  Prueba.addFila(2);
  EXPECT_EQ(Prueba.getFilas(), 3);
}

TEST(MapTest, CopiaAniadir) {
  Map Prueba;
  EXPECT_EQ(Prueba.getFilas(), 1);
  EXPECT_EQ(Prueba.getColumnas(), 1);
  EXPECT_EQ(Prueba.store[0][0], -1);

  Prueba.addFila(1);
  EXPECT_EQ(Prueba.getFilas(), 2);
  EXPECT_EQ(Prueba.getColumnas(), 1);
  EXPECT_EQ(Prueba.store[0][0], -1);
  EXPECT_EQ(Prueba.store[1][0], -1);

  Prueba.store[0][0] = 3;
  Prueba.store[1][0] = 5;
  Prueba.addFila(0);
  EXPECT_EQ(Prueba.getFilas(), 3);
  EXPECT_EQ(Prueba.getColumnas(), 1);
  EXPECT_EQ(Prueba.store[0][0], -1);
  EXPECT_EQ(Prueba.store[1][0], 3);
  EXPECT_EQ(Prueba.store[2][0], 5);
}
