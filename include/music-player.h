
#ifndef __MUSICPLAYER__H__
#define __MUSICPLAYER__H__ 

#include "common.h"
#include <SFML/Audio.hpp>


class MusicPlayer {
public:
	MusicPlayer();
	~MusicPlayer();

	void add(sf::Music& track);
	void play();
	void stop();
	void update();

	void chooseRandom();

private:
	DISALLOW_COPY_AND_ASSIGN(MusicPlayer);

	vector <sf::Music*> music;
	int current;
	int size;
	bool playing;
	
	void next();
};




#endif
