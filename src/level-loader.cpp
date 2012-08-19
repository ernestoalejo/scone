#include <fstream>
#include "level-loader.h"

using namespace std;


//clase LevelLoader

LevelLoader::LevelLoader(string name) {         //Constructor
	Load(name);
}

void LevelLoader::Load(string name) {           //Funcion carga
	//Carga la informacion del nivel.
	string dir("data/levels/" + name + "/info.lvl");
	fstream file(dir.c_str(), fstream::in);

	float x, y;
	int w, h, n;
	string tipo;

	file >> n;
	levelSize = n;
	file >> n;

	platforms.resize(n);

	for (int i = 0 ; i < n ; i++) {
		file >> tipo;
		file >> x;
		file >> y;
		file >> w;
		file >> h;
		sf::FloatRect rect(x, y, w, h);
		Platform* platformtmp = new Platform(rect, tipo);

		platforms[i] = platformtmp;
	}

	file.close();
}

vector<Platform*> LevelLoader::getPlatform() {              //Devuelve vector
	return platforms;
}

int LevelLoader::getLevelSize() {
	return levelSize;
}
