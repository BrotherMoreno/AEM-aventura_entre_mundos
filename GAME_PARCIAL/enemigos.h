#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include<iostream>
#include<string.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>
#include <cstdlib>
const int MAX_WIDTH = 120;
const int MAX_HEIGHT = 29;
using namespace System;
class Enemigos {
protected:
    float velocidad;
    int posX, posY;
    int direccionX;
    int direccionY;
public:
    Enemigos(float v, int x, int y, int dir) : velocidad(v), posX(x), posY(y), direccionX(dir), direccionY(dir){}
    void gotoxy(int x, int y);
    virtual void mover() = 0;
    virtual void dibujar() = 0;
    virtual void borrar() = 0;
    virtual bool chocar() = 0;
    virtual int getX();
    virtual int getY();
    virtual int getLongitud() = 0;
    virtual void rebotar(int direccion);
    virtual ~Enemigos(){}
};
#endif // !ENEMIGOS_H

