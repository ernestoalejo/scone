
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_COLLISIONS_CIRCLES_H_
#define INCLUDE_COLLISIONS_CIRCLES_H_


#include "scone/common.h"
#include "collisions/structs.h"


namespace collisions {


/**
 * Comprueba si colisionan dos circulos
 * @param a Circulo 1.
 * @param b Circulo 2.
 * @return La informacion de la colision
 */
Info Circles(const Circle& a, const Circle& b);


}   // namespace collisions


#endif  // INCLUDE_COLLISIONS_CIRCLES_H_
