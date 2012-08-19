
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#include <cstdlib>


unsigned int globalRandSeed;


int Rand(int n) {
  return rand_r(&globalRandSeed) % n;
}

