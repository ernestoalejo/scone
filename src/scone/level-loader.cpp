
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include <string>
#include <vector>

#include "scone/level-loader.h"


LevelLoader::LevelLoader(string name) {
  Load(name);
}

void LevelLoader::Load(string name) {
  // Carga la informacion del nivel.
  string dir("data/levels/" + name + "/info.lvl");
  fstream file(dir.c_str(), fstream::in);

  float x, y;
  int w, h, n;
  string tipo;

  file >> n;
  levelSize = n;
  file >> n;

  platforms.resize(n);

  for (int i = 0 ; i < n ; i++) {
    file >> tipo;
    file >> x;
    file >> y;
    file >> w;
    file >> h;
    sf::FloatRect rect(x, y, w, h);
    Platform* platformtmp = new Platform(rect, tipo);

    platforms[i] = platformtmp;
  }

  file.close();
}

vector<Platform*> LevelLoader::getPlatform() {
  return platforms;
}

int LevelLoader::getLevelSize() {
  return levelSize;
}
