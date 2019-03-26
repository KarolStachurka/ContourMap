#include "field.h"

Field::Field()
{

}

Field::Field(int x, int y, double value)
{
    setCordinates(x,y);
    this->value = value;
    setColor(100,0,0);
}

void Field::setCordinates(int x, int y)
{
    cordinateX = x;
    cordinateY = y;
}

void Field::setColor(int red, int green, int blue)
{
    color = QColor(red,green,blue);
}

double Field::getValue()
{
    return value;
}

int Field::getX()
{
    return cordinateX;
}

int Field::getY()
{
    return cordinateY;
}

QColor Field::getColor()
{
    return color;
}

bool Field::operator<(const Field& a)
{
    return this->value < a.value;
}

bool Field::operator>(const Field& a)
{
    return this->value > a.value;
}

bool Field::operator=(const Field& a)
{
    return this->value = a.value;
}
