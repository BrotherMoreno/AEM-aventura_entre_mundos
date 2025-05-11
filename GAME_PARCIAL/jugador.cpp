#include"jugador.h"
#include<conio.h>
#include<Windows.h>
#include"enemigos.h"
Jugador::Jugador(int x, int y) : posX(x), posY(y), viva(true), vida(10),velocidad(1){}
void Jugador::gotoxy(int x, int y) {
    Console::SetCursorPosition(x, y);
}
void Jugador::mover(int tecla, int jugador) {
    if (jugador == 1) {
        borrar(1);
        if (tecla == 72 && posY > 0) posY -= velocidad; // Mueve hacia arriba más rápido
        else if (tecla == 80 && posY < MAX_HEIGHT - 4) posY += velocidad; // Mueve hacia abajo más rápido
        else if (tecla == 75 && posX > 0) posX -= velocidad; // Mueve hacia la izquierda más rápido
        else if (tecla == 77 && posX < MAX_WIDTH - 5) posX += velocidad; // Mueve hacia la derecha más rápido
        dibujar(1);
    }
    if (jugador == 2) {
        borrar(2);
        if (tecla == 'w' && posY > 0) posY -= velocidad;
        else if (tecla == 's' && posY < MAX_HEIGHT - 2) posY += velocidad;
        else if (tecla == 'a' && posX > 0) posX -= velocidad;
        else if (tecla == 'd' && posX < MAX_WIDTH - 3) posX += velocidad;
        dibujar(2);
    }
}

void Jugador::dibujar(int elegirDibujoJugador) {
    if (!viva) return;

    char block = (char)219;
    if (elegirDibujoJugador == 1) {
        int forma[4][5] = {
            {0, 5, 5, 5, 0}, // Cabeza
            {1, 4, 4, 4, 1}, // Brazos
            {3, 2, 2, 2, 3}, // Cuerpo
            {0, 2, 0, 2, 0}  // Pies
        };

        for (int i = 0; i < 4; ++i) {
            gotoxy(posX, posY + i);
            for (int j = 0; j < 5; ++j) {
                if (forma[i][j] == 0) {
                    Console::ForegroundColor = ConsoleColor::Black; // Espacio vacío
                    std::cout << " ";
                }
                if (forma[i][j] == 1) {
                    Console::ForegroundColor = ConsoleColor::DarkRed; // Brazos
                    std::cout << block;
                }
                if (forma[i][j] == 2) {
                    Console::ForegroundColor = ConsoleColor::White; // Cabeza, cuerpo y pies
                    std::cout << block;
                }
                if (forma[i][j] == 3) {
                    Console::ForegroundColor = ConsoleColor::DarkGray; // Cabeza, cuerpo y pies
                    std::cout << (char)223;
                } 
                if (forma[i][j] == 4) {
                    Console::ForegroundColor = ConsoleColor::DarkBlue; // Cabeza, cuerpo y pies
                    std::cout << (char)223;
                }
                if (forma[i][j] == 5) {
                    Console::ForegroundColor = ConsoleColor::Yellow; // Cabeza, cuerpo y pies
                    std::cout << (char)219;
                }
            }
        }
    }
    if (elegirDibujoJugador == 2) {

        int forma[2][2] = { {0,0},
                                        {1,1,},
        };


        for (int i = 0; i < 2; ++i) {
            gotoxy(posX, posY + i);
            for (int j = 0; j < 2; ++j) {
                if (forma[i][j] == 0) {
                    Console::ForegroundColor = ConsoleColor::White;
                    std::cout << block;
                }
                if (forma[i][j] == 1) {
                    Console::ForegroundColor = ConsoleColor::DarkRed;
                    std::cout << block;
                }
            }
        }
    }
    mostrarVida();
}

void Jugador::borrar(int jugador) {
    if (jugador == 1) {

        for (int i = 0; i < 4; ++i) {
            gotoxy(posX, posY + i);
            std::cout << "     ";  // 11 espacios
        }
    }
    if (jugador == 2) {

        for (int i = 0; i < 2; ++i) {
            gotoxy(posX, posY + i);
            std::cout << "  ";  // 11 espacios
        }
    }

}

void Jugador::mostrarVida() {
    Console::ForegroundColor = ConsoleColor::DarkRed;
    gotoxy(120 - 10, 0);
    std::cout << "Vida:" << vida << "   ";
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
