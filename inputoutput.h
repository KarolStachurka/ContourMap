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
    std::string fileName;
    std::vector<std::string> matrixInput;
public:
    InputOutput();
    bool loadMatrix();
    bool saveMap();
    bool loadMap();
    bool createFile();
    void setFileName(std::string fileName);
    void setfilePath(std::string filePath);
    std::vector<std::string> getMatrixInput();

};

#endif // INPUTOUTPUT_H
