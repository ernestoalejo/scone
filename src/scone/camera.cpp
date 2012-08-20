
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#include "scone/camera.h"

Camera::Camera(int end) {
  this->end = end;
  view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
}


void Camera::update(float diff) {
  float posx = sprite->position().x;

  if (posx < HALF_SCREEN_WIDTH) {
    posx = HALF_SCREEN_WIDTH;
  }

  if (posx > end - HALF_SCREEN_WIDTH) {
    posx = end - HALF_SCREEN_WIDTH;
  }

  view.setCenter(posx, HALF_SCREEN_HEIGHT);
}


void Camera::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.setView(view);
}


void Camera::follow(Sprite& sprite) {
  this->sprite = &sprite;
}

float Camera::getX() const {
  return view.getCenter().x - HALF_SCREEN_WIDTH;
}
