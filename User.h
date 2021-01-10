/**
 * @author Ates Avci
 * Header for User
 */

#ifndef USER_H
#define USER_H
#include <string>

class User{
    //Variables.
    private:
        std::string userName;
        int password;
    //Functions.
    public:
        std::string getUsername();
        int getPassword();
        User(std::string, int);
        ~User();


};
#endif