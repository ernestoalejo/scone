
#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string>

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

#define LOG cout
#define ERROR cerr

#endif
