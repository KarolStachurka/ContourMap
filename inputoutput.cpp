#include "inputoutput.h"

InputOutput::InputOutput()
{
    configFileName = "config.csv";
}

bool InputOutput::loadMatrix()
{
    std::ifstream file;
    std::string line;
    matrixInput.clear();
    file.open(matrixFileName);
    while(std::getline(file,line,'\n'))
    {
        matrixInput.push_back(line);
    }
}

bool InputOutput::loadConfig()
{
    std::ifstream file;
    std::string line;
    configInput.clear();
    file.open(configFileName);
    while(std::getline(file,line,'\n'))
    {
        configInput.push_back(line);
    }
}

void InputOutput::saveConfig(std::vector<std::string> config)
{
    std::ofstream file;
    file.open(configFileName);
    for(auto i:config)
    {
        file << i << "\n";
    }
}

void InputOutput::setMatrixFileName(std::string matrixFileName)
{
    this->matrixFileName = matrixFileName;
}

std::vector<std::string> InputOutput::getMatrixInput()
{
    return matrixInput;
}
std::vector<std::string> InputOutput::getConfigInput()
{
    return configInput;
}
