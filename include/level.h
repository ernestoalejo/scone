#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <SFML/Graphics.hpp>

#include "common.h"
#include "level-loader.h"


class Level{

public:
	Level(string name);
	void update(float diff);
	void event(const sf::Event& event);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	DISALLOW_COPY_AND_ASSIGN(Level);
	vector<Platform> platform;

};



#endif	
