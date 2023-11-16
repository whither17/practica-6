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

private:
    double x_i, y_i, vy_i, vx_i, vx, vy;
    unsigned int masa, radio;
};

#endif // PLANET_H
