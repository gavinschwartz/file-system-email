#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <string>
#include <ctime>
#include <iostream>

using namespace std;

class Email {
public:
   
    string userID;      
    string fromAddress;  // The sender's email address
    string toAddress;    // The recipient's email address
    string subject;      // The subject of the email
    string content;      // The content of the email
    time_t timestamp;    // The time when the email was sent or received
    bool isRead;              // A flag indicating if the email has been read
};

#endif // EMAIL_HPP
