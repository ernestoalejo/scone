
#include "collisions/sat.h"

using namespace collisions;

inline sf::Vector2f normalize(const sf::Vector2f& v) {
	float  length = sqrt(v.x * v.x + v.y * v.y);
	return length == 0 ? v : sf::Vector2f(v.x / length, v.y / length);
}

SATInfo collisions::SATCircles(const Circle& a, const Circle& b) {
	SATInfo info;
	info.collides = false;
	float radiototal = a.radio + b.radio;
	float dx = (b.center.x - a.center.x);
	float dy = (b.center.y - a.center.y);
	if (dx * dx + dy * dy > radiototal * radiototal) {
		return info;
	}
	info.collides = true;
	info.direccion = normalize(sf::Vector2f(dx, dy));
	info.espacio = radiototal - sqrt(dx * dx + dy * dy);
	info.correccion = info.direccion * info.espacio;

	return info;
}

SATInfo collisions::SATRects(const Rect& a, const Rect& b, bool aligned) {

}

SATInfo collisions::SATCircleRect(const Circle& a, const Rect& b) {

}
