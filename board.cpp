#include "board.h"

Board::Board()
{

}

Board::Board(std::vector<std::string> inputMatrix)
{
    std::vector<std::vector<double>> matrix;
    for(auto i:inputMatrix)
    {
        std::vector<double> matrixRow;
        std::stringstream ss(i);
        double number;
        while(ss >> number)
        {
            matrixRow.push_back(number);
            if (ss.peek() == ',')
            {
             ss.ignore();
            }

        }
        matrix.push_back(matrixRow);
    }
    int row = 0, col = 0;
    for(auto i:matrix)
    {
        for(auto j:i)
        {
            Field field(row, col, j);
            board.push_back(field);
            col++;
        }
        row++;
        sizeY = col;
        col = 0;
    }
    sizeX = row;
}

void Board::colourBoard(QColor max, QColor min)
{
    Field maxValueField = *std::max_element(board.begin(),board.end());
    Field minValueField = *std::min_element(board.begin(),board.end());
    double maxValue = maxValueField.getValue();
    double minValue= minValueField.getValue();

    int hueRatio = max.hue() - min.hue();
    int saturationRatio = max.saturation() - min.saturation();
    int valueRatio = max.value() - min.value();

    for(Field &i:board)
    {
        double ratio = getPositionInRange(minValue,maxValue,i.getValue());
        i.setColor(ratio * hueRatio + min.hue(),
                   ratio * saturationRatio + min.saturation(),
                   ratio * valueRatio + min.value()
                   );
    }

}

std::vector<Field> Board::getBoard()
{
    return board;
}

int Board::getSizeX()
{
    return sizeX;
}

int Board::getSizeY()
{
    return sizeY;
}
