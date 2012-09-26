
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_SCONE_CAMERA_H_
#define INCLUDE_SCONE_CAMERA_H_


#include "scone/common.h"
#include "common/sprite.h"


/**
 * La clase camara sirve para que la camara se vaya moviendo y el personaje quede
 * en el centro.
 */
class Camera : public sf::Drawable {
public:
  /**
   * Constructor por defecto.
   * @param end El valor maximo hasta donde la camara va a llegar.
   */
  explicit Camera(int end);

  /**
   * Actualiza la camara para que siga al centro de la imagen y no se pase del
   * final de la imagen.
   */
  void update(float diff);

  /** @inheritDoc */
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  /**
   * Guarda la imagen que tiene que seguir la camara.
   */
  void follow(Sprite& sprite);

  /** @return El valor de la X que indica la posicion */
  int getX();

  /**
   * Cambia la posición de la camara, usar solo para pruebas.
   * @param pos Nuevo centro de la camara.
   */
  void setPos(Vector2f pos);


private:
  /**
   * Este es el objeto al que la camara va a seguir.
   */
  Sprite* sprite;

  /**
   * Indica donde esta el fin para que la camara deje de moverse y no se salga
   * del fondo.
   */
  int end;

  /**
   * Indica lo que se esta viendo en la camara.
   */
  sf::View view;

  DISALLOW_COPY_AND_ASSIGN(Camera);
};


#endif  // INCLUDE_SCONE_CAMERA_H_
