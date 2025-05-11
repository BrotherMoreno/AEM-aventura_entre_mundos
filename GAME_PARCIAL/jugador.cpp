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
    else if (tecla == 's' && posY < MAX_HEIGHT - 4) posY++; // Altura de 8
    else if (tecla == 'a' && posX > 0) posX--;
    else if (tecla == 'd' && posX < MAX_WIDTH - 5) posX++; // Ancho de 12
    dibujar();
}

void Jugador::dibujar() {
    if (!viva) return;

    char block = (char)219;

    int forma[4][4] = { {2,1,1,2},
                                    {1,0,0,1},
                                    {2,1,1,2},
                                    {1,2,2,1}
    };


    for (int i = 0; i < 4; ++i) {
        gotoxy(posX, posY + i);
        for (int j = 0; j < 4; ++j) {
            if (forma[i][j] == 0) {
                Console::ForegroundColor = ConsoleColor::White;
                std::cout << block;
            }
            if (forma[i][j] == 1) {
                Console::ForegroundColor = ConsoleColor::DarkRed;
                std::cout << block;
            }
            if (forma[i][j] == 2) {
                Console::ForegroundColor = ConsoleColor::DarkGreen;
                std::cout << block;
            }
        }
    }

    mostrarVida();
}

void Jugador::borrar() {
    for (int i = 0; i < 4; ++i) {
        gotoxy(posX, posY + i);
        std::cout << "    ";  // 11 espacios
    }

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
     if (!viva) return;
        vida -= 1;
        if (vida <= 0) {
            vida = 0;
            morir();
        }
}
