#ifndef USER_HPP
#define USER_HPP
#include <string>
#include <fstream>
#include "LinkedList.hpp"
#include "file-system.hpp"

using namespace std;

class User
{

public:
    string userID;
    string username;
    string password;
    string email;

    bool isAdmin;

    string toString()
    {
        return "User: " + username + "\n" + "Email: " + email + "\n" + "isAdmin:" + (isAdmin ? "true" : "false") + "\n";
    }

    void saveToFile(fstream &outputFile)
    {
        outputFile << userID << endl;
        outputFile << username << endl;
        outputFile << password << endl;
        outputFile << email << endl;
        outputFile << isAdmin << endl;
    }
};

User createUser();

LinkedList<User> loadUsersFromFile();

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

    cout << "Are you an Admin? " << endl;

    string dummy;
    cin >> dummy;
    cin.ignore(1, '\n');
    newUser.isAdmin = dummy == "Y";

    return newUser;
}

LinkedList<User> loadUsersFromFile()
{
    LinkedList<User> allUsers; // collection of all our users
    int userCount = 0;
    string dirName = "data";
    createDirectoryIfNotExist(dirName);

    // Check if users.txt exists, if not create it
    string fileName = "data/users.txt";
    bool fileAlreadyExists = fileExists(fileName);

    createFileIfNotExist(fileName);
    fstream inputFile(fileName, ios::in);

    if (fileAlreadyExists)
    {
        inputFile >> userCount; // Read the user count from the file
    }

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

        inputFile.getline(buffer, 64);
        userData.isAdmin = buffer == string("1");

        allUsers.add(userData); // adding new user to list

        delete[] buffer; // every time you allocate something with new, must unallocate with delete to free it
    }
    return allUsers;
}

#endif
