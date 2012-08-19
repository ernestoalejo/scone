
#include "music-player.h"


MusicPlayer::MusicPlayer()
  : current(-1) , size(0) , playing(false) {
  // vacio
}

MusicPlayer::~MusicPlayer() {
  // vacio
}

void MusicPlayer::add(sf::Music& track) {
  music.push_back(&track);
  size++;
}

void MusicPlayer::play() {
  if (playing || size == 0)
    return;
  playing = true;
  next();
}

void MusicPlayer::next() {
  current++;
  if (current == size)
    current = 0;
  music[current]->play();
}

void MusicPlayer::stop() {
  if (!playing || size == 0)
    return;
  playing = false;
  music[current]->stop();
}

void MusicPlayer::update(float diff) {
  if (playing && music[current]->getStatus() == sf::SoundSource::Stopped)
    next();
}

void MusicPlayer::chooseRandom() {
  if (playing || size == 0)
    return;
  current = rand() % size;
}

int MusicPlayer::getCurrent() {
  return current;
}

int MusicPlayer::getSize() {
  return size;
}

bool MusicPlayer::isPlaying() {
  return playing;
}
