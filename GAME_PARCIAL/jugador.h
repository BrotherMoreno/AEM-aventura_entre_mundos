#ifndef JUGADOR_H
#define JUGADOR_H
#define Arriba 72
#define Abajo 80
#define Derecha 77
#define Izquierda 75
#define Letrae 101

#include <iostream>
#include<cctype>
#include<Windows.h>
#include<thread>
#include<chrono>
#include<conio.h>
using  namespace System;
class Jugador {
public:
    Jugador(int x, int y);
    void gotoxy(int x, int y);
    void mover(char tecla);
    void dibujar();
    void borrar();
    void mostrarVida();
    int getX();
    int getY();
    bool estaViva();
    void morir();
    void perderVida();
private:
	//basic atributes
	int posX, posY;
	bool viva;
	int vida;


};
#endif 
