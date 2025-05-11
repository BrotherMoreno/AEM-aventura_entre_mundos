#include "fantasma.h"
void Fantasma::gotoxy(int x, int y) {
	Console::SetCursorPosition(x, y);
}
void Fantasma::mover() {
    borrar(); // Borra la posición anterior
    posY += direccionY; // Mueve hacia abajo
    if (posY >= MAX_HEIGHT - 3 || posY <= 3) {
        direccionY *= -1; // Invierte la dirección
    }
    dibujar(); // Dibuja en la nueva posición
}
void Fantasma::dibujar() {
    gotoxy(posX, posY);
    std::cout << "/-O-\\"; // Representación del fantasma
}
void Fantasma::borrar() {
    gotoxy(posX, posY);
    std::cout << "      "; // Borra el fantasma de la posición anterior
}
bool Fantasma::chocar() {
    return true;
}
int Fantasma::getLongitud() {
    return 5;
}