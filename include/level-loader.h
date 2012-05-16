

#ifndef __LEVELLOADER__H__
#define __LEVELLOADER__H__

#include "common.h"
#include <vector>


struct Platform{
	float x, y;
	int w, h;
};



class LevelLoader{
private:
	DISALLOW_COPY_AND_ASSIGN(LevelLoader);
	void Load(string name);
	vector<Platform> platforms(n); 


public:
	LevelLoader(string name);
	vector<Platform> Get();


};




#endif