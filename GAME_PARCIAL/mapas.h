#ifndef MAPAS_H
#define MAPAS_H
#define COLUMNA 120
#define FILA 30
#include <iostream>
#include<cctype>
#include<Windows.h>
#include<thread>
#include<chrono>
#include<conio.h>

using  namespace System;
class Mapas {
public:
	Mapas();
	void dibujarMapa1();
	void dibujarMapa2();
	void dibujarMapa3();
	void dibujarCasaMadera();
	void dibujarCarretera();
	void dibujarArbol();
	int carretera[9][70];
	int piscina[30][120];
	int casaMadera[30][120];
	int mapa1[30][120];
	int mapa2[30][120];
	int mapa3[30][120];
};
#endif // !MAPAS_H
