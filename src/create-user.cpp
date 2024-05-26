#include <iostream>
#include "User.hpp"
#include <string>
#include "create-root-user.hpp"

using namespace std;

int main()

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
    }
    else
    {
        cout << "Login failure." << endl;
    }

    return 0;
}


