
// Copyright 2012 The Scone authors.
// See LICENSE for more info.


#ifndef __BGSCROLLER_H__
#define __BGSCROLLER_H__

#include "scone/common.h"
#include "resources-manager.h"
#include "camera.h"

/**
 * Modulo para mover imagenes a partir del fondo.
 */
class BgScroller : public sf::Drawable {

private:
  DISALLOW_COPY_AND_ASSIGN(BgScroller);

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
  Camera* camera;

  /**
   * Guarda posicion horizontal.
   */
  float posx;

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


public:

  /**
   * Constructor.
   * @param manager Carga un recurso.
   * @param name Carga el nombre del recurso.
   * @param size Tamaño del recurso.
   */
  BgScroller(ResourcesManager& manager, string name, int size);

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
  void follow(Camera& camera);
};

#endif
