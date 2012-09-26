
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_SCONE_MUSIC_PLAYER_H_
#define INCLUDE_SCONE_MUSIC_PLAYER_H_


#include <vector>

#include "scone/common.h"


/**
 * Sirve para darle sonido al juego mientras jugamos.
 */
class MusicPlayer {
public:
  MusicPlayer();
  ~MusicPlayer();

  /**
   * Añadir una nueva canción a la lista.
   * @param track La canción que queremos guardar.
   */
  void add(sf::Music& track);

  /**
   * Reproduce la lista de canciónes.
   */
  void play();

  /**
   * Parar de reproducir la lista de canciónes.
   */
  void stop();

  /**
   * Actualiza la información del reproductor cada frame.
   * @param diff Tiempo que ha durado el último frame.
   */
  void update(float diff);

  /**
   * Elige una canción aleatoriamente.
   */
  void chooseRandom();

  /**
   * @return El nº de canción actual.
   */
  int getCurrent();

  /** @return El nº de canciones. */
  int getSize();

  /**
   * @return Si esta sonando.
   */
  bool isPlaying();

private:
  /**
  * Para guardar las canciones.
  */
  vector<sf::Music*> music;

  /** @return Canción actual. */
  int current;

  /** @return Tamaño actual. */
  int size;

  /** Sonando o no. */
  bool playing;

  /** Pasa a la siguiente canción. */
  void next();

  DISALLOW_COPY_AND_ASSIGN(MusicPlayer);
};


#endif  // INCLUDE_SCONE_MUSIC_PLAYER_H_
