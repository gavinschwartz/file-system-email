#ifndef LOGIN_HPP
#define LOGIN_HPP
#include <string>
#include "User.hpp"
#include <iostream>

User createRootUser();

bool login();

using namespace std;

User createRootUser()
{

    User rootUser;

    rootUser.userID = "gpDlgb1DEz";
    rootUser.username = "root";
    rootUser.password = "password";
    rootUser.email = "gpDlgb1DEz@aol.com";
    rootUser.isAdmin = true;

    return rootUser;
}

bool login()
{
    User rootUser = createRootUser();

    string userUsername;
    string userPassword;

    cout << "Enter your username." << endl;
    cin >> userUsername;

    cout << "Enter your password." << endl;
    cin >> userPassword;

    if (userUsername == rootUser.username && userPassword == rootUser.password)
    {
        cout << "Login successful!" << endl;
        return true;
    }
    else
    {
        cout << "Login failure." << endl;
        return false;
    }
}

#endif