#ifndef UIDIALOG_H
#define UIDIALOG_H

#include "inputoutput.h"
#include "board.h"
#include "colorpalette.h"

#include <map>
#include <vector>

//!  Definition of class UIDialog.
/*!
  Class is responsible for handling user actions in program.
*/
class UIDialog
{
private:
    /// Field containig board object with currently loaded contour map.
    Board board;
    /// Field containing InputOutput object for handling file operations.
    InputOutput *inputOutput;
    /// Map containing all color palettes
    std::map<int, ColorPalette> colorPaletteMap;
    /// Currently used color palette in program
    ColorPalette colorPalette;

public:
    //! Default constructor
        /*!
        */
    UIDialog();
    //! Default destructor
        /*!
        */
    ~UIDialog();
    //! Colours current contour map with colors from currently choosen color palette.
        /*!
        */
    void display();
    //! Creates board with contour map from file with matrix of values
        /*!
          \param fileName - path to file with matrix of values
        */
    void loadBoard(std::string fileName);
    //! Sets currently used color palette
        /*!
          \param colorPalette - currently used color palette in program
        */
    void setColorPalette(ColorPalette colorPalette);
    //! Returns object with currently used color palette in program
        /*!
          \returns currently used color palette in program
        */
    ColorPalette getColorPalette();
    //! Returns board object with currently loaded contour map
        /*!
          \returns board object with currently loaded contour map
        */
    Board getBoard();
    //! Creates vector of strings with loaded config file data.
        /*!
          \returns  vector of strings with loaded config file data.
        */
    std::vector<std::string> createPalettesConfig();
    //! Creates vector with names of all color palettes
        /*!
          \returns vector with names of all color palettes
        */
    std::vector<std::string> getPaletteList();
    //! Creates map of color palettes with values from config
        /*!
          \param config - ector of strings with loaded config file data
        */
    void setPalettesFromConfig(std::vector<std::string> config);
    //! Adds new color palette to color palettes map
        /*!
          \param identifier - index of palette position on list
          \param name - stores name of palette
          \param maximum - stores color of maximum value on map
          \param minimum - stores color of minimum value on map
        */
    void addNewPalette(int identifier, std::string name, QColor maximum, QColor minimum);
    //! Returns palette parameters on position with given identifier
        /*!
          \param identifier - index of palette position on list
          \param name - stores name of palette
          \param maximum - stores color of maximum value on map
          \param minimum - stores color of minimum value on map
        */
    void getPaletteColors(int identifier, std::string &name, QColor &maximum, QColor &minimum);
    //! sets palette with new parameters on position with given identifier
        /*!
          \param identifier - index of palette position on list
          \param name - stores name of palette
          \param maximum - stores color of maximum value on map
          \param minimum - stores color of minimum value on map
        */
    void setPaletteColors(int identifier, std::string name, QColor maximum, QColor minimum);

};

#endif // UIDIALOG_H
