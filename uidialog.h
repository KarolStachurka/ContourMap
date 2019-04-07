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
    std::map<int, ColorPalette> colorPaletteMap;
    ColorPalette colorPalette;

public:
    UIDialog();
    ~UIDialog();
    void display();
    void loadBoard(std::string fileName);
    void setColorPalette(ColorPalette colorPalette);
    ColorPalette getColorPalette();
    Board getBoard();
    std::vector<std::string> createPalettesConfig();
    std::vector<std::string> getPaletteList();
    void setPalettesFromConfig(std::vector<std::string> config);
    void addNewPalette(int identifier, std::string name, QColor maximum, QColor minimum);
    void getPaletteColors(int identifier, std::string &name, QColor &maximum, QColor &minimum);
    void setPaletteColors(int identifier, std::string name, QColor maximum, QColor minimum);

};

#endif // UIDIALOG_H
