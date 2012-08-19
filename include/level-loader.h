#ifndef __LEVELLOADER__H__
#define __LEVELLOADER__H__

#include "common.h"
#include "sprites/platform.h"

class LevelLoader {

public:
	LevelLoader(string name);
	vector<Platform*> getPlatform();
	int getLevelSize();

private:
	DISALLOW_COPY_AND_ASSIGN(LevelLoader);
	void Load(string name);
	vector<Platform*> platforms;
	int levelSize;

};


#endif