
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#ifndef INCLUDE_SCONE_DRAWABLE_H_
#define INCLUDE_SCONE_DRAWABLE_H_


#include "scone/common.h"


class Drawable : public sf::Drawable {
public:
  Drawable();

  // Implement the sf::Drawable interface
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  // Functions made to been overwritten
  virtual void update(float diff);
  virtual void event(const sf::Event& event);

private:
  DISALLOW_COPY_AND_ASSIGN(Drawable);
};


#endif  // INCLUDE_SCONE_DRAWABLE_H_

