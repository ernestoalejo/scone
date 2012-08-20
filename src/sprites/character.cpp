
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include "scone/resources-manager.h"
#include "sprites/character.h"


const float VELOCITY = 5;
const float ACCELERATION = 0.1;
const float THRESHOLD = 0.07;


Character::Character()
: target_(0, 0)
{ 
  ResourcesManager::getInstance().loadTextures(sprite, "character");
  sprite.setPosition(HALF_SCREEN_WIDTH, HALF_SCREEN_HEIGHT);
}


void Character::update(float diff) {
  vel_ = target_ * ACCELERATION + vel_ * (1 - ACCELERATION);

  if(fabs(vel_.x) < THRESHOLD)
    vel_.x = 0;
  if(fabs(vel_.y) < THRESHOLD)
    vel_.y = 0;

  sprite.move(vel_);
}


void Character::event(const sf::Event& event) {
  if(event.type == sf::Event::KeyPressed) {
    switch(event.key.code) {
      case sf::Keyboard::Up:    target_.y = -VELOCITY; break;
      case sf::Keyboard::Down:  target_.y =  VELOCITY; break;

      case sf::Keyboard::Left:  target_.x = -VELOCITY; break;
      case sf::Keyboard::Right: target_.x =  VELOCITY; break;

      default: { }
    }
  } else if(event.type == sf::Event::KeyReleased) {
    switch(event.key.code) {
      case sf::Keyboard::Up:
      case sf::Keyboard::Down:  target_.y = 0; break;

      case sf::Keyboard::Left:
      case sf::Keyboard::Right: target_.x = 0; break;

      default: { }
    }
  }
}
