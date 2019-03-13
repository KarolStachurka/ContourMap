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
}
