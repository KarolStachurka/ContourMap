#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class InputOutput
{
private:
    std::string filePath;
    std::string matrixFileName;
    std::string configFileName;
    std::vector<std::string> matrixInput;
    std::vector<std::string> configInput;
public:
    InputOutput();
    bool loadMatrix();
    bool loadConfig();
    bool saveMap();
    bool loadMap();
    bool createFile();
    void setMatrixFileName(std::string matrixFileName);
    void setfilePath(std::string filePath);
    std::vector<std::string> getMatrixInput();
    std::vector<std::string> getConfigInput();
};

#endif // INPUTOUTPUT_H
