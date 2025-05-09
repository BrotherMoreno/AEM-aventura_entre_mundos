#include "fantasma.h"
void Fantasma::gotoxy(int x, int y) {
    Console::SetCursorPosition(x, y);
}
void Fantasma::mover() {
    borrar();
    posX += static_cast<int>(velocidad) * direccionX;
    rebotar();
    dibujar();
}

void Fantasma::dibujar() {
    gotoxy(posX, posY);
    std::cout << "=--OO";
}

void Fantasma::borrar() {
    gotoxy(posX, posY);
    std::cout << "     ";
}

bool Fantasma::chocar() { return true; }

int Fantasma::getLongitud() { return 5; }