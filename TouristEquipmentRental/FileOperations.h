#ifndef FILES_H
#define FILES_H

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class FileOperations
{
public:
    /**
     * \brief Opens a file
     * \param fileMode Depending if the file will be available for input or output, ios::in or ios::out
     * \param fileName Name of the file
     * \return Returns a reference to opened file
     */
    fstream openFile(string fileName, ios_base::openmode fileMode);

    /**
     * \brief Saves passed data to file
     * \param file File to which data should be saved
     * \param data Data to be written to file
     * \return Returns true data was written successfully and false if there was some error
     */
    template <class DATA_TYPE>
    bool saveDataToFile(fstream file, DATA_TYPE data);
};

#endif
