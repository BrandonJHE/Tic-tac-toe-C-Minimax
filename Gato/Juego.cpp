#include "Juego.h"
Juego::Juego() { }
Juego::~Juego() { }
void Juego::iniciar() {
menu:
	if (menuPrinc() != 'S') goto menu;
}
char Juego::menuPrinc() {
	sf::RenderWindow window(sf::VideoMode(525, 300), "Gato");
	window.clear(sf::Color::Cyan);
	montarImagMenuPrinc(window);
	window.display();
	while (window.isOpen()) {
		sf::Event event;
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) { window.close(); return 'S'; }
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) { window.close(); return 'S'; }
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left) {
			if (unJug.pulsado(sf::Mouse::getPosition(window))) {
				window.close();
				juegoPC(menuPC());
				window.display();
			}
			else if (salir.pulsado(sf::Mouse::getPosition(window))) { window.close(); return 'S'; }
		}
	}
}
char Juego::juegoPC(char dificultad) {
	sf::RenderWindow window(sf::VideoMode(290, 290), "Usuario VS PC");
	window.clear(sf::Color(16, 16, 16, 255));
	reiniciarCuadricula(window);
	window.display();
	cantMov = 0;
	int tabla[9] = { 0,0,0,0,0,0,0,0,0 };
	while (window.isOpen()) {
		sf::Event event;
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) { window.close(); break; }
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) { window.close(); break; }
		int g = ganador(tabla);
		if (g == 1) { window.close(); juegoPerdido(); break; }
		if (g == -1) { window.close(); juegoGanado(); break; }
		if (cantMov == 9) { window.close(); juegoEmpatado(); break; }
		if (jugar == -1){
			actualizarPantalla(window);
			window.display();
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left) {
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				if (revBotones(mousePosition)) juegoJugador(tabla, mousePosition, window);
			}
		}
		else {
			juegoComputadora(tabla, dificultad, window);
		}
	}
	return 'S';
}
char Juego::menuPC() {
	sf::RenderWindow window(sf::VideoMode(420, 200), "Dificultad");
	window.clear(sf::Color::Cyan);
	montarImagMenuPC(window);
	window.display();
	while (window.isOpen()) {
		sf::Event event;
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) { window.close(); return 'S'; }
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) { window.close(); return 'S'; }
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left) {
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			if (nivelFacil.pulsado(mousePosition)) { 
				window.close(); 
				primerJugador();
				return 'F'; 
			}
			else if (nivelDificil.pulsado(mousePosition)) { 
				window.close();
				primerJugador();
				return 'D'; 
			}
		}
	}
}
void Juego::primerJugador() {
	sf::RenderWindow window(sf::VideoMode(260, 230), "Primer Jugador?");
	window.clear(sf::Color::Cyan);
	montarImagPrimJug(window);
	window.display();
	while (window.isOpen()) {
		sf::Event event;
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) { window.close(); return; }
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) { window.close(); return; }
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left) {
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			if (computadora.pulsado(mousePosition)) { jugar = 1; return; }
			else if (jugador.pulsado(mousePosition)) { jugar = -1; return; }
		}
	}
}
void Juego::juegoGanado() {
	sf::RenderWindow window(sf::VideoMode(750, 400), "Ganaste! Felicidades");
	Boton boton;
	boton.setDatos(0, 0);
	boton.setValor(8);
	window.clear(sf::Color::Cyan);
	window.draw(boton.getSprite());
	window.display();
	while (window.isOpen()) {
		sf::Event event;
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) { window.close(); return; }
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) { window.close(); return; }
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left) {
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			if (boton.pulsado(mousePosition)) { window.close(); return; }
		}
	}
}
void Juego::juegoPerdido() {
	sf::RenderWindow window(sf::VideoMode(802, 481), "Perdiste! Suerte en proxima");
	Boton boton;
	boton.setDatos(0, 0);
	boton.setValor(9);
	window.clear(sf::Color::Cyan);
	window.draw(boton.getSprite());
	window.display();
	while (window.isOpen()) {
		sf::Event event;
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) { window.close(); return; }
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) { window.close(); return; }
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left) {
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			if (boton.pulsado(mousePosition)) { window.close(); return; }
		}
	}
}
void Juego::juegoEmpatado() {
	sf::RenderWindow window(sf::VideoMode(500, 250), "Oh Empate");
	Boton boton;
	boton.setDatos(0, 0);
	boton.setValor(10);
	window.clear(sf::Color::Cyan);
	window.draw(boton.getSprite());
	window.display();
	while (window.isOpen()) {
		sf::Event event;
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) { window.close(); return; }
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) { window.close(); return; }
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left) {
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			if (boton.pulsado(mousePosition)) { window.close(); return; }
		}
	}
}
void Juego::reiniciarCuadricula(sf::RenderWindow &window) {
	int x = 0, y;
	for (int i = 0; i < 3; i++) {
		y = 0;
		for (int j = 0; j < 3; j++) {
			botones[i][j].setDatos(x, y);
			botones[i][j].setValor(0);
			window.draw(botones[i][j].getSprite());
			y += 100;
		}
		x += 100;
	}
}
void Juego::actualizarPantalla(sf::RenderWindow &window) {
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) window.draw(botones[i][j].getSprite());
}
bool Juego::revBotones(sf::Vector2i mousePosition) {
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (botones[i][j].pulsado(mousePosition)) return true;
	return false;
}
void Juego::montarImagMenuPrinc(sf::RenderWindow &window) {
	unJug.setDatos(25, 37);
	unJug.setValor(2);
	salir.setDatos(275, 37);
	salir.setValor(5);
	window.draw(unJug.getSprite());
	window.draw(salir.getSprite());
}
void Juego::montarImagMenuPC(sf::RenderWindow &window) {
	nivelFacil.setDatos(20, 10);
	nivelFacil.setValor(3);
	nivelDificil.setDatos(220, 10);
	nivelDificil.setValor(4);
	window.draw(nivelFacil.getSprite());
	window.draw(nivelDificil.getSprite());
}
void Juego::montarImagPrimJug(sf::RenderWindow &window) {
	jugador.setDatos(10, 10);
	jugador.setValor(7);
	computadora.setDatos(140, 10);
	computadora.setValor(6);
	window.draw(jugador.getSprite());
	window.draw(computadora.getSprite());
}
int Juego::juegoDificil(int tabla[], int j) {
	int g = ganador(tabla);
	if (g != 0) return g * j;
	int mov = -1;
	int nota = -2;
	for (int i = 0; i < 9; i++) {
		if (tabla[i] == 0) {
			tabla[i] = j;
			int nota2 = -juegoDificil(tabla, -j);
			if (nota2 > nota) {
				nota = nota2;
				mov = i;
			}
			tabla[i] = 0;
		}
	}
	if (mov == -1) return 0;
	return nota;
}
int Juego::juegoFacil(int tabla[]) {
	int mov = -1;
	int nota = 0;
	for (int i = 0; i < 9; i++) {
		if (tabla[i] == 0) {
			tabla[i] = -1;
			int g = ganador(tabla);
			tabla[i] = 0;
			if (g == -1) {
				nota = g;
				mov = i;
				break;
			}
		}
	}
	if (mov == -1) {
		for (int i = 0; i < 9; i++) {
			if (tabla[i] == 0) {
				mov = i;
				break;
			}
		}
	}
	return mov;
}
int Juego::ganador(int tabla[]) {
	int ganes[8][3] = { { 0,1,2 },{ 3,4,5 },{ 6,7,8 },{ 0,3,6 },{ 1,4,7 },{ 2,5,8 },{ 0,4,8 },{ 2,4,6 } };
	for (int i = 0; i < 8; i++) {
		if (tabla[ganes[i][0]] != 0 && tabla[ganes[i][0]] == tabla[ganes[i][1]] && tabla[ganes[i][0]] == tabla[ganes[i][2]]) return tabla[ganes[i][2]];
	}
	return 0;
}
void Juego::juegoComputadora(int tabla[], char dificultad, sf::RenderWindow &window) {
	int mov = -1;
	int nota = -2;
	int p = 0;
	for (int i = 0; i < 9; i++) {
		if (dificultad == 'F') {
			mov = juegoFacil(tabla);
			break;
		}
		else {
			if (tabla[i] == 0) {
				tabla[i] = 1;
				int nota2 = -juegoDificil(tabla, -1);
				tabla[i] = 0;
				if (nota2 > nota) {
					nota = nota2;
					mov = i;
				}
			}
		}
	}
	tabla[mov] = 1;
	nota = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (nota == mov) {
				botones[i][j].setValor(1);
				window.draw(botones[i][j].getSprite());
				jugar = -jugar;
				cantMov++;
				return;
			}
			nota++;
		}
	}
}
void Juego::juegoJugador(int tabla[], sf::Vector2i pulsacion, sf::RenderWindow &window) {
	int p = 0;
	if (ganador(tabla) == 0) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (botones[i][j].pulsado(pulsacion)) {
					if (tabla[p] == 0 && botones[i][j].getValor() == 0) {
						tabla[p] = -1;
						botones[i][j].setValor(-1);
						window.draw(botones[i][j].getSprite());
						jugar = -jugar;
						cantMov++;
						return;
					}
				}
				p++;
			}
		}
	}
}