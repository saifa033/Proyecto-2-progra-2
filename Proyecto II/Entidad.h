#pragma once
#ifndef ENTIDAD_H
#define ENTIDAD_H

class Entidad {
protected:
    int x, y;

public:
    Entidad(int x = 0, int y = 0);
    virtual ~Entidad() {}

    int getX() const;
    int getY() const;
    void setPosicion(int nuevaX, int nuevaY);
};

#endif // ENTIDAD_H
