#include "field.h"

Field::Field()
{

}

Field::Field(int x, int y, double value)
{
    setCordinates(x,y);
    this->value = value;
}

void Field::setCordinates(int x, int y)
{
    cordinateX = x;
    cordinateY = y;
}
