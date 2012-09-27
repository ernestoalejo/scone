
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_EDITOR_MAP_H_
#define INCLUDE_EDITOR_MAP_H_

#include "scone/common.h"
#include "common/drawable.h"
#include "gtest/gtest_prod.h"

class Map : public Drawable {
public:
  Map();
  ~Map();
  void addFila(int fila);
  void addColumna(int columna);
  int getFilas();
  int getColumnas();
private:
  int** store;
  int filas, columnas;
  void reservaEspacio();
  void liberaEspacio();

  FRIEND_TEST(MapTest, CopiaAniadirFila);
  FRIEND_TEST(MapTest, CopiaAniadirColumna);
  DISALLOW_COPY_AND_ASSIGN(Map);
};

#endif  // INCLUDE_EDITOR_MAP_H_
