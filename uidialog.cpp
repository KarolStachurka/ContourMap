#include "uidialog.h"

UIDialog::UIDialog()
{
    inputOutput = new InputOutput();

}

void UIDialog::display()
{
    inputOutput->setFileName("test.csv");
    inputOutput->loadMatrix();
    board = Board(inputOutput->getMatrixInput());
}

Board UIDialog::getBoard()
{
    return board;
}
