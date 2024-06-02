#ifndef USER_HPP
#define USER_HPP
#include <string>
#include <fstream>

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

#endif
