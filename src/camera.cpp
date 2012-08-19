
#include "camera.h"

Camera::Camera(int end) {
	this->end = end;
}


void Camera::update(float diff) {
	float posx = sprite->position().x;

	if (posx < HALF_SCREEN_WIDTH) {
		posx = HALF_SCREEN_WIDTH;
	}

	if (posx > end - HALF_SCREEN_WIDTH) {
		posx = end - HALF_SCREEN_WIDTH;
	}

	view.setCenter(posx, HALF_SCREEN_HEIGHT);
}


void Camera::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.setView(view);
}


void Camera::follow(Sprite& sprite) {
	this->sprite = &sprite;
}

int Camera::getX() {
	return view.getCenter().x - SCREEN_WIDTH / 2;
}
