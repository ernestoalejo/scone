
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_SPRITES_CHARACTER_H_
#define INCLUDE_SPRITES_CHARACTER_H_


#include "scone/sprite.h"


enum CharacterState {
  WALK,
  JUMP,
};


class Character : public Sprite {
public:
  Character();

  void event(const sf::Event& event);
  void update(float diff);

private:
  sf::Vector2f vel_, target_;
  CharacterState state_;

  DISALLOW_COPY_AND_ASSIGN(Character);
};


#endif  // INCLUDE_SPRITES_CHARACTER_H_
