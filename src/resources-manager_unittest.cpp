#include "resources-manager.h"
#include "gtest/gtest.h"

// Pruebas automatizadas.
// Imagenes.
TEST(ResourcesManagerTest, Imagenes){
	sf::Sprite a;
	ResourcesManager prueba("test");
	EXPECT_EQ(prueba.getTexturesCacheSize(), 0);
	prueba.loadTextures(a, "test");
	EXPECT_EQ(prueba.getTexturesCacheSize(), 1);
	prueba.loadTextures(a, "test2");
	EXPECT_EQ(prueba.getTexturesCacheSize(), 2);
	prueba.loadTextures(a, "test3");
	EXPECT_EQ(prueba.getTexturesCacheSize(), 3);
}

// Musica.
TEST(ResourcesManagerTest, Musica){
	ResourcesManager prueba("test");
	EXPECT_EQ(prueba.getMusicCacheSize(), 0);
	prueba.loadMusic("test");
	EXPECT_EQ(prueba.getMusicCacheSize(), 1);
	prueba.loadMusic("test2");
	EXPECT_EQ(prueba.getMusicCacheSize(), 2);
	prueba.loadMusic("test3");
	EXPECT_EQ(prueba.getMusicCacheSize(), 3);
}

// Fuentes.
TEST(ResourcesManagerTest, Fuentes){
	ResourcesManager prueba("test");
	EXPECT_EQ(prueba.getFontsCacheSize(), 0);
	prueba.loadFont("test");
	EXPECT_EQ(prueba.getFontsCacheSize(), 1);
	prueba.loadFont("test2");
	EXPECT_EQ(prueba.getFontsCacheSize(), 2);
	prueba.loadFont("test3");
	EXPECT_EQ(prueba.getFontsCacheSize(), 3);
}

