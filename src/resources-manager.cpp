
#include "resources-manager.h"


ResourcesManager::ResourcesManager() {
	//vacio.
}

void ResourcesManager::loadTextures(sf::Sprite& sprite, string name) {
 	sf::Texture* objetotextura = 0;

	if(textures.count(name) > 0)
		objetotextura = textures[name];
	
	if(objetotextura == 0){
		LOG << " * Cargando imagen " << name << "..." << endl;

		objetotextura = new sf::Texture ();
		string dir("data/textures/" + name + ".png");
		if(!objetotextura->loadFromFile(dir))
			ERROR << "Error cargando imagen " << dir << endl;

		textures[name] = objetotextura;
	}

	sprite.setTexture(*objetotextura, true);

	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width/2, bounds.height/2);
}

sf::Music &ResourcesManager::loadMusic( string name){

	if(music.count(name) > 0)
		return *music[name];

	LOG << " * Cargando musica " << name << "..." << endl;

	music[name] = new sf::Music ();
	string dir("data/music/" + name + ".ogg");
	if(!music[name]->openFromFile(dir))
		ERROR << "Error cargando musica " << dir << endl;
	return *music[name];

}

ResourcesManager::~ResourcesManager(void) {
	//Para texturas
	{
		typedef map<string, sf::Texture*>::const_iterator iterator;
		for(iterator i = textures.begin(); i != textures.end(); ++i){
			delete i->second;
		}
	}
}
