#ifndef UIDIALOG_H
#define UIDIALOG_H

#include "inputoutput.h"
#include "board.h"
#include "colorpalette.h"

#include <map>
#include <vector>
class UIDialog
{
private:
    Board board;
    InputOutput *inputOutput;
    std::map<std::string, ColorPalette> colorPaletteList;

public:
    UIDialog();
    void display();
    Board getBoard();
    std::vector<std::string> createPalettesConfig();
    void setPalettesFromConfig(std::vector<std::string> config);

};

#endif // UIDIALOG_H
