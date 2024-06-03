#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>
#include "User.hpp"
#include "login.hpp"
#include "LinkedList.hpp"
#include "file-system.hpp"

using namespace std;

int main()

{

    User loggedInUser = login();

    if (!loggedInUser.isAdmin)
    {
        cout << "You must be an admin to run this. " << endl;
        return 1;
    }

    // Load up all existing users from file.
    LinkedList<User> allUsers = loadUsersFromFile();

    // input user data from the console
    User newUser = createUser();

    allUsers.add(newUser); // adding new user to list

    fstream outputFile;                          // File stream for output
    outputFile.open("data/users.txt", ios::out); // Open the file for writing

    allUsers.savetoFile(outputFile, 1);

    return 0;
}