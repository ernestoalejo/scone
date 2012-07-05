#ifndef __LEVELLOADER__H__
#define __LEVELLOADER__H__

#include "common.h"
#include "sprites/platform.h"

class LevelLoader{
private:
	DISALLOW_COPY_AND_ASSIGN(LevelLoader);
	void Load(string name);
	vector<Platform*> platforms; 


public:
	LevelLoader(string name);
	vector<Platform*> getPlatform();


};




#endif