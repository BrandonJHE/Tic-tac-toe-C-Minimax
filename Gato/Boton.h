#pragma once
#include "SFML\Graphics.hpp"
class Boton
{
public:
	Boton();
	~Boton();
	void setValor(int);
	int getValor();
	void setDatos(int, int);
	void actualizarSprite();
	bool pulsado(sf::Vector2i);
	sf::Sprite getSprite();
	sf::Texture getImagenTextura();
	sf::Vector2u getTamañoImagen();
private:
	int valor;
	sf::Sprite imagen;
	sf::Texture imagenTextura;
	sf::Vector2u tamañoImagen;
};

