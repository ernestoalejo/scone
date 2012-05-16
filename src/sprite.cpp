
#include "sprite.h"

Sprite::Sprite() :
	velocity(0, 0)
{
	// empty
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

void Sprite::update(float diff) {
  sprite.move(velocity * diff);
}

void Sprite::event(const sf::Event& event) {
	// empty
}

sf::Vector2f Sprite::position() {
	return sprite.getPosition();
}
