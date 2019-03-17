#ifndef COLORPALETTE_H
#define COLORPALETTE_H

#include <QColor>

class ColorPalette
{
public:
    ColorPalette();
    ColorPalette(QColor maximumColor, QColor minimumColor);
    std::string getName();
    QColor getMaximumColor();
    QColor getMinimumColor();
    void setMinimumColor(QColor minimumColor);
    void setMaximumColor(QColor maximumColor);
private:
    QColor maximumColor;
    QColor minimumColor;
    std::string name;
};

#endif // COLORPALETTE_H
