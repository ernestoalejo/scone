#ifndef __SPRITES_PLATFORM_H__
#define __SPRITES_PLATFORM_H__

#include "common.h"

class Platform {
public:
	Platform(sf::FloatRect rect, string name);
	~Platform();

private:
	sf::Vector2f size;

};

#endif
