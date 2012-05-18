
#include "resources-manager.h"
#include "gtest/gtest.h"


TEST(ResourcesManagerTest, CacheTextures) {
	ResourcesManager manager("test");

	EXPECT_EQ(manager.getTexturesCacheSize(), 0);

	sf::Sprite sprite;

	manager.loadTextures(sprite, "test");
	EXPECT_EQ(manager.getTexturesCacheSize(), 1);

	manager.loadTextures(sprite, "test2");
	EXPECT_EQ(manager.getTexturesCacheSize(), 2);

	manager.loadTextures(sprite, "test");
	EXPECT_EQ(manager.getTexturesCacheSize(), 2);
}


TEST(ResourcesManagerTest, CacheFonts) {
	ResourcesManager manager("test");

	EXPECT_EQ(manager.getFontsCacheSize(), 0);

	manager.loadFont("test");
	EXPECT_EQ(manager.getFontsCacheSize(), 1);

	manager.loadFont("test2");
	EXPECT_EQ(manager.getFontsCacheSize(), 2);

	manager.loadFont("test");
	EXPECT_EQ(manager.getFontsCacheSize(), 2);
}


TEST(ResourcesManagerTest, CacheMusic) {
	ResourcesManager manager("test");

	EXPECT_EQ(manager.getMusicCacheSize(), 0);

	manager.loadMusic("test");
	EXPECT_EQ(manager.getMusicCacheSize(), 1);

	manager.loadMusic("test2");
	EXPECT_EQ(manager.getMusicCacheSize(), 2);

	manager.loadMusic("test");
	EXPECT_EQ(manager.getMusicCacheSize(), 2);
}
