#ifndef __BGSCROLLER_H__
#define __BGSCROLLER_H__

#include "common.h"
#include "resources-manager.h"
#include <SFML/Graphics.hpp>
#include <vector>

class BgScroller :public sf::Drawable {

private:
	DISALLOW_COPY_AND_ASSIGN(BgScroller);
	vector<sf::Sprite> sprites;
	int current, size;
	Camera* camera;
    float posx;
	bool drawNext;
	float bgWidth, halfBgWidth;

public:
	 BgScroller(ResourcesManager& manager, string name, int size);
	~BgScroller();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(float diff);

	void follow(Camera& camera);
};

#endif