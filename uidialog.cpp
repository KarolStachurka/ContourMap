#include "uidialog.h"

UIDialog::UIDialog()
{
    inputOutput = new InputOutput();

}

void UIDialog::display()
{
    inputOutput->setFileName("test.csv");
    inputOutput->loadMatrix();
    board = new Board(inputOutput->getMatrixInput());
}
