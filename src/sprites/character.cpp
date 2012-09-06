
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include <algorithm>

#include "scone/resources-manager.h"
#include "sprites/character.h"
#include "collisions/points.h"


const float VELOCITY = 5;
const float JUMP_VELOCITY = 20;
const float ACCELERATION = 0.2;
const float THRESHOLD = 0.07;
const float GRAVITY = 15;
const float DECELERATION = 1;


Character::Character()
  : target(0, GRAVITY), jump(false),
    targetDisplay("target", sf::Font::getDefaultFont(), 15),
    velDisplay("vel", sf::Font::getDefaultFont(), 15) {
  ResourcesManager::getInstance().loadTextures(sprite, "character");
  sprite.setPosition(HALF_SCREEN_WIDTH, HALF_SCREEN_HEIGHT);
  calcSize();

  velDisplay.setPosition(0, 15);
  targetDisplay.setPosition(0, 30);
}


void Character::update(float diff) {
  sf::Vector2f oldPos(sprite.getPosition());

  // Prepare the velocity and target texts
  stringstream velText;
  velText << vel.x << ", " << vel.y;
  velDisplay.setString(velText.str());

  stringstream targetText;
  targetText << target.x << ", " << target.y;
  targetDisplay.setString(targetText.str());

  // Change the velocity to reach the target
  vel = target * ACCELERATION + vel * (1 - ACCELERATION);

  // Jump to zero if the velocity is near it
  if (fabs(vel.x) < THRESHOLD)
    vel.x = 0;

  if (fabs(vel.y) < THRESHOLD) {
    vel.y = 0;

    if (jump)
      target.y = -JUMP_VELOCITY;
  }

  // Move the sprite according to the velocity
  sprite.move(vel);

  sf::Vector2f pos(sprite.getPosition());
  bool collided = false;

  collided = collidesWithPlatforms(oldPos, pos);

  if (pos.y >= 450) {
    // Stop the falling of the char if needed
    if (target.y > 0)
      target.y = vel.y = 0;

    // Don't let the char go down this line
    pos.y = 450;
    collided = true;
  }

  // Apply gravity
  if (target.y < 0 || !collided)
    target.y = min(target.y + DECELERATION, GRAVITY);

  sprite.setPosition(pos);
}


void Character::event(const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code) {
    case sf::Keyboard::Up:
      jump = true;
      break;

    case sf::Keyboard::Left:
      target.x = -VELOCITY;
      break;

    case sf::Keyboard::Right:
      target.x =  VELOCITY;
      break;

    default:
    { }
    }
  } else if (event.type == sf::Event::KeyReleased) {
    switch (event.key.code) {
    case sf::Keyboard::Left:
      if (target.x == -VELOCITY)
        target.x = 0;
      break;

    case sf::Keyboard::Right:
      if (target.x == VELOCITY)
        target.x = 0;
      break;

    case sf::Keyboard::Up:
      jump = false;
      break;

    default:
    { }
    }
  }
}


void Character::setLevel(const Level& level) {
  platforms = level.getPlatform();
}


void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  Sprite::draw(target, states);

  sf::View v = target.getView();
  target.setView(target.getDefaultView());

  target.draw(targetDisplay);
  target.draw(velDisplay);

  target.setView(v);
}


bool Character::collidesWithPlatforms(const sf::Vector2f& oldPos,
                                      sf::Vector2f& pos) {
  sf::Vector2f p(pos.x, pos.y + size.y / 2 + 1);
  sf::Vector2f oldP(oldPos.x, oldPos.y + size.y / 2 - 1);

  for (unsigned int i = 0; i < platforms.size(); i++) {
    // Test the bottom point against the platform
    collisions::Rect r(platforms[i]->getCollisionRect());
    collisions::Info info(collisions::PointRect(p, r));

    if (info.collides) {
      float dy = (p.y - r.pos.y - 1);
      if (target.y > 0 && oldP.y < r.pos.y) {
        // Stop the char inmediatly without deacceleration
        // when the ground is hitted
        target.y = vel.y = 0;

        // Escape from the collision
        pos.y -= dy;

        // Change the collision flag
        return true;
      } else if (dy == 0) {
        // If the char is stopped in a platform, don't flicker
        // continously down and up
        return true;
      }

      // Escape early if a collision it's found
      // but no action is required
      return false;
    }
  }

  return false;
}
