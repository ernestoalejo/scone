#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "common.h"

using namespace std;

class Level{

public:
	Level(string name);
	void update(float diff);
	void event(const sf::Event& event);
	void draw(RenderTarget& target,RenderStates states) const;

private:
	DISALLOW_COPY_AND_ASSIGN(Level);
	vector<Platform> platform;

};



#endif	