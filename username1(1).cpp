#include<iostream>
#include<string>
#include<vector>
#include<exception>
#include"username1.hpp"

using namespace std ;

void username ::setUsername(std::string str)
{
    
        if (checkUsername(str))
        {
            ID = str;
        }
        else
        {
            cinUsername();
        }
}

void username ::cinUsername()
{
    std :: string username;
    cin >> username;
    if (username[0] == '@')
        username = username.substr(1);
    setUsername(username);
}


bool username ::checkUsername(std::string str)
{
    if (str[0] == '@')
    {
        str = str.substr(1, str.length() - 1);
    }
    bool checker = true;
    try
    {   int zeroChar = char(str[0]);
        if (str.length() < 5)
        {
            throw invalid_argument("! username must be more than 5 digits!!\n");
        }
        
        else if (zeroChar > 47 && zeroChar < 58)
        {
            throw invalid_argument("! you can't set the numbers for first digit!! \n");
        }
        else if (str == "log in" || str == "log out" || str == "sign up" || str == "delete" )
        {
            throw invalid_argument("! this keyword is reserved!!\n");
        }
        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] < 48) || (str[i] > 57 && str[i] < 65) || (str[i] > 90 && str[i] < 97) || (str[i] > 122))
                throw invalid_argument("! password must contain numbers or letters!!\n");
        }
    }

    catch (invalid_argument obj)
    {
        cerr << obj.what();
        checker = false;
    }

    return checker;
}

void username ::printUsername()
{
    cout << "> @" << ID;
}

std::string username ::getUsername()
{
    return ID;
}