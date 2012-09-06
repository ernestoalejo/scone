
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


/*
Info SATPolygons(vector<Vector2f>& verticesA,
                    vector<Vector2f>& verticesB, Vector2f& offset) {
  Info info;
  info.collides = false;
  float shortestDist = std::numeric_limits<float>::max();

  int nsidesA = verticesA.size();
  int nsidesB = verticesB.size();

  for (int i = 0; i < nsidesA; i++) {
    // Calculates the normal vector between this vertex and the next one.
    Vector2f nextVertice((i >= nsidesA - 1) ?
                             verticesA[0] : verticesA[i + 1]);
    Vector2f axis(normal(verticesA[i], nextVertice));

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


Info SATPolygonCircle(vector<Vector2f>& verticesA,
                         const Rect& a, const Circle& b, Vector2f& offset) {
  Info info;
  info.collides = false;
  float shortestDist = std::numeric_limits<float>::max();

  int nsidesA = verticesA.size();
  for (int i = 0; i < nsidesA; i++) {
    // Calculates the normal vector between this vertex and the next one.
    Vector2f nextVertice((i >= nsidesA - 1) ?
                             verticesA[0] : verticesA[i + 1]);
    Vector2f axis(normal(verticesA[i], nextVertice));

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

Info collisions::SATRects(const Rect& a, const Rect& b) {
  sf::Transform atrans(a.getInverse());
  sf::Transform btrans(b.getInverse());

  vector<Vector2f> va(4);
  va[0] = atrans.transformPoint(0, 0);
  va[1] = atrans.transformPoint(a.size.x, 0);
  va[2] = atrans.transformPoint(a.size.x, a.size.y);
  va[3] = atrans.transformPoint(0, a.size.y);

  vector<Vector2f> vb(4);
  vb[0] = btrans.transformPoint(0, 0);
  vb[1] = btrans.transformPoint(b.size.x, 0);
  vb[2] = btrans.transformPoint(b.size.x, b.size.y);
  vb[3] = btrans.transformPoint(0, b.size.y);

  // Offset between the two figures
  Vector2f offset(a.pos.x - b.pos.x, a.pos.y - b.pos.y);

  Info info = SATPolygons(va, vb, offset);
  if (a.angle != b.angle && !info.collides) {
    info = SATPolygons(vb, va, offset);
  }
  return info;
}


Info collisions::SATCircleRect(const Circle& b, const Rect& a) {
  sf::Transform atrans(a.getInverse());

  vector<Vector2f> va(4);
  va[0] = atrans.transformPoint(0, 0);
  va[1] = atrans.transformPoint(a.size.x, 0);
  va[2] = atrans.transformPoint(a.size.x, a.size.y);
  va[3] = atrans.transformPoint(0, a.size.y);

  Vector2f offset(a.pos.x - b.center.x, a.pos.y - b.center.y);

  return SATPolygonCircle(va, a, b, offset);
}
*/
