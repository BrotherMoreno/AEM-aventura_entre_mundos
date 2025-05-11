#ifndef FANTASMA_H
#define FANTASMA_H

#include "enemigos.h"

class Fantasma : public Enemigos {
public:
    Fantasma(float v, int x, int y) : Enemigos(v, x, y, 1) {} // Constructor que llama al constructor de la clase base
    void gotoxy(int x, int y);
    void mover() override;
    void dibujar() override;
    void borrar() override;
    bool chocar() override;
    int getLongitud() override;

    ~Fantasma() override {}
};

#endif // FANTASMA_H