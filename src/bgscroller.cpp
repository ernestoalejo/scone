#include "resources-manager.h"
#include "bgscroller.h"
#include <sstream>

BgScroller::BgScroller(ResourcesManager& manager, string name, int size)
: sprites(size), size(size), posx(0), bgWidth(-1)
{
	for(int i = 0; i < size; i++) {
		stringstream nombre;
		nombre << name << "/" << i;
		manager.loadTextures(sprites[i], nombre.str());

		if(bgWidth < 0) {
			bgWidth = sprites[i].getLocalBounds().width;
			halfBgWidth = bgWidth / 2;
		}

		sprites[i].setPosition(i * bgWidth + halfBgWidth, HALF_SCREEN_HEIGHT);
	}
}

BgScroller::~BgScroller() {
	// vacio
}

void BgScroller::update(float diff) {
	posx = camera->getX();
	//posx+=0.1;

	current = (posx / bgWidth);

	drawNext = false;
	if(sprites[current].getPosition().x + halfBgWidth < posx + SCREEN_WIDTH)
		drawNext = true;
}

void BgScroller::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprites[current]);
	if(drawNext)
		target.draw(sprites[current+1]);
}


void BgScroller::follow(Camera& camera) {
	this->camera = &camera;
}
