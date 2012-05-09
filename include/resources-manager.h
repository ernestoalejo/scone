#ifndef __RESOURCESMANAGER_H__
#define __RESOURCESMANAGER_H__


#include <SFML/Graphics.hpp>
#include "common.h"
#include <SFML/Audio.hpp>
#include <iostream>

class ResourcesManager{

public:
	ResourcesManager();
	void loadTextures(sf::Sprite& sprite, string name);
	~ResourcesManager(void);

private:
	DISALLOW_COPY_AND_ASSIGN(ResourcesManager);

	map<string, sf::Texture*> textures;
	map<string, sf::Music*> music;
	map<string, sf::Font*> fonts;

};

#endif