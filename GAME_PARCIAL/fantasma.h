#ifndef FANTASMA_H
#define FANTASMA_H
#include"enemigos.h"
#include<iostream>
#include<string.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace System;
class Fantasma : Enemigos{
    Fantasma(float v, int x, int y) : Enemigos(v, x, y, 1) {}
    void gotoxy(int x, int y);
    void mover() override;
    void dibujar() override;
    void borrar() override;
    bool chocar() override;
    int getLongitud() override;
};

#endif // !FANTASMA_H
