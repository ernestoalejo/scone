
#include "level.h"


Level::Level(string name){
	LevelLoader datos(name);
	platform = datos.getPlatform();
}

void Level::update(float diff){


}

void Level::event(const sf::Event& event){


}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	
}
