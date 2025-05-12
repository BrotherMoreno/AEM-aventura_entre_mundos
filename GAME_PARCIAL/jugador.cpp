#include"jugador.h"
#include<conio.h>
#include<Windows.h>
#include"enemigos.h"
Jugador::Jugador(int x, int y) : posX(x), posY(y), viva(true), vida(10),velocidad(1){}
void Jugador::gotoxy(int x, int y) {
    Console::SetCursorPosition(x, y);
}
void Jugador::mover(int tecla, int jugador, int mapa1[30][120]) {
    if (!viva) return;
    if (jugador == 1) {

        int nuevaPosX = posX;
        int nuevaPosY = posY;

        // Calcula la nueva posición basada en la tecla presionada
        if (tecla == 72 && posY > 0) nuevaPosY--; // Arriba
        else if (tecla == 80 && posY < 29) nuevaPosY++; // Abajo (ajustado para 30 filas)
        else if (tecla == 75 && posX > 0) nuevaPosX--; // Izquierda
        else if (tecla == 77 && posX < 119) nuevaPosX++; // Derecha (ajustado para 120 columnas)

        // Verifica si la nueva posición es válida en el mapa
        if (/*mapa1[nuevaPosY][nuevaPosX] == 3&& mapa1[nuevaPosY][nuevaPosX+1] == 3&& mapa1[nuevaPosY][nuevaPosX+2] == 3&& mapa1[nuevaPosY][nuevaPosX+3] == 3&& mapa1[nuevaPosY][nuevaPosX+4] == 3 &&*/
            mapa1[nuevaPosY+1][nuevaPosX] == 3 && mapa1[nuevaPosY+1][nuevaPosX + 1] == 3 && mapa1[nuevaPosY+1][nuevaPosX + 2] == 3 && mapa1[nuevaPosY+1][nuevaPosX + 3] == 3 && mapa1[nuevaPosY+1][nuevaPosX + 4] == 3 && 
            mapa1[nuevaPosY + 2][nuevaPosX] == 3 && mapa1[nuevaPosY + 2][nuevaPosX + 1] == 3 && mapa1[nuevaPosY + 2][nuevaPosX + 2] == 3 && mapa1[nuevaPosY + 2][nuevaPosX + 3] == 3 && mapa1[nuevaPosY + 2][nuevaPosX + 4] == 3 &&
            mapa1[nuevaPosY + 3][nuevaPosX] == 3 && mapa1[nuevaPosY + 3][nuevaPosX + 1] == 3 && mapa1[nuevaPosY + 3][nuevaPosX + 2] == 3 && mapa1[nuevaPosY + 3][nuevaPosX + 3] == 3 && mapa1[nuevaPosY + 3][nuevaPosX + 4] == 3 && 
            mapa1[nuevaPosY + 4][nuevaPosX] == 3 && mapa1[nuevaPosY + 4][nuevaPosX + 1] == 3 && mapa1[nuevaPosY + 4][nuevaPosX + 2] == 3 && mapa1[nuevaPosY + 4][nuevaPosX + 3] == 3 && mapa1[nuevaPosY + 4][nuevaPosX + 4] == 3 ) {
            borrar(jugador); // Borra la posición anterior
            posX = nuevaPosX;
            posY = nuevaPosY;
            dibujar(jugador); // Dibuja en la nueva posición
        }
    }

    if (jugador == 2) {
        borrar(2);
        if (tecla == 'w' && posY > 0) posY -= velocidad;
        else if (tecla == 's' && posY < MAX_HEIGHT - 2) posY += velocidad;
        else if (tecla == 'a' && posX > 0) posX -= velocidad;
        else if (tecla == 'd' && posX < MAX_WIDTH - 3) posX += velocidad;
        dibujar(2);
    }
    if (jugador == 3) {
        int nuevaPosX = posX;
        int nuevaPosY = posY;

        // Calcula la nueva posición basada en la tecla presionada
        if (tecla == 72 && posY > 0) nuevaPosY--; // Arriba
        else if (tecla == 80 && posY < 29) nuevaPosY++; // Abajo (ajustado para 30 filas)
        else if (tecla == 75 && posX > 0) nuevaPosX--; // Izquierda
        else if (tecla == 77 && posX < 119) nuevaPosX++; // Derecha (ajustado para 120 columnas)

        // Verifica si la nueva posición es válida en el mapa
        if ((mapa1[nuevaPosY][nuevaPosX] == 6&& mapa1[nuevaPosY][nuevaPosX+1] == 6&& mapa1[nuevaPosY][nuevaPosX+2] == 6&& mapa1[nuevaPosY][nuevaPosX+3] == 6&& mapa1[nuevaPosY][nuevaPosX+4] == 6&&
            mapa1[nuevaPosY + 1][nuevaPosX] == 6 && mapa1[nuevaPosY + 1][nuevaPosX + 1] == 6&& mapa1[nuevaPosY + 1][nuevaPosX + 2] == 6 && mapa1[nuevaPosY + 1][nuevaPosX + 3] == 6 && mapa1[nuevaPosY + 1][nuevaPosX + 4] == 6 &&
            mapa1[nuevaPosY + 2][nuevaPosX] == 6 && mapa1[nuevaPosY + 2][nuevaPosX + 1] == 6 && mapa1[nuevaPosY + 2][nuevaPosX + 2] == 6 && mapa1[nuevaPosY + 2][nuevaPosX + 3] == 6 && mapa1[nuevaPosY + 2][nuevaPosX + 4] == 6 &&
            mapa1[nuevaPosY + 3][nuevaPosX] == 6 && mapa1[nuevaPosY + 3][nuevaPosX + 1] == 6 && mapa1[nuevaPosY + 3][nuevaPosX + 2] == 6 && mapa1[nuevaPosY + 3][nuevaPosX + 3] == 6 && mapa1[nuevaPosY + 3][nuevaPosX + 4] == 6 )||(
            mapa1[nuevaPosY][nuevaPosX] == 5 || mapa1[nuevaPosY][nuevaPosX + 1] == 5 || mapa1[nuevaPosY][nuevaPosX + 2] == 5 ||mapa1[nuevaPosY][nuevaPosX + 3] == 5 || mapa1[nuevaPosY][nuevaPosX + 4] == 5 &&
            mapa1[nuevaPosY + 1][nuevaPosX] == 5 || mapa1[nuevaPosY + 1][nuevaPosX + 1] == 5 || mapa1[nuevaPosY + 1][nuevaPosX + 2] == 5||mapa1[nuevaPosY + 1][nuevaPosX + 3] == 5 || mapa1[nuevaPosY + 1][nuevaPosX + 4] == 5 ||
            mapa1[nuevaPosY + 2][nuevaPosX] == 5 || mapa1[nuevaPosY + 2][nuevaPosX + 1] == 5 ||mapa1[nuevaPosY + 2][nuevaPosX + 2] == 5 || mapa1[nuevaPosY + 2][nuevaPosX + 3] == 5 || mapa1[nuevaPosY + 2][nuevaPosX + 4] == 5 ||
            mapa1[nuevaPosY + 3][nuevaPosX] == 5 || mapa1[nuevaPosY + 3][nuevaPosX + 1] == 5 || mapa1[nuevaPosY + 3][nuevaPosX + 2] == 5 || mapa1[nuevaPosY + 3][nuevaPosX + 3] == 5 || mapa1[nuevaPosY + 3][nuevaPosX + 4] == 5)) {
            borrar(jugador); // Borra la posición anterior
            posX = nuevaPosX;
            posY = nuevaPosY;
            dibujar(jugador); // Dibuja en la nueva posición
        }
        if ((
            mapa1[nuevaPosY][nuevaPosX] == 5 || mapa1[nuevaPosY][nuevaPosX + 1] == 5 || mapa1[nuevaPosY][nuevaPosX + 2] == 5 || mapa1[nuevaPosY][nuevaPosX + 3] == 5 || mapa1[nuevaPosY][nuevaPosX + 4] == 5 &&
            mapa1[nuevaPosY + 1][nuevaPosX] == 5 || mapa1[nuevaPosY + 1][nuevaPosX + 1] == 5 || mapa1[nuevaPosY + 1][nuevaPosX + 2] == 5 || mapa1[nuevaPosY + 1][nuevaPosX + 3] == 5 || mapa1[nuevaPosY + 1][nuevaPosX + 4] == 5 ||
            mapa1[nuevaPosY + 2][nuevaPosX] == 5 || mapa1[nuevaPosY + 2][nuevaPosX + 1] == 5 || mapa1[nuevaPosY + 2][nuevaPosX + 2] == 5 || mapa1[nuevaPosY + 2][nuevaPosX + 3] == 5 || mapa1[nuevaPosY + 2][nuevaPosX + 4] == 5 ||
            mapa1[nuevaPosY + 3][nuevaPosX] == 5 || mapa1[nuevaPosY + 3][nuevaPosX + 1] == 5 || mapa1[nuevaPosY + 3][nuevaPosX + 2] == 5 || mapa1[nuevaPosY + 3][nuevaPosX + 3] == 5 || mapa1[nuevaPosY + 3][nuevaPosX + 4] == 5)) {

        }
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
        mostrarVida();

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
            mostrarVida();

        }
    }
    if (elegirDibujoJugador == 3) {
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
    if (jugador == 3) {

        for (int i = 0; i < 4; ++i) {
            gotoxy(posX, posY + i);
            std::cout << "     ";  // 11 espacios
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
