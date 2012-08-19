
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_SCONE_LEVEL_LOADER_H_
#define INCLUDE_SCONE_LEVEL_LOADER_H_

#include <string>
#include <vector>

#include "scone/common.h"
#include "sprites/platform.h"


class LevelLoader {
public:
  explicit LevelLoader(string name);

  vector<Platform*> getPlatform();
  int getLevelSize();

private:
  void Load(string name);
  vector<Platform*> platforms;
  int levelSize;

  DISALLOW_COPY_AND_ASSIGN(LevelLoader);
};


#endif  // INCLUDE_SCONE_LEVEL_LOADER_H_
