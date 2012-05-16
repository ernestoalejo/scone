#ifndef __RESOURCESMANAGER_H__
#define __RESOURCESMANAGER_H__

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "common.h"


class ResourcesManager {
public:
	ResourcesManager(string);
	~ResourcesManager(void);

	void loadTextures(sf::Sprite& sprite, string name);
	sf::Music &loadMusic( string name);
	const sf::Font &loadFont(const string &name);

private:
	DISALLOW_COPY_AND_ASSIGN(ResourcesManager);
	string datoprivado;
	map<string, sf::Texture*> textures;
	map<string, sf::Music*> music;
	map<string, sf::Font*> fonts;
};

#endif
