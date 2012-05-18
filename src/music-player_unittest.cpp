
#include "music-player.h"
#include "gtest/gtest.h"


TEST(MusicPlayerTest, ZeroSongs) {
	MusicPlayer player;

	// Comprobamos que está vacío.
	EXPECT_EQ(player.getSize(), 0);
	EXPECT_EQ(player.getCurrent(), -1);
	EXPECT_FALSE(player.isPlaying());

	// No se puede reproducir algo vacío
	player.play();
	EXPECT_FALSE(player.isPlaying());

	// No se elige una aleatoria sino hay canciones para elegir.
	player.chooseRandom();
	EXPECT_EQ(player.getCurrent(), -1);
	EXPECT_FALSE(player.isPlaying());
}


TEST(MusicPlayerTest, SongsLoop) {
	MusicPlayer player;

	sf::Music test;
	player.add(test);
	player.add(test);

	// Comprobamos que empieza bien la repodrucción.
	player.play();
	EXPECT_TRUE(player.isPlaying());
	EXPECT_EQ(player.getCurrent(), 0);

	// Actualizamos un frame y deberíamos pasar a la siguiente canción
	// porque la music que le hemos pasado está vacía (termina inmediatamente).
	player.update(0);
	EXPECT_TRUE(player.isPlaying());
	EXPECT_EQ(player.getCurrent(), 1);

	// Probamos que vuelva al principio.
	player.update(0);
	EXPECT_TRUE(player.isPlaying());
	EXPECT_EQ(player.getCurrent(), 0);

	// Probamos a parar el loop.
	player.stop();
	EXPECT_FALSE(player.isPlaying());
	EXPECT_EQ(player.getCurrent(), 0);

	// Y que ya no siga moviendose el loop
	player.update(0);
	EXPECT_FALSE(player.isPlaying());
	EXPECT_EQ(player.getCurrent(), 0);

	// Probamos a re-iniciar el loop.
	player.play();
	EXPECT_TRUE(player.isPlaying());
	EXPECT_EQ(player.getCurrent(), 1);
}
