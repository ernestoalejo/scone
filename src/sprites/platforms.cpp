#include "platform.h"
#include "ResourcesManager.h"

Platform::Platform(sf::FloatRect rect, string name)
: size(rect.w,rect.h)
{
	ResourcesManager::getInstance().loadTexture(sprite, name);
	sprite.setPosition(rect.x, rect.y);
}

Platform::~Platform(){

}
