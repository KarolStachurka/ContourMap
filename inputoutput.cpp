#include "inputoutput.h"

InputOutput::InputOutput()
{

}

bool InputOutput::loadMatrix()
{
    std::ifstream file;
    std::string line;
    file.open(fileName);
    while(std::getline(file,line,'\n'))
    {
        matrixInput.push_back(line);
    }
}

void InputOutput::setFileName(std::string fileName)
{
    this->fileName = fileName;
}

std::vector<std::string> InputOutput::getMatrixInput()
{
    return matrixInput;
}
