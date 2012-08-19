
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#ifndef INCLUDE_SCONE_SPRITE_H_
#define INCLUDE_SCONE_SPRITE_H_


#include "scone/common.h"


class Sprite : public sf::Drawable {
public:
  Sprite();

  // Implement the sf::Drawable interface
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  // Functions made to been overwritten
  virtual void update(float diff);
  virtual void event(const sf::Event& event);

  sf::Vector2f position();


protected:
  sf::Sprite sprite;


private:
  DISALLOW_COPY_AND_ASSIGN(Sprite);
};


#endif  // INCLUDE_SCONE_SPRITE_H_

