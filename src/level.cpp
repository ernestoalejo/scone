#include "level.h"
#include <iostream>


using namespace std;

Level::Level(string name){
	LevelLoader datos(name);
	platform = datos.getPlatform();
}

void Level::update(float diff){


}

void Level::event(const sf::Event& event){


}

void Level::draw(RenderTarget& target,RenderStates states) const {
	
}