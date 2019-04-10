#ifndef COLORPALETTE_H
#define COLORPALETTE_H

#include <QColor>

//!  Definition of class ColorPalette.
/*!
  Class is responsible for storing palette of colors defined by user for contour map.
*/
class ColorPalette
{
public:
    //! Default constructor
        /*!
        */
    ColorPalette();

    //! Constructor:
    //! Creates color palette object, which contains color variety of contour map
        /*!
          \param name - name of palette
          \param maximumColor - color of maximum value on map
          \param minimumColor - color of minimum value on map
        */
    ColorPalette(std::string name, QColor maximumColor, QColor minimumColor);

    //! Return string with name of color palette
        /*!
          \returns name of palette
        */
    std::string getName();

    //! Return QColor of maximum value on contour map
        /*!
          \returns color defined for maximum value
        */
    QColor getMaximumColor();

    //! Return QColor of minimum value on contour map
        /*!
          \returns color defined for minimum value
        */
    QColor getMinimumColor();

    //! Sets  value of  minimum value on contour map
        /*!
          \param minimumColor - color of minimum value on map
        */
    void setMinimumColor(QColor minimumColor);

    //! Sets  value of  maximum value on contour map
        /*!
          \param maximumColor - color of maximum value on map
        */
    void setMaximumColor(QColor maximumColor);

    //! Sets value of string with name of color palette
        /*!
          \param name - new name of palette
        */
    void setName(std::string name);
private:
    /// Field stores color of minimum value on map.
    QColor maximumColor;
    /// Field stores color of maximum value on map.
    QColor minimumColor;
    /// Field stores name of palette.
    std::string name;
};

#endif // COLORPALETTE_H
