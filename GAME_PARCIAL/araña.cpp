#include"araña.h"

void Araña::mover() {
    borrar();
    posX += static_cast<int>(velocidad) * direccionX;
    rebotar(1);
    dibujar();
}
void Araña::dibujar() {
    gotoxy(posX, posY);
    Console::ForegroundColor = ConsoleColor::Cyan;
    std::cout << "[o_o]"; // Cabeza

    gotoxy(posX, posY + 1);
    std::cout << " |-| "; // Cuerpo

    gotoxy(posX, posY + 2);
    std::cout << "/   \\"; // Piernas
}
void Araña::borrar() {
    gotoxy(posX, posY);
    std::cout << "     ";
    gotoxy(posX, posY + 1);
    std::cout << "    ";
    gotoxy(posX, posY + 2);
    std::cout << "     ";



}
bool Araña::chocar() {
    return true;
}
int getLongitud()  {
    return 4;
}