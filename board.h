#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <field.h>

class Board
{
    std::vector<std::vector<Field>> board;

public:
    Board();
    void createBoard();
    void colourBoard();
};

#endif // BOARD_H
