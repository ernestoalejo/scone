
#include "resources-manager.h"

ResourcesManager::ResourcesManager(){
	//vacio.
}

void ResourcesManager::loadTextures(sf::Sprite& sprite, string name){
 	sf::Texture* objetotextura=0;

	if(textures.count(name)>0)
		objetotextura = textures[name];
	
	if(objetotextura==0){
		cout << "Cargando imagen " << name << ".png" << endl;
		objetotextura = new sf::Texture ();
		string dir("data/textures/" + name + ".png");
		if(!objetotextura->loadFromFile(dir))
			cerr << "Error cargando imagen " << dir << endl;
		textures[name]=objetotextura;
	}

	sprite.setTexture(*objetotextura, true);

	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width/2, bounds.height/2);
}

ResourcesManager::~ResourcesManager(void){
//Para texturas
	{
		typedef map<string, sf::Texture*>::const_iterator iterator;
		for(iterator i = textures.begin(); i != textures.end(); ++i){
			delete i->second;
		}
	}




	/*cout << " * Deleting textures...";
		typedef map<string, sf::Texture*>::const_iterator iterator;
		for(iterator it = textures.begin(); it != textures.end(); ++it) {
			delete it->second;
		}
		cout << "Done!" << endl;*/
}