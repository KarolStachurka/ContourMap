#include "uidialog.h"

UIDialog::UIDialog()
{
    inputOutput = new InputOutput();
    inputOutput->loadConfig();
    setPalettesFromConfig(inputOutput->getConfigInput());

}

UIDialog::~UIDialog()
{
    inputOutput->saveConfig(createPalettesConfig());
}

void UIDialog::display()
{
    inputOutput->setMatrixFileName("test.csv");
    inputOutput->loadMatrix();
    board = Board(inputOutput->getMatrixInput());
    board.colourBoard(colorPalette.getMaximumColor(), colorPalette.getMinimumColor());
}

void UIDialog::addNewPalette(std::string identifier, std::string name, QColor maximum, QColor minimum)
{
    ColorPalette palette = ColorPalette(name,minimum,maximum);
    colorPaletteMap.insert(std::pair<std::string,ColorPalette>(identifier,palette));
}

void UIDialog::getPaletteColors(std::string identifier, std::string &name, QColor &maximum, QColor &minimum)
{
    ColorPalette palette = colorPaletteMap.at(identifier);
    name = palette.getName();
    maximum = palette.getMaximumColor();
    minimum = palette.getMinimumColor();
}

void UIDialog::setPaletteColors(std::string identifier, std::string name, QColor maximum, QColor minimum)
{
    ColorPalette &palette = colorPaletteMap[identifier];
    palette.setName(name);
    palette.setMaximumColor(maximum);
    palette.setMinimumColor(minimum);
}

void UIDialog::setPalettesFromConfig(std::vector<std::string> config)
{
    for(auto i:config)
    {
        std::string name, identifier;
        std::stringstream ss(i);
        int number;
        std::vector<int> configRow;
        std::getline(ss, identifier, ',');
        std::getline(ss, name, ',');
        while(ss >> number)
        {
            configRow.push_back(number);
            if (ss.peek() == ',')
            {
             ss.ignore();
            }

        }
        try
        {
            QColor maximum = QColor(configRow[0],configRow[1],configRow[2]);
            QColor minimum = QColor(configRow[3],configRow[4],configRow[5]);
            addNewPalette(identifier,name,maximum,minimum);
        }
        catch(std::exception e)
        {
        }
    }
}

std::vector<std::string> UIDialog::createPalettesConfig()
{
    std::vector<std::string> config;
    for( auto &i:colorPaletteMap)
    {
        std::stringstream ss;
        ss << i.first << ","
           << i.second.getName() << ","
           << i.second.getMinimumColor().red() << ","
           << i.second.getMinimumColor().green() << ","
           << i.second.getMinimumColor().blue() << ","
           << i.second.getMaximumColor().red() << ","
           << i.second.getMaximumColor().green() << ","
           << i.second.getMaximumColor().blue();
        config.push_back(ss.str());
    }
    return config;

}

void UIDialog::setColorPalette(ColorPalette colorPalette)
{
    this->colorPalette = colorPalette;
}
ColorPalette UIDialog::getColorPalette()
{
    return colorPalette;
}


Board UIDialog::getBoard()
{
    return board;
}
std::vector<std::string> UIDialog::getPaletteList()
{
    std::vector<std::string> paletteList;
    for( auto &i:colorPaletteMap)
    {
        paletteList.push_back(i.second.getName());
    }
    return paletteList;
}

