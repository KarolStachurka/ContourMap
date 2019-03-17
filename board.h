#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <sstream>
#include <iostream>

#include <field.h>


class Board
{
    std::vector<Field> board;

public:
    Board();
    Board(std::vector<std::string> inputMatrix);
    void createBoard();
    void colourBoard();
    std::vector<Field> getBoard();
};

#endif // BOARD_H
