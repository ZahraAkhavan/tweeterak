#include<iostream>
#include<string>

#include"password1.hpp"
using namespace std;

void password :: setCode()
{
    std::string str;
    
    while(true){
        //if password being longer than 4 digit, program will finish, not: try again.
        cin >> str;
        if (str.length() > 4){
            code = str;
            break;
        }
        else
            cout << "!your password is too short!! please enter again: ";
    }
}

std::string password :: getCode()
{
    return code;
}