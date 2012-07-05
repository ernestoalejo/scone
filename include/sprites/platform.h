#ifndef __SPRITES_PLATFORM_H__
#define __SPRITES_PLATFORM_H__

#include "common.h"
#include "sprite.h"

class Platform : public Sprite {
public:
	Platform(sf::FloatRect rect, string name);
	~Platform();

private:
	sf::Vector2f size;

};

#endif
