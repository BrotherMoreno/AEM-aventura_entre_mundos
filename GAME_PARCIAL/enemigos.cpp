#include "enemigos.h"

int Enemigos::getX(){
	return posX;
}
int Enemigos::getY(){
	return posY;
}
void Enemigos::gotoxy(int x,int y){
    Console::SetCursorPosition(x, y);
}
void Enemigos::rebotar(int direccion) {
    if (direccion ==1) {
        if (posX <= 0 || posX + getLongitud() >= 46) {
            direccionX *= -1;
            // ?? Corrige la posición para no salirse
            if (posX <= 0) posX = 1;
            if (posX + getLongitud() >= 46) posX = 46 - getLongitud() - 1;
        }
    }
    //if (direccion == 2) {
    //    if (posY <= 0 || posY + getLongitud() >= MAX_HEIGHT) {
    //        direccionY *= -1;
    //        // ?? Corrige la posición para no salirse
    //        if (posY <= 0) posY = 1;
    //        if (posY + getLongitud() >= MAX_HEIGHT) posY = MAX_HEIGHT - getLongitud() - 1;
    //    }
    //}
}