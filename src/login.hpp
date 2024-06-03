#ifndef LOGIN_HPP
#define LOGIN_HPP
#include <string>
#include "User.hpp"
#include <iostream>


bool login();

using namespace std;


bool login()
{
    User rootUser = createRootUser();

    string userUsername;
    string userPassword;

    cout << "Login as existing user. " << endl;

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