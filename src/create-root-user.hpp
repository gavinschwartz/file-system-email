#ifndef CREATE_ROOT_USER_HPP
#define CREATE_ROOT_USER_HPP
#include <string>
#include "User.hpp"

using namespace std;

User createRootUser()
{

    User rootUser;

    rootUser.userID = "gpDlgb1DEz";
    rootUser.username = "root";
    rootUser.password = "password";
    rootUser.emailAddress = "gpDlgb1DEz@aol.com";

    return rootUser;
}

#endif