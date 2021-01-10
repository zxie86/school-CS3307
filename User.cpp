/**
 * @author Ates Avci
 * @date 04.11.2020
 * DEfinitions for User class.
 */

#include <iostream>
#include "User.h"
using namespace std;

    string User::getUsername(){
        return this->userName;
    }
    int User::getPassword(){
        return this->password;
    }

    User::User(string usrname, int pswrd){
        userName = usrname;
        password = pswrd;
    }

    User::~User(){
    }
