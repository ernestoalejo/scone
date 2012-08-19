
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "scone/common.h"
#include "level-loader.h"


class Level : public Sprite {

public:
  Level(string name);
  void update(float diff);
  void event(const sf::Event& event);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  int getLevelSize();

private:
  DISALLOW_COPY_AND_ASSIGN(Level);
  vector<Platform*> platform;
  int levelSize;

};



#endif
