#include"ara�a.h"

void Ara�a::mover() {
    borrar();
    posX += static_cast<int>(velocidad) * direccionX;
    rebotar();
    dibujar();
}
void Ara�a::dibujar() {
    gotoxy(posX, posY);
    std::cout << "|~\\_";
}
void Ara�a::borrar() {
    gotoxy(posX, posY);
    std::cout << "    ";
}
bool Ara�a::chocar() {
    return true;
}
int getLongitud()  {
    return 4;
}