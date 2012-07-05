#ifndef __COLLISION_SAT__H__
#define __COLLISION_SAT__H__

#include "common.h"

namespace collisions {


struct Circle {
	sf::Vector2f center;
	float radio;
};

struct Rect {
	sf::Vector2f pos;
	sf::Vector2f size;

	/**
	 * Matriz 3x3 que guarda las rotaciones y las escalas
	 */
	sf::Transform trans;
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
 * @param Ahorra calculos si estan alineados.
 * @return La informacion de la colision
 */
SATInfo SATRects(const Rect& a, const Rect& b, bool aligned);

/**
 * Comprueba si colisionan un circulo y un rectangulo
 * @param a Circulo.
 * @param b Rectangulo.
 * @return La informacion de la colision
 */
SATInfo SATCircleRect(const Circle& a, const Rect& b);

}

#endif
