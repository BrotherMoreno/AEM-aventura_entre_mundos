#ifndef ARAÑA_H
#define ARAÑA_H
#include"enemigos.h"
class Araña :public Enemigos{
public:
	Araña(float v, int x, int y) : Enemigos(v, x, y, 1) {}

    void mover() override;
    void dibujar() override;
    void borrar() override;
    bool chocar() override;

    int getLongitud() override {
        return 4;
    }

};
#endif // !ARAÑA_H
