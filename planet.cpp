#include "planet.h"

planet::planet(double x_i_, double y_i_, double vx_i_, double vy_i_, unsigned int masa_, unsigned int radio_) : x_i(x_i_), y_i(y_i_), vx_i(vx_i_), vy_i(vy_i_), masa(masa_), radio(radio_)
{
    setRect(x_i, y_i, radio*2, radio*2);
    setBrush(QBrush(Qt::black));
    setPos(x_i + WIDTH_GV/2 - radio , y_i + HEIGHT_GV/2 - radio);



}

planet::~planet()
{

}


