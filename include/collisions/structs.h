
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_COLLISIONS_STRUCTS_H_
#define INCLUDE_COLLISIONS_STRUCTS_H_


#include "scone/common.h"


namespace collisions {


struct Info {
  bool collides;
  sf::Vector2f escape, direction;
};


struct Circle {
  sf::Vector2f center;
  float radio;
};


struct Rect {
  sf::Vector2f pos, size, scale;
  float angle;

  sf::Transform getInverse() const {
    sf::Vector2f center(size.x / 2, size.y / 2);

    sf::Transform t;
    t = t.scale(scale, center).getInverse();
    t.translate(-pos);

    if (angle != 0)
      t.rotate(-angle, center);

    return t;
  }
};


struct SATInfo {
  bool collides;

  /**
   * Vector que indica la direccion y sentido para que el objeto deje de colisionar
   */
  sf::Vector2f direccion;

  /**
   * Es el tamaño del espacio que hay hasta que dejen de colisionar los dos objetos
   */
  float espacio;

  /**
   * Si restas este vector al primer objeto sale de la colision
   */
  sf::Vector2f correccion;
};


}   // namespace collisions


#endif  // INCLUDE_COLLISIONS_STRUCTS_H_
