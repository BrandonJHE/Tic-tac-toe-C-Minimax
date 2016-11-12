#include "Boton.h"
Boton::Boton() { valor = '0'; }
Boton::~Boton(){ }
void Boton::setValor(int v){
	valor = v;
	actualizarSprite();
}
int Boton::getValor() {
	return valor;
}
void Boton::setDatos(int x, int y) {
	imagen.setPosition(sf::Vector2f(x, y));
}
sf::Sprite Boton::getSprite() {
	return imagen;
}
sf::Texture Boton::getImagenTextura() {
	return imagenTextura;
}
sf::Vector2u Boton::getTamañoImagen() {
	return tamañoImagen;
}
void Boton::actualizarSprite() {
	switch (valor)
	{
	case -1:
		imagenTextura.loadFromFile("GatoX.jpg");
		imagen.setTexture(imagenTextura);
		tamañoImagen = imagenTextura.getSize();
		break;
	case 0:
		imagenTextura.loadFromFile("GatoVacio.jpg");
		imagen.setTexture(imagenTextura);
		tamañoImagen = imagenTextura.getSize();
		break;
	case 1:
		imagenTextura.loadFromFile("GatoO.jpg");
		imagen.setTexture(imagenTextura);
		tamañoImagen = imagenTextura.getSize();
		break;
	case 2:
		imagenTextura.loadFromFile("TiposJuegos.jpg");
		imagen.setTexture(imagenTextura);
		imagen.setTextureRect(sf::IntRect(0, 0, 225, 225));
		tamañoImagen.x = imagen.getTextureRect().width;
		tamañoImagen.y = imagen.getTextureRect().height;
		break;
	case 3:
		imagenTextura.loadFromFile("NivelFacil.jpg");
		imagen.setTexture(imagenTextura);
		tamañoImagen = imagenTextura.getSize();
		break;
	case 4:
		imagenTextura.loadFromFile("NivelDificil.jpg");
		imagen.setTexture(imagenTextura);
		tamañoImagen = imagenTextura.getSize();
		break;
	case 5:
		imagenTextura.loadFromFile("BotonSalir.jpg");
		imagen.setTexture(imagenTextura);
		tamañoImagen = imagenTextura.getSize();
		break;
	case 6:
		imagenTextura.loadFromFile("PC.jpg");
		imagen.setTexture(imagenTextura);
		tamañoImagen = imagenTextura.getSize();
		break;
	case 7:
		imagenTextura.loadFromFile("Jugador.jpg");
		imagen.setTexture(imagenTextura);
		tamañoImagen = imagenTextura.getSize();
		break;
	case 8:
		imagenTextura.loadFromFile("JuegoGanado.png");
		imagen.setTexture(imagenTextura);
		tamañoImagen = imagenTextura.getSize();
		break;
	case 9:
		imagenTextura.loadFromFile("JuegoPerdido.jpg");
		imagen.setTexture(imagenTextura);
		tamañoImagen = imagenTextura.getSize();
		break;
	case 10:
		imagenTextura.loadFromFile("JuegoEmpatado.jpg");
		imagen.setTexture(imagenTextura);
		tamañoImagen = imagenTextura.getSize();
	default:
		break;
	}
}
bool Boton::pulsado(sf::Vector2i mousePosition) {
	if (imagen.getPosition().x <= mousePosition.x && tamañoImagen.x + imagen.getPosition().x >= mousePosition.x &&
		imagen.getPosition().y <= mousePosition.y && tamañoImagen.y + imagen.getPosition().y >= mousePosition.y)
		return true;
	else return false;
}