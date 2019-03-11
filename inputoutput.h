#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <string>
#include <vector>

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

};

#endif // INPUTOUTPUT_H
