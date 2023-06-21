#include<iostream>
#include<vector>
using namespace std;


#ifndef TWEETER
#define TWEETER

#include "user1.cpp"

class tweeter
{
private:
    vector <user> members; // users collection
    user *current; // to check who loges in
    bool login = false; // to check if loged in
    bool runCycle = true; // while true 

    bool flag = false ; // just to control

    std::string command;

public:
 
    //void func(); // call the other functions
    void run();
    void help() ;
    //void getCommand(); // cin and recognize commands
    void signup(std::string);
    void logIn(std::string, std::string);
    // void logIn(std::string);
    
    //void setLog(); // change login
    void setLog(bool); // set login
    //bool getLog(); // get back the login value


    void getCommandLogIn();
    void getCommandLogOut();

};

#endif // TWEETER