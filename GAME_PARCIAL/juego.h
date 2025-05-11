#ifndef JUEGO_H
#define JUEGO_H
#include"jugador.h"
#include"enemigos.h"
#include "araña.h"
#include"fantasma.h"
#include"mapas.h"
#include <iostream>
#include<cctype>
#include<Windows.h>
#include<thread>
#include<chrono>
#include<conio.h>

using namespace System;

class Juego {
public:
    Juego() : Jugador(MAX_WIDTH / 2, MAX_HEIGHT - 20) {
        //Enemigos.push_back(new Araña(10, 0, 10));
        Enemigos.push_back(new Fantasma(2, MAX_WIDTH - 13, 10));
        Enemigos.push_back(new Araña(2, 0, 7));
    }
    void gotoxy(int x, int y) {
        Console::SetCursorPosition(x, y);
    }
    void ajustarConsola() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD size = { MAX_WIDTH, MAX_HEIGHT };
        SetConsoleScreenBufferSize(hConsole, size);
        SMALL_RECT rect = { 0, 0, MAX_WIDTH - 1, MAX_HEIGHT - 1 };
        SetConsoleWindowInfo(hConsole, TRUE, &rect);
    }
    void jugarNivel2() {
        ajustarConsola();
        Mapas.dibujarMapa2();

        while (Jugador.estaViva()) {
            Console::BackgroundColor = ConsoleColor::Black;
            Jugador.dibujar(2);
            Jugador.mostrarVida();

            if (_kbhit()) {
                int tecla = _getch();
                Jugador.mover(tecla,2);
            }

            for (auto* v : Enemigos) {
                v->mover();

                // 🔧 Colisión más precisa usando longitud
                if (Jugador.getY() == v->getY() &&
                    Jugador.getX() >= v->getX() &&
                    Jugador.getX() < v->getX() + v->getLongitud()) {
                    if (v->chocar()) {
                        Jugador.perderVida();
                    }
                }
            }

            Sleep(100);
        }

        system("cls"); // Limpia pantalla al morir
        gotoxy(MAX_WIDTH / 2 - 10, MAX_HEIGHT / 2);
        std::cout << "¡Game Over! Has muerto.\n";
        Sleep(3000); // Espera antes de cerrar
    }
    void jugarNivel() {
        ajustarConsola();
        Mapas.dibujarMapa1();
        while (Jugador.estaViva()) {
            Console::BackgroundColor = ConsoleColor::Black;

            Jugador.dibujar(1);
            Jugador.mostrarVida();

            if (_kbhit()) {
                int tecla = _getch();
                Jugador.mover(tecla,1);
            }

            for (auto* v : Enemigos) {
                v->mover();

                // 🔧 Colisión más precisa usando longitud
                if (Jugador.getY() == v->getY() &&
                    Jugador.getX() >= v->getX() &&
                    Jugador.getX() < v->getX() + v->getLongitud()) {
                    if (v->chocar()) {
                        Jugador.perderVida();
                    }
                }
            }

            Sleep(50);
        }

        system("cls"); // Limpia pantalla al morir
        gotoxy(MAX_WIDTH / 2 - 10, MAX_HEIGHT / 2);
        std::cout << "¡Game Over! Has muerto.\n";
        Sleep(3000); // Espera antes de cerrar
    }
	~Juego() {
		for (auto* v : Enemigos)
			delete v;
	} 
	void run(); 
private:
	std::vector<Enemigos*> Enemigos;
	Jugador Jugador;
    Mapas Mapas;    
    
	//       
	void intro();
	void ocultarCursor();
	void dibujoDragonEstatico();
	void menuPrincipal();
	void portadaEstaticaJuego();
	void pelotaAni1();
	void pelotaAni2();
	void pelotaAni3();
	void animacionPortada();	
	//void cargarJuego();
	//void nuevoJuego();
	void mostrarInstrucciones();
	void resaltarOpcionMenu(char* options, int pos_opx, int pos_opy, bool seleccion);
};
#endif /
