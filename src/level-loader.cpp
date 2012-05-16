

#include <fstream>
#include "level-loader.h"

using namespace std;
 
LevelLoader::LevelLoader(string name){          //Constructor
	Load(name); 
}

void LevelLoader::Load(string name){            //Funcion carga

	string dir("data/levels/" + name + "/info.lvl");
	fstream file(dir.c_str(), fstream::in);

	float x, y;
	int w, h, n;
	file >> n;


	for(int i = 0 ; i < n ; i++){
		file >> x;
		file >> y;
		file >> w;
		file >> h;

		Platform platformtmp;
		platformtmp.x = x;
		platformtmp.y = y;
		platformtmp.w = w;
		platformtmp.h = h;

		platforms[i] = platformtmp;
	}

	file.close();
}

vector<Platform> LevelLoader::Get(){               //Devuelve vector
	return platforms;
}

