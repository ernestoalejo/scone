
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "common.h"
#include <SFML/Graphics.hpp>

class Sprite : public sf::Drawable {
	
private:
	DISALLOW_COPY_AND_ASSIGN(Sprite);
	
public:
	Sprite();
	
	// Implement the sf::Drawable interface
	virtual	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Functions made to been overwritten
	virtual void update(float diff);
	virtual void event(const sf::Event& event);

	sf::Vector2f position();

protected:
	sf::Vector2f velocity;
	sf::Texture texture;
	sf::Sprite sprite;


};

#endif
