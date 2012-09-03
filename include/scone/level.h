
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_SCONE_LEVEL_H_
#define INCLUDE_SCONE_LEVEL_H_


#include <string>
#include <vector>

#include "scone/common.h"
#include "scone/level-loader.h"


class Level : public Sprite {
public:
  explicit Level(string name);

  void update(float diff);
  void event(const sf::Event& event);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  int getLevelSize();
  vector<Platform*> getPlatform() const;

private:
  vector<Platform*> platform;
  int levelSize;

  DISALLOW_COPY_AND_ASSIGN(Level);
};


#endif  // INCLUDE_SCONE_LEVEL_H_
