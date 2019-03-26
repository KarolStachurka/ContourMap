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
        col = 0;
    }
    colourBoard();
}

void Board::colourBoard()
{
    std::sort(board.begin(),board.end());
    Field max = *std::max_element(board.begin(),board.end());
    Field min = *std::min_element(board.begin(),board.end());
    double maxValue = max.getValue();
    double minValue= min.getValue();

    for(Field &i:board)
    {
        double ratio = getPositionInRange(minValue,maxValue,i.getValue());
        i.setColor(ratio*255,ratio*255,0);
    }

}

std::vector<Field> Board::getBoard()
{
    return board;
}
