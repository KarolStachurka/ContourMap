#ifndef FIELD_H
#define FIELD_H


class Field
{
private:
    int cordinateX;
    int cordinateY;
    int colorRed;
    int colorBlue;
    int colorGreen;
public:
    Field();
    void setCordinates(int x, int y);
};

#endif // FIELD_H
