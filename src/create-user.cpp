#include <iostream>
#include <cstdlib>
#include "User.hpp"
#include <string>
#include "login.hpp"
#include <fstream>
#include <sys/types.h>
#include <dirent.h>
#include "LinkedList.hpp"

// function prototypes
User createUser();

bool directoryExists(string &dirName);
bool createDirectory(string &dirName);
void loadUsersFromFile(string &users, LinkedList<User> &allUsers);

using namespace std;

int main()

{
    LinkedList<User> allUsers; // collection of all our users
    int userCount = 0;
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
    else // if the file did already exist
    {
        inputFile >> userCount; // Read the user count from the file
    }

    bool loginSuccess = login();

    if (loginSuccess == false)
    {
        return 1;
    }

    // Load up all existing users from file.
    cout << "user count = " << userCount << endl; // Output the user count
    inputFile.ignore(1, '\n');                    // Ignore the newline character after the count
    for (int i = 0; i < userCount; i++)
    {
        User userData;
        char *buffer = new char[128];

        inputFile.getline(buffer, 64);
        userData.userID = string(buffer);

        inputFile.getline(buffer, 64);
        userData.username = string(buffer);

        inputFile.getline(buffer, 64);
        userData.password = string(buffer);

        inputFile.getline(buffer, 64);
        userData.email = string(buffer);

        allUsers.add(userData); // adding new user to list

        delete[] buffer; // every time you allocate something with new, must unallocate with delete to free it
    }

    // input user data from the console
    User newUser = createUser();

    allUsers.add(newUser); // adding new user to list

    fstream outputFile;                  // File stream for output
    outputFile.open("data/users.txt", ios::out); // Open the file for writing

    allUsers.savetoFile(outputFile);

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