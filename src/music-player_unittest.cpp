#include "music-player.h"
#include "gtest/gtest.h"

TEST(MusicPlayerTest, Anadir) {
	MusicPlayer Prueba;
	EXPECT_EQ(Prueba.getSize(), 0);

	sf::Music cancion;
	Prueba.add(cancion);
	EXPECT_EQ(Prueba.getSize(), 1);
}

TEST(MusicPlayerTest, Play) {
	MusicPlayer Prueba;
	Prueba.play();
	EXPECT_FALSE(Prueba.isPlaying());

	sf::Music cancion;
	Prueba.add(cancion);
	Prueba.play();
	EXPECT_TRUE(Prueba.isPlaying());
}

TEST(MusicPlayerTest, PasaCancion) {
	MusicPlayer Prueba;

	sf::Music cancion1;
	sf::Music cancion2;
	sf::Music cancion3;
	Prueba.add(cancion1);
	Prueba.add(cancion2);
	Prueba.add(cancion3);

	Prueba.play();
	EXPECT_EQ(Prueba.getCurrent(), 0);
	Prueba.update(0);
	EXPECT_EQ(Prueba.getCurrent(), 1);
	Prueba.update(0);
	EXPECT_EQ(Prueba.getCurrent(), 2);
	Prueba.update(0);
	EXPECT_EQ(Prueba.getCurrent(), 0);
}

TEST(MusicPlayerTest, Parar) {
	MusicPlayer Prueba;

	sf::Music cancion;
	Prueba.add(cancion);
	Prueba.play();
	EXPECT_TRUE(Prueba.isPlaying());
	Prueba.stop();
	EXPECT_FALSE(Prueba.isPlaying());
}

TEST(MusicPlayerTest, Aleatorio) {
	MusicPlayer Prueba;

	Prueba.chooseRandom();
	EXPECT_EQ(Prueba.getCurrent(), -1);

	sf::Music cancion1;
	sf::Music cancion2;
	sf::Music cancion3;
	Prueba.add(cancion1);
	Prueba.add(cancion2);
	Prueba.add(cancion3);

	Prueba.chooseRandom();
	EXPECT_GE(Prueba.getCurrent(), 0);
}
