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
    void setColor(int hue, int saturation, int value);
    int getX();
    int getY();
    double getValue();
    QColor getColor();

    bool operator<(const Field& a);
    bool operator>(const Field& a);
    bool operator=(const Field& a);
};

#endif // FIELD_H
