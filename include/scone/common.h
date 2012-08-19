
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


using namespace std;

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

const float SCREEN_WIDTH = 640;
const float SCREEN_HEIGHT = 480;

const float HALF_SCREEN_HEIGHT = SCREEN_HEIGHT / 2;
const float HALF_SCREEN_WIDTH = SCREEN_WIDTH / 2;

#define LOG cerr
#define ERROR cerr

#endif
