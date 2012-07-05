#include "sprites/platform.h"
#include "resources-manager.h"

Platform::Platform(sf::FloatRect rect, string name)
: size(rect.width,rect.height)
{
	ResourcesManager::getInstance().loadTextures(sprite, name);
	sprite.setPosition(rect.left, rect.top);
}

Platform::~Platform(){

}
