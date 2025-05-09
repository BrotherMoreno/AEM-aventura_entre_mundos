#include"araña.h"

void Araña::mover() {
    borrar();
    posX += static_cast<int>(velocidad) * direccionX;
    rebotar();
    dibujar();
}
void Araña::dibujar() {
    gotoxy(posX, posY);
    std::cout << "|~\\_";
}
void Araña::borrar() {
    gotoxy(posX, posY);
    std::cout << "    ";
}
bool Araña::chocar() {
    return true;
}
int getLongitud()  {
    return 4;
}