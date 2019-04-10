#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

//!  Definition of class InputOutput.
/*!
  Class is responsible for loading and saving data used in program.
*/
class InputOutput
{
private:
    /// Path to file with matrix of values for contour map.
    std::string matrixFileName;
    /// Path t file with config values of color palettes.
    std::string configFileName;
    /// vector of strings with loaded input with matrix values data.
    std::vector<std::string> matrixInput;
    /// vector of strings with loaded config file data.
    std::vector<std::string> configInput;
public:
    //! Default constructor
        /*!
        */
    InputOutput();
    //! Loads matrix from file which path is defined in matrixFileNmae field.
        /*!
        */
    bool loadMatrix();
    //! Loads config from file which path is defined in configFileNmae field
        /*!
        */
    bool loadConfig();
    //! Sets path to file with input matrix
        /*!
          \param matrixFileName - path to file with matrix of values for contour map.
        */
    void setMatrixFileName(std::string matrixFileName);

    //! Saves current config of color palettes to config file.
        /*!
          \param config - vector of strings with loaded config file data.
        */
    void saveConfig(std::vector<std::string> config);
    //! returns vector of strings with loaded input with matrix values data.
        /*!
          \returns vector of strings with loaded input with matrix values data.
        */
    std::vector<std::string> getMatrixInput();
    //! returns vector of strings with loaded config file data.
        /*!
          \returns vector of strings with loaded config file data.
        */
    std::vector<std::string> getConfigInput();
};

#endif // INPUTOUTPUT_H
