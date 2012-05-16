
#include "resources-manager.h"

//Constructor por defecto
ResourcesManager::ResourcesManager() {
	//vacio.
}

//Para cargar imagenes en formato ".png"
void ResourcesManager::loadTextures(sf::Sprite &sprite, string name) {
 	sf::Texture* objetotextura = 0;

	if(textures.count(name) > 0)
		objetotextura = textures[name];
	
	if(objetotextura == 0){
		LOG << " * Cargando imagen " << name << "..." << endl;

		objetotextura = new sf::Texture ();
		string dir(datoprivado + "/textures/" + name + ".png");
		if(!objetotextura->loadFromFile(dir))
			ERROR << "Error cargando imagen " << dir << endl;

		textures[name] = objetotextura;
	}

	sprite.setTexture(*objetotextura, true);

	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width/2, bounds.height/2);
}

//Para cargar musica en formato ".ogg"
sf::Music &ResourcesManager::loadMusic(string name){

	if(music.count(name) > 0)
		return *music[name];

	LOG << " * Cargando musica " << name << "..." << endl;

	music[name] = new sf::Music ();
	string dir(datoprivado + "/music/" + name + ".ogg");
	if(!music[name]->openFromFile(dir))
		ERROR << "Error cargando musica " << dir << endl;
	return *music[name];
}

//Para cargar fonts en formato ".ttf"
const sf::Font &ResourcesManager::loadFont(const string &name){
	if(fonts.count(name) > 0){
		return *fonts[name];
	}
	//Si no esta cargado, lo carga desde disco.
	LOG << " * Cargando fuentes " << name << "..." << endl;
	
	fonts[name] = new sf::Font();
	string dir(datoprivado + "/fonts/" + name + ".ttf");
	if(!fonts[name]->loadFromFile(dir))
		ERROR << "Error cargando fuente " << dir << endl;
	return *fonts[name];

}

//Destructor
ResourcesManager::~ResourcesManager(void) {
	//Para texturas.
	{
		typedef map<string, sf::Texture*>::const_iterator iterator;
		for(iterator i = textures.begin(); i != textures.end(); ++i){
			delete i->second;
		}
	}
	//Para musica.
	{
		typedef map<string, sf::Music*>::const_iterator iterator;
		for(iterator i = music.begin(); i != music.end(); ++i){
			delete i->second;
		}
	}
	//Para fuentes.
	{
		typedef map<string, sf::Font*>::const_iterator iterator;
		for(iterator i = fonts.begin(); i != fonts.end(); ++i){
			delete i->second;
		}
	}
}
