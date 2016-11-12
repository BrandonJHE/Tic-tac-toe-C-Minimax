#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "Boton.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Network.hpp"
class Juego
{
public:
	Juego();
	~Juego();
	void iniciar();
	char menuPrinc();
	char menuPC();
	void primerJugador();
	char juegoPC(char);
	void reiniciarCuadricula(sf::RenderWindow&);
	bool revBotones(sf::Vector2i);
	void actualizarPantalla(sf::RenderWindow&);
	void montarImagMenuPrinc(sf::RenderWindow&);
	void montarImagMenuPC(sf::RenderWindow&);
	void montarImagPrimJug(sf::RenderWindow&);
	int juegoDificil(int[], int);
	int juegoFacil(int[]);
	void juegoGanado();
	void juegoPerdido();
	void juegoEmpatado();
	void juegoComputadora(int[], char, sf::RenderWindow&);
	void juegoJugador(int[], sf::Vector2i, sf::RenderWindow&);
	int ganador(int[]);
private:
	int jugar, cantMov;
	Boton botones[3][3];
	Boton unJug, salir;
	Boton nivelFacil, nivelDificil;
	Boton computadora, jugador;
};

