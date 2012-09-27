
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include "editor/map.h"

Map::Map() {
  reservaEspacio();
}

Map::~Map() {
  liberaEspacio();
}

void Map::addFila(int fila) {
  int** auxstore = new int *[filas + 1];
  for (int i = 0; i < filas + 1; i++) {
    auxstore[i] = new int[columnas];
  }
  for (int f = 0; f < filas; f++) {
    for (int c = 0; c < columnas; c++) {
      if (f < fila) {
        auxstore[f][c] = store[f][c];
      } else {
        auxstore[f + 1][c] = store[f][c];
      }
    }
  }

  liberaEspacio();
  store = auxstore;
  filas++;
  for (int c = 0; c < columnas; c++) {
    store[fila][c] = -1;
  }
}

void Map::addColumna(int columna) {
  int** auxstore = new int *[filas];
  for (int i = 0; i < columnas + 1; i++) {
    auxstore[i] = new int[columnas + 1];
  }
  for (int f = 0; f < filas; f++) {
    for (int c = 0; c < columnas; c++) {
      if (c < columna) {
        auxstore[f][c] = store[f][c];
      } else {
        auxstore[f][c + 1] = store[f][c];
      }
    }
  }

  liberaEspacio();
  store = auxstore;
  columnas++;
  for (int i = 0; i < filas; i++) {
    store[i][columna] = -1;
  }
}

int Map::getFilas() {
  return filas;
}

int Map::getColumnas() {
  return columnas;
}

void Map::reservaEspacio() {
  store = new int *[1];
  store[0] = new int[1];
  store[0][0] = -1;
  filas = 1;
  columnas = 1;
}

void Map::liberaEspacio() {
  for (int f = 0; f < filas; f++) {
    delete [] store[f];
  }
  delete [] store;
}
