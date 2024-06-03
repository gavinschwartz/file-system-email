#ifndef LOGIN_HPP
#define LOGIN_HPP
#include <string>
#include "User.hpp"
#include <iostream>

User login();

using namespace std;

User login()
{
    LinkedList<User> allUsers = loadUsersFromFile();

    string userID;
    string userPassword;

    cout << "Login as existing user. " << endl;

    cout << "Enter your userID" << endl;
    cin >> userID;

    cout << "Enter your password." << endl;
    cin >> userPassword;

    int indexOfUser = allUsers.getIndexByID(userID);
    if (indexOfUser == -1)
    {
        cerr << "User not found" << endl;
        exit(1);
    }

    User user = allUsers.getDataByIndex(indexOfUser);

    if (userID == user.username && userPassword == user.password)
    {
        cout << "Login successful!" << endl;
        return user;
    }
    else
    {
        cout << "Login failure." << endl;
        exit(1);
    }
}

#endif