
#ifndef __CAMERA__H__
#define __CAMERA__H__

#include "common.h"
#include <SFML/Graphics.hpp>
#include "sprite.h"

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
  Camera(int end);

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

private:
  DISALLOW_COPY_AND_ASSIGN(Camera);

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

};
#endif
