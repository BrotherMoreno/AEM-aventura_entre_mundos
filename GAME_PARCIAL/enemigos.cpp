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
void Enemigos::rebotar() {
    if (posX <= 0 || posX + getLongitud() >= MAX_WIDTH) {
        direccionX *= -1;
        // ?? Corrige la posición para no salirse
        if (posX <= 0) posX = 1;
        if (posX + getLongitud() >= MAX_WIDTH) posX = MAX_WIDTH - getLongitud() - 1;
    }
}