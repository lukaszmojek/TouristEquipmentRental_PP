#include "FileOperations.h"

using namespace std;

fstream FileOperations::openFile(string fileName, ios_base::openmode fileMode)
{
    fstream file;
    file.open(fileName, fileMode);

    if (!file.is_open())
    {
        throw new exception("Couldn't open specified file!");
    }

    return file;
}

template <class DATA_TYPE>
bool FileOperations::saveDataToFile(fstream file, DATA_TYPE data)
{
    try
    {
        for (auto record : data)
        {
            file << data.toString();
        }

        return true;
    }
    catch (exception e)
    {
        return false;
    }
}
