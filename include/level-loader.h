

#ifndef __LEVELLOADER__H__
#define __LEVELLOADER__H__

#include "common.h"
#include <vector>
#include <SFML/Graphics.hpp>


class Platform{
private:
	sf::Vector2f pos;
	sf::Vector2f size;
	string tipo;

public:
	Platform(string tipo,float x,float y,int w,int h);
	sf::Vector2f getPos();
	sf::Vector2f getSize();

};



class LevelLoader{
private:
	DISALLOW_COPY_AND_ASSIGN(LevelLoader);
	void Load(string name);
	vector<Platform> platforms; 


public:
	LevelLoader(string name);
	vector<Platform> getPlatform();


};




#endif