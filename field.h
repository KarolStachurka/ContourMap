#ifndef FIELD_H
#define FIELD_H

#include <iostream>


class Field
{
private:
    int cordinateX;
    int cordinateY;
    int colorRed;
    int colorBlue;
    int colorGreen;
    double value;
public:
    Field();
    Field(int x, int y, double value);
    void setCordinates(int x, int y);
};

#endif // FIELD_H
