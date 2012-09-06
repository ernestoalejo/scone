
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#ifndef INCLUDE_SCONE_COMMON_H_
#define INCLUDE_SCONE_COMMON_H_


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <algorithm>
#include <cmath>
#include <fstream>   // NOLINT(readability/streams)
#include <iostream>  // NOLINT(readability/streams)
#include <sstream>   // NOLINT(readability/streams)
#include <string>
#include <vector>


using std::cerr;
using std::cout;
using std::endl;
using std::fstream;
using std::map;
using std::max;
using std::min;
using std::string;
using std::stringstream;
using std::vector;
using sf::Vector2f;


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


#endif  // INCLUDE_SCONE_COMMON_H_
