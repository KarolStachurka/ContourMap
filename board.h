#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <sstream>
#include <iostream>

#include <field.h>
#include <utils.h>


class Board
{
    std::vector<Field> board;
    int sizeX;
    int sizeY;

public:
    Board();
    Board(std::vector<std::string> inputMatrix);
    void createBoard();
    void colourBoard(QColor max, QColor min);
    std::vector<Field> getBoard();
    int getSizeX();
    int getSizeY();
};

#endif // BOARD_H
