
#include "music-player.h"


MusicPlayer::MusicPlayer()
: current(-1) , size(0) , playing(false)
{
	// vacio
}

MusicPlayer::~MusicPlayer() {
	// vacio
}

void MusicPlayer::add(sf::Music& track) {
	music[size] = &track;
	size++;
}

void MusicPlayer::play() {
	if (playing)
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
	if(!playing)
		return;
	playing = false;
	music[current]->stop();
}

void MusicPlayer::update() {
	if(playing && music[current]->getStatus() == sf::SoundSource::Stopped)
		next();
}

void MusicPlayer::chooseRandom() {
	if(playing)
		return;
	current = rand() % size;
}
