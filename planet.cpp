#include "planet.h"

planet::planet(double x_i_, double y_i_, double vx_i_, double vy_i_, unsigned int masa_, unsigned int radio_) : x_i(x_i_), y_i(y_i_), vx_i(vx_i_), vy_i(vy_i_), masa(masa_), radio(radio_)
{
    setRect(x_i, y_i, radio*2, radio*2);
    setBrush(QBrush(Qt::black));
    setPosicion(x_i, y_i);



}

planet::~planet()
{

}

double planet::getX_i() const
{
    return x_i;
}

void planet::setX_i(double newX_i)
{
    x_i = newX_i;
}

double planet::getY_i() const
{
    return y_i;
}

void planet::setY_i(double newY_i)
{
    y_i = newY_i;
}

double planet::getVy_i() const
{
    return vy_i;
}

void planet::setVy_i(double newVy_i)
{
    vy_i = newVy_i;
}

double planet::getVx() const
{
    return vx;
}

void planet::setVx(double newVx)
{
    vx = newVx;
}

double planet::getVy() const
{
    return vy;
}

void planet::setVy(double newVy)
{
    vy = newVy;
}

double planet::getVx_i() const
{
    return vx_i;
}

void planet::setVx_i(double newVx_i)
{
    vx_i = newVx_i;
}

unsigned int planet::getMasa() const
{
    return masa;
}

void planet::setMasa(unsigned int newMasa)
{
    masa = newMasa;
}

unsigned int planet::getRadio() const
{
    return radio;
}

void planet::setRadio(unsigned int newRadio)
{
    radio = newRadio;
}

void planet::setPosicion(double x, double y)
{
    setPos((x/escala) + WIDTH_GV/2 - radio , (y/escala) + HEIGHT_GV/2 - radio);
}


