#ifndef FILE_SYSTEM_HPP
#define FILE_SYSTEM_HPP
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>

using namespace std;

bool directoryExists(string &dirName);
bool createDirectory(string &dirName);
void createDirectoryIfNotExist(string &dirName);
bool fileExists(string &fileName);

// TODO: create fileExists method code.
// bool fileExists(string &fileName);

bool directoryExists(string &dirName)
{
    DIR *dir = opendir(("./" + dirName).c_str());
    if (dir)
    {
        closedir(dir);
        return true;
    }
    else
    {
        return false;
    }
}

bool createDirectory(string &dirName)
{
    return system(("mkdir " + dirName).c_str()) == 0;
}

void createDirectoryIfNotExist(string &dirName)
{
    if (!directoryExists(dirName))
    {
        // Directory does not exist, create it
        if (!createDirectory(dirName))
        {
            cerr << "Error creating directory 'data'" << endl;
            exit(1);
        }
    }
}

bool fileExists(string &fileName)
{
    fstream inputFile(fileName, ios::in);
    if (!inputFile.is_open())
    {
        inputFile.close(); // Close the input file if it was open
        return false;
    }
    else
    {
        inputFile.close(); // Close the input file if it was open
        return true;
    }
}

void createFileIfNotExist(string &fileName)
{
    bool fileAlreadyExists = fileExists(fileName);
    if (!fileAlreadyExists)
    {
        cout << fileName << " does not exist, creating the file" << endl;

        // Create the new empty output file
        fstream outputFile(fileName, ios::out);
        if (!outputFile)
        {
            cerr << "Error creating file " << fileName << endl;
            exit(1);
        }
    }
}
#endif
