#include <iostream>
#include <cstdlib>
#include "User.hpp"
#include <string>
#include "login.hpp"
#include <fstream>
#include <sys/types.h>
#include <dirent.h>

User createUser();

bool directoryExists(string &dirName);
bool createDirectory(string &dirName);

using namespace std;

int main()

{
    string dirName = "data";
    if (!directoryExists(dirName))
    {
        // Directory does not exist, create it
        if (!createDirectory(dirName))
        {
            cerr << "Error creating directory 'data'" << endl;
            return 1;
        }
    }

    // Check if users.txt exists, if not create it
    fstream inputFile("data/users.txt", ios::in);
    if (!inputFile.is_open())
    {
        inputFile.close(); // Close the input file if it was open
        cout << "data/users.txt does not exist, creating the file" << endl;

        // Create the new empty output file
        fstream outputFile("data/users.txt", ios::out);
        if (!outputFile)
        {
            cerr << "Error creating file 'data/users.txt'" << endl;
            return 1;
        }
        outputFile.close(); // Close the output file

        // Reopen input file
        inputFile.open("data/users.txt", ios::in);
    }
    inputFile.close();

    bool loginSuccess = login();

    if (loginSuccess == false)
    {
        return 1;
    }
    User newUser = createUser();

    fstream outputFile;

    // executing fstream method to open this folder
    outputFile.open("data/users.txt", ios::out);

    outputFile << newUser.userID << endl;
    outputFile << newUser.username << endl;
    outputFile << newUser.password << endl;
    outputFile << newUser.email << endl;
    outputFile << newUser.isAdmin << endl;

    return 0;
}

User createUser()
{
    User newUser;

    cout << "Enter UserID." << endl;
    cin >> newUser.userID;

    cout << "Enter Username." << endl;
    cin >> newUser.username;

    cout << "Enter Password." << endl;
    cin >> newUser.password;

    cout << "Enter Email." << endl;
    cin >> newUser.email;

    newUser.isAdmin = false;

    return newUser;
}

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
