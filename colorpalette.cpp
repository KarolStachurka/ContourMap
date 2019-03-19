#include "colorpalette.h"

ColorPalette::ColorPalette()
{

}

ColorPalette::ColorPalette(std::string name, QColor maximumColor, QColor minimumColor)
{
    this->name = name;
    this->maximumColor = maximumColor;
    this->minimumColor = minimumColor;
}

std::string ColorPalette::getName()
{
    return name;
}

QColor ColorPalette::getMaximumColor()
{
    return maximumColor;
}

QColor ColorPalette::getMinimumColor()
{
    return minimumColor;
}

void ColorPalette::setName(std::string name)
{
    this->name = name;
}

void ColorPalette::setMinimumColor(QColor minimumColor)
{
    this->minimumColor = minimumColor;
}

void ColorPalette::setMaximumColor(QColor maximumColor)
{
    this->maximumColor = maximumColor;
}
