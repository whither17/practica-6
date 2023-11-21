#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QBrush>
#include "macros.h"

class planet : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    planet(double x_i_, double y_i_, double vx_i_, double vy_i_, unsigned int masa_, unsigned int radio_);
    ~planet();

    double getX_i() const;
    void setX_i(double newX_i);

    double getY_i() const;
    void setY_i(double newY_i);

    double getVy_i() const;
    void setVy_i(double newVy_i);

    double getVx() const;
    void setVx(double newVx);

    double getVy() const;
    void setVy(double newVy);

    double getVx_i() const;
    void setVx_i(double newVx_i);

    unsigned int getMasa() const;
    void setMasa(unsigned int newMasa);

    unsigned int getRadio() const;
    void setRadio(unsigned int newRadio);

    void setPosicion(double x, double y);

private:
    double x_i, y_i, vy_i, vx_i, vx, vy;
    unsigned int masa, radio;
};

#endif // PLANET_H
