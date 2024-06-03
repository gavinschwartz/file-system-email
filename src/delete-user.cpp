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
    bool loginSuccess = login();

    if (loginSuccess == false)
    {
        return 1;
    }

    // Load up all existing users from file.
    LinkedList<User> allUsers = loadUsersFromFile();

    allUsers.print();

    // asking user which index to remove user
    cout << "What is the ID of the user you want to delete? " << endl;
    string id;
    cin >> id;
    if (id == string("root"))
    {
        cerr << "Cannot delete root user. " << endl;
        exit(1);
    }

    // reading in remove user method
    int indexToDelete = allUsers.getIndexByID(id);
    if (indexToDelete == -1)
    {
        cerr << "User not found" << endl;
        exit(1);
    }

    allUsers.remove(indexToDelete);

    // output save changes
    fstream outputFile;
    outputFile.open("data/users.txt", ios::out); // Open the file for writing
    allUsers.savetoFile(outputFile, 1);

    return 0;
}
