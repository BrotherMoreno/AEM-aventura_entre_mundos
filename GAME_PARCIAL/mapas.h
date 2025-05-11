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

	int mapa1[30][120];
	int mapa2[30][120];
};
#endif // !MAPAS_H
