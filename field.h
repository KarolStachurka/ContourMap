#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <QColor>

//!  Definition of class Field.
/*!
  Class is responsible for storing parameters of single field of contour map.
*/
class Field
{
private:
    /// Class field stores x coordinate of field on map.
    int cordinateX;
    /// Class field stores y coordinate of field on map.
    int cordinateY;
    /// Class field stores color of this field.
    QColor color;
    /// Class field stores value of this field.
    double value;
public:
    //! Default constructor
        /*!
        */
    Field();
    //! Constructor:
    //! Creates field object, which contains parameters of single field on contour map
        /*!
          \param x - x coordinate of field.
          \param y - y coordinate of field.
          \param value - value of field
        */
    Field(int x, int y, double value);
    //! Sets coordinates of field
        /*!
          \param x - x coordinate of field.
          \param y - y coordinate of field.
        */
    void setCordinates(int x, int y);
    //! Sets color of field
        /*!
          \param hue - value of Hue in HSV color format.
          \param saturation - value of Saturation in HSV color format.
          \param value - value of Value in HSV color format.
        */
    void setColor(int hue, int saturation, int value);
    //! Return x coordinate of field
        /*!
          \returns x coordinate of field on map.
        */
    int getX();
    //! Return y coordinate of field
        /*!
          \returns y coordinate of field on map.
        */
    int getY();
    //! Return value of this field
        /*!
          \returns value of field
        */
    double getValue();
    //! Return QColor of field on contour map
        /*!
          \returns color defined for this field value
        */
    QColor getColor();

    bool operator<(const Field& a);
    bool operator>(const Field& a);
    bool operator=(const Field& a);
};

#endif // FIELD_H
