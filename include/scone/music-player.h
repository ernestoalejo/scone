
// Copyright 2012 The Scone authors.
// See LICENSE for more info.

#ifndef INCLUDE_SCONE_MUSIC_PLAYER_H_
#define INCLUDE_SCONE_MUSIC_PLAYER_H_


#include <vector>

#include "scone/common.h"


class MusicPlayer {
public:
  MusicPlayer();
  ~MusicPlayer();

  void add(sf::Music& track);
  void play();
  void stop();

  void update(float diff);

  void chooseRandom();

  int getCurrent();
  int getSize();
  bool isPlaying();


private:
  vector <sf::Music*> music;
  int current;
  int size;
  bool playing;

  void next();

  DISALLOW_COPY_AND_ASSIGN(MusicPlayer);
};


#endif  // INCLUDE_SCONE_MUSIC_PLAYER_H_
