#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>

using namespace std;

bool directoryExists(string &dirName);
bool createDirectory(string &dirName);
//TODO: create fileExists method code.
//bool fileExists(string &fileName);

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