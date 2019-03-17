#ifndef UIDIALOG_H
#define UIDIALOG_H

#include "inputoutput.h"
#include "board.h"


class UIDialog
{
private:
    Board board;
    InputOutput *inputOutput;

public:
    UIDialog();
    void display();
    Board getBoard();

};

#endif // UIDIALOG_H
