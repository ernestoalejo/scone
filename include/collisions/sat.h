
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_COLLISIONS_SAT_H_
#define INCLUDE_COLLISIONS_SAT_H_


#include "scone/common.h"
#include "collisions/structs.h"


namespace collisions {


/**
 * Comprueba si colisionan dos circulos
 * @param a Circulo 1.
 * @param b Circulo 2.
 * @return La informacion de la colision
 */
SATInfo SATCircles(const Circle& a, const Circle& b);


/**
 * Comprueba si colisionan dos rectangulos
 * @param a Rectangulo 1.
 * @param b Rectangulo 2.
 * @return La informacion de la colision
 */
SATInfo SATRects(const Rect& a, const Rect& b);


/**
 * Comprueba si colisionan un circulo y un rectangulo
 * @param a Circulo.
 * @param b Rectangulo.
 * @return La informacion de la colision
 */
SATInfo SATCircleRect(const Circle& a, const Rect& b);


}   // namespace collisions


#endif  // INCLUDE_COLLISIONS_SAT_H_
