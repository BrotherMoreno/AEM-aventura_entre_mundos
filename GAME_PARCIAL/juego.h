#ifndef JUEGO_H
#define JUEGO_H
#include"jugador.h"
#include"enemigos.h"
#include "araña.h"
#include"fantasma.h"
#include <iostream>
#include<cctype>
#include<Windows.h>
#include<thread>
#include<chrono>
#include<conio.h>
using namespace System;

class Juego {
public:
	Juego() : Jugador(MAX_WIDTH / 2, MAX_HEIGHT - 5) {
        Enemigos.push_back(new Araña(2, 0, 5));
        Enemigos.push_back(new Araña(3, 0, 6));
        Enemigos.push_back(new Araña(4, 0, 7));
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
	void jugarNivel1() {
        ajustarConsola();
        while (Jugador.estaViva()) {
            Jugador.dibujar();

            if (_kbhit()) {
                char tecla = _getch();
                Jugador.mover(tecla);
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

        if (!Jugador.estaViva()) {
            gotoxy(0, MAX_HEIGHT);
            std::cout << "\n\n¡Game Over! Has muerto.";
        }
	}
	~Juego() {
		for (auto* v : Enemigos)
			delete v;
	} 
	void run();
private:
	std::vector<Enemigos*> Enemigos;
	Jugador Jugador;
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
