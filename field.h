#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <QColor>


class Field
{
private:
    int cordinateX;
    int cordinateY;
    int colorRed;
    int colorBlue;
    int colorGreen;
    QColor color;
    double value;
public:
    Field();
    Field(int x, int y, double value);
    void setCordinates(int x, int y);
    void setColor(int red, int green, int blue);
    int getX();
    int getY();
    int getValue();
    QColor getColor();
};

#endif // FIELD_H
