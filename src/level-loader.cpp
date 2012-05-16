

#include <fstream>
#include "level-loader.h"

using namespace std;


//clase LevelLoader
 
LevelLoader::LevelLoader(string name){          //Constructor
	Load(name); 
}

void LevelLoader::Load(string name){            //Funcion carga

	string dir("data/levels/" + name + "/info.lvl");
	fstream file(dir.c_str(), fstream::in);

	float x, y;
	int w, h, n;
	string tipo;

	file >> n;


	for(int i = 0 ; i < n ; i++){
		file >> tipo;
		file >> x;
		file >> y;
		file >> w;
		file >> h;

		Platform platformtmp(tipo,x,y,w,h);

		platforms[i] = platformtmp;
	}

	file.close();
}

vector<Platform> LevelLoader::getPlatform(){               //Devuelve vector
	return platforms;
}

// clase Platform

Platform::Platform(string tipo,float x,float y,int w,int h)
: pos(x,y) , size(w,h)
{
	//Vacio

}

sf::Vector2f Platform::getPos(){
	return pos;
}

sf::Vector2f Platform::getSize(){
	return size;
}