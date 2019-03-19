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
    std::map<std::string, ColorPalette> colorPaletteMap;

public:
    UIDialog();
    void display();
    Board getBoard();
    std::vector<std::string> createPalettesConfig();
    std::vector<std::string> getPaletteList();
    void setPalettesFromConfig(std::vector<std::string> config);
    void addNewPalette(std::string identifier, std::string name, QColor maximum, QColor minimum);
    void getPaletteColors(std::string identifier, std::string &name, QColor &maximum, QColor &minimum);
    void setPaletteColors(std::string identifier, std::string name, QColor maximum, QColor minimum);

};

#endif // UIDIALOG_H
