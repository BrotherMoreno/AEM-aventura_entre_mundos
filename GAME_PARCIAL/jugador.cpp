#include"jugador.h"
#include<conio.h>
#include<Windows.h>
#include"enemigos.h"
Jugador::Jugador(int x, int y) : posX(x), posY(y), viva(true), vida(10) {}
void Jugador::gotoxy(int x, int y) {
    Console::SetCursorPosition(x, y);
}
void Jugador::mover(char tecla) {
    borrar();
    if (tecla == 'w' && posY > 0) posY--;
    else if (tecla == 's' && posY < MAX_HEIGHT - 1) posY++;
    else if (tecla == 'a' && posX > 0) posX--;
    else if (tecla == 'd' && posX < MAX_WIDTH - 1) posX++;
    dibujar();
}

void Jugador::dibujar() {
    gotoxy(posX, posY);
    std::cout << (char)254;
    mostrarVida();
}

void Jugador::borrar() {
    gotoxy(posX, posY);
    std::cout << " ";
}

void Jugador::mostrarVida() {
    gotoxy(MAX_WIDTH - 15, 1);
    std::cout << "Vida: " << vida << "   ";
}

int Jugador::getX() { return posX; }
int Jugador::getY() { return posY; }
bool Jugador::estaViva() { return viva; }
void Jugador::morir() { viva = false; }

void Jugador::perderVida() {
    vida -= 1;
    if (vida <= 0) {
        morir();
    }
}
