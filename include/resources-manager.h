#ifndef __RESOURCESMANAGER_H__
#define __RESOURCESMANAGER_H__

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "common.h"

/**
 * Organiza los recursos del juego. Carga estos y los maneja.
 */
class ResourcesManager {
public:
  /**
   * Constructor
   * @param n Dirección donde se encuentran los datos. Carpeta base.
   */
  ResourcesManager(string n);
  ~ResourcesManager(void);

  /**
   * Singleton
   * @return Una instancia del objeto resource.
   */
  static ResourcesManager& getInstance();

  /**
   * Carga las texturas en Sprite.
   * @param sprite Donde se cargan la textura.
   * @param name Nombre de la textura a cargar
   */
  void loadTextures(sf::Sprite& sprite, string name);

  /**
   * Carga el archivo de música.
   * @param name Es el nombre del archivo a cargar.
   * @return Música cargada.
   */
  sf::Music& loadMusic(string name);

  /**
   * Carga el archivo para las fuentes.
   * @param name Es el nombre del archivo a cargar.
   * @return Fuente cargada.
   */
  const sf::Font& loadFont(const string& name);

  /**
   * Obtiene el tamaño de las texturas
   */
  int getTexturesCacheSize();

  /**
   * Obtiene el tamaño del caché de las fuentes
   */
  int getFontsCacheSize();

  /**
   * Obtiene el tamaño del caché de música.
   */
  int getMusicCacheSize();

private:
  DISALLOW_COPY_AND_ASSIGN(ResourcesManager);


  /**
   * Es la carpeta para el constructor.
   */
  string datoprivado;

  map<string, sf::Texture*> textures;
  map<string, sf::Music*> music;
  map<string, sf::Font*> fonts;
};

#endif
