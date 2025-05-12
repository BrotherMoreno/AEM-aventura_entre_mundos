#ifndef DEBORADOR_H
#define DEBORADOR_H
#include"mapas.h"
#include <iostream>
#include<cctype>
#include<Windows.h>
#include<thread>
#include<chrono>
#include<conio.h>
class Deborador {
public:
    int x, y;
    int direccionX;

    Deborador(int startX, int startY) : x(startX), y(startY), direccionX(1) {}

    void dibujar() {
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(x, y);
        std::cout << ">O<";
    }

    void borrar() {
        Console::SetCursorPosition(x, y);
        std::cout << "   ";
    }

    void mover() {
        borrar();
        x += direccionX;


        if (x >= 118 || x <= 1) {
            direccionX *= -1;
        }

        dibujar();
    }
};



#endif // !DEBORADOR_H
