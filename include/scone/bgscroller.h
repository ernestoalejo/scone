
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#ifndef INCLUDE_SCONE_BGSCROLLER_H_
#define INCLUDE_SCONE_BGSCROLLER_H_


#include <string>
#include <vector>

#include "scone/common.h"
#include "scone/resources-manager.h"
#include "scone/camera.h"


/**
 * Modulo para mover imagenes a partir del fondo.
 */
class BgScroller : public sf::Drawable {
public:
  /**
   * Constructor.
   * @param name Carga el nombre del recurso.
   * @param size Tamaño del recurso.
   */
  BgScroller(string name, int size);

  /**
   * Destructor.
   */
  ~BgScroller();

  /** @inheridDoc */
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  /**
   * Actualiza fondo.
   * @param diff cantidad de segundos pasados tras el anterior fondo.
   */
  void update(float diff);

  /**
   * Asigna a la camara.
   * @param camera Camara a la que se le sigue.
   */
  void follow(const Camera& camera);


private:
  /**
   * Vector de imagenes.
   */
  vector<sf::Sprite> sprites;

  /**
   * La imagen actual.
   */
  int current;

  /**
   * Tamaño de la imagen actual.
   */
  int size;

  /**
   * Carga la camara.
   */
  const Camera* camera;

  /**
   * Indica si hay espacio para dibujar la siguiente imagen.
   */
  bool drawNext;

  /**
   * Anchura de la imagen.
   */
  float bgWidth;

  /**
   * Mitad del ancho de la imagen.
   */
  float halfBgWidth;

  DISALLOW_COPY_AND_ASSIGN(BgScroller);
};


#endif  // INCLUDE_SCONE_BGSCROLLER_H_
