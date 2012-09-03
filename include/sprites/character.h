
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_SPRITES_CHARACTER_H_
#define INCLUDE_SPRITES_CHARACTER_H_

#include <vector>

#include "scone/sprite.h"
#include "scone/level.h"


class Character : public Sprite {
public:
  Character();

  void event(const sf::Event& event);
  void update(float diff);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  void setLevel(const Level& level);

private:
  sf::Vector2f vel, target;
  vector<Platform*> platforms;
  bool jump;

  sf::Text targetDisplay, velDisplay;

  DISALLOW_COPY_AND_ASSIGN(Character);
};


#endif  // INCLUDE_SPRITES_CHARACTER_H_
