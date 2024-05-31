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
        return "User: " + username + "\n" + "Email;: " + email + "\n";
    }

    void saveToFile(fstream &outputFile)
    {
        outputFile << userID << endl;   // Write the post text
        outputFile << username << endl; // Write the user name
        outputFile << password << endl; // Write the timestamp
        outputFile << email << endl;    // Write the timestamp
    }
};

#endif
