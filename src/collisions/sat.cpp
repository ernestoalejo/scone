
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#include <limits>
#include <vector>

#include "collisions/sat.h"


using collisions::Circle;
using collisions::Rect;
using collisions::SATInfo;


inline sf::Vector2f normalize(const sf::Vector2f& v) {
  float  length = sqrt(v.x * v.x + v.y * v.y);
  return length == 0 ? v : sf::Vector2f(v.x / length, v.y / length);
}


inline sf::Vector2f normal(const sf::Vector2f& p1, const sf::Vector2f& p2) {
  return normalize(sf::Vector2f(p1.y - p2.y, p2.x - p1.x));
}


inline float dotProduct(const sf::Vector2f& p1, const sf::Vector2f& p2) {
  return p1.x * p2.x + p1.y * p2.y;
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


SATInfo SATPolygons(vector<sf::Vector2f>& verticesA,
                    vector<sf::Vector2f>& verticesB, sf::Vector2f& offset) {
  SATInfo info;
  info.collides = false;
  float shortestDist = std::numeric_limits<float>::max();

  int nsidesA = verticesA.size();
  int nsidesB = verticesB.size();

  for (int i = 0; i < nsidesA; i++) {
    // Calculates the normal vector between this vertex and the next one.
    sf::Vector2f nextVertice((i >= nsidesA - 1) ?
                             verticesA[0] : verticesA[i + 1]);
    sf::Vector2f axis(normal(verticesA[i], nextVertice));

    float min[2];
    float max[2];

    // Project figure A into the normal
    min[0] = dotProduct(axis, verticesA[0]);
    max[0] = min[0];

    for (int j = 1; j < nsidesA; j++) {
      float tmp = dotProduct(axis, verticesA[j]);

      if (tmp < min[0]) min[0] = tmp;
      if (tmp > max[0]) max[0] = tmp;
    }

    // Project figure B into the normal
    min[1] = dotProduct(axis, verticesB[0]);
    max[1] = min[1];

    for (int j = 1; j < nsidesB; j++) {
      float tmp = dotProduct(axis, verticesB[j]);

      if (tmp < min[1]) min[1] = tmp;
      if (tmp > max[1]) max[1] = tmp;
    }

    // Apply the offset to the A figure
    float sOffset = dotProduct(axis, offset);
    min[0] += sOffset;
    max[0] += sOffset;

    // Test for intersections
    if (min[0] - max[1] >= 0 || min[1] - max[0] >= 0)
      return info;

    // Save the results if it's the shortest path to get out
    // of the collision
    float distMin = max[1] - min[0];
    distMin = (distMin < 0) ? -distMin : distMin;

    if (distMin < shortestDist) {
      info.direccion = axis;
      info.espacio = distMin;
      shortestDist = distMin;
    }
  }

  info.collides = true;
  info.correccion = info.direccion * info.espacio;

  return info;
}


SATInfo SATPolygonCircle(vector<sf::Vector2f>& verticesA,
                         const Rect& a, const Circle& b, sf::Vector2f& offset) {
  SATInfo info;
  info.collides = false;
  float shortestDist = std::numeric_limits<float>::max();

  int nsidesA = verticesA.size();
  for (int i = 0; i < nsidesA; i++) {
    // Calculates the normal vector between this vertex and the next one.
    sf::Vector2f nextVertice((i >= nsidesA - 1) ?
                             verticesA[0] : verticesA[i + 1]);
    sf::Vector2f axis(normal(verticesA[i], nextVertice));

    float min[2];
    float max[2];

    // Project figure A into the normal
    min[0] = dotProduct(axis, verticesA[0]);
    max[0] = min[0];

    for (int j = 1; j < nsidesA; j++) {
      float tmp = dotProduct(axis, verticesA[j]);

      if (tmp < min[0]) min[0] = tmp;
      if (tmp > max[0]) max[0] = tmp;
    }

    // Project figure B into the normal
    min[1] = 0;
    max[1] = min[1] + b.radio;
    min[1] -= b.radio;

    // Apply the offset to the A figure
    float sOffset = dotProduct(axis, offset);
    min[0] += sOffset;
    max[0] += sOffset;

    // Test for intersections
    if (min[0] - max[1] >= 0 || min[1] - max[0] >= 0)
      return info;

    // Save the results if it's the shortest path to get out
    // of the collision
    float distMin = max[1] - min[0];
    distMin = (distMin < 0) ? -distMin : distMin;

    if (distMin < shortestDist) {
      info.direccion = axis;
      info.espacio = distMin;
      shortestDist = distMin;
    }
  }

  info.collides = true;
  info.correccion = info.direccion * info.espacio;

  return info;
}

SATInfo collisions::SATRects(const Rect& a, const Rect& b, bool aligned) {
  vector<sf::Vector2f> va(4);
  va[0] = a.trans.transformPoint(0, 0);
  va[1] = a.trans.transformPoint(a.size.x, 0);
  va[2] = a.trans.transformPoint(a.size.x, a.size.y);
  va[3] = a.trans.transformPoint(0, a.size.y);

  vector<sf::Vector2f> vb(4);
  vb[0] = b.trans.transformPoint(0, 0);
  vb[1] = b.trans.transformPoint(b.size.x, 0);
  vb[2] = b.trans.transformPoint(b.size.x, b.size.y);
  vb[3] = b.trans.transformPoint(0, b.size.y);

  // Offset between the two figures
  sf::Vector2f offset(a.pos.x - b.pos.x, a.pos.y - b.pos.y);

  SATInfo info = SATPolygons(va, vb, offset);
  if (!aligned && !info.collides) {
    info = SATPolygons(vb, va, offset);
  }
  return info;
}


SATInfo collisions::SATCircleRect(const Circle& b, const Rect& a) {
  vector<sf::Vector2f> va(4);
  va[0] = a.trans.transformPoint(0, 0);
  va[1] = a.trans.transformPoint(a.size.x, 0);
  va[2] = a.trans.transformPoint(a.size.x, a.size.y);
  va[3] = a.trans.transformPoint(0, a.size.y);

  sf::Vector2f offset(a.pos.x - b.center.x, a.pos.y - b.center.y);

  return SATPolygonCircle(va, a, b, offset);
}
