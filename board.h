#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <sstream>
#include <iostream>

#include <field.h>
#include <utils.h>

//!  Definition of class board.
/*!
  Class is responsible for storing map created from input matrix and colouring it.
*/
class Board
{
    /// Field stores vector of Fields of whole board.
    std::vector<Field> board;
    /// Field stores number of x size of board.
    int sizeX;
    /// Field stores number of x size of board.
    int sizeY;

public:
    //! Default constructor
        /*!
        */
    Board();
    //! Constructor:
    //! Creates board object, which contains all fields of contour map
        /*!
          \param inputMatrix - container with strings of input matrix with values of map
        */
    Board(std::vector<std::string> inputMatrix);
    //! Changes colors of all fields based on minium and maximum value fields colors
        /*!
          \param max    color of field with maximum value
          \param min    color of field with minimum value
        */
    void colourBoard(QColor max, QColor min);
    //! returns vector of objects representing each field of map
        /*!
          \returns vector of fields of contour map
        */
    std::vector<Field> getBoard();

    //! returns x size of board
        /*!
          \returns x size of map
        */
    int getSizeX();

    //! returns y size of board
        /*!
          \returns y size of map
        */
    int getSizeY();
};

#endif // BOARD_H
