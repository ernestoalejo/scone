
#ifndef __CAMERA__H__
#define __CAMERA__H__ 

#include "common.h"
#include <SFML/Graphics.hpp>
#include "sprite.h"

class Camera : public sf::Drawable {
	
private:
	DISALLOW_COPY_AND_ASSIGN(Camera);
	
	Sprite *sprite;
	int end;
	sf::View view;

public:
	Camera(int end);
	
	void update (float diff);
	
	void draw (sf::RenderTarget& target, sf::RenderStates states) const;
	
	void follow (Sprite& sprite);

	int getX();

	
};
#endif
