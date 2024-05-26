#ifndef USER_HPP
#define USER_HPP
#include <string>

using namespace std;

class User
{

public:
    string userID;
    string username;
    string password;
    string emailAddress;

    bool isAdmin;
};

#endif
