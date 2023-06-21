#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "tweeter1.hpp"

using namespace std;

void tweeter ::run()
{
    cout << "hey dude!:) welcome to tweeterak!;)" << endl <<
    "we wish you have a nice journy in our app!:)" << endl <<
    "tweeterak by : OriginalKaz" << endl <<
    "Reyhaneh Sadat Khosravi - 40112358014" << endl <<
    "Zahra Akhavan Attar - 40112358001" << endl;
    while (true)
    {
        while (!login)
        {
            cout << "\n> ";
            getline(cin, command);
            for(int i = 0; i < command.size(); i++)
            {
                tolower(command[i]);
            }
            getCommandLogOut();
        }

        while (login)
        {
            cout << "\n> @" << current-> getUn() << " > ";
            getline(cin, command);
            for(int i = 0; i < command.size(); i++)
            {
                tolower(command[i]);
            }
            getCommandLogIn();
        }

    }
}

void tweeter ::getCommandLogOut()
{
    if (command == "help")
    {
        help();
    }

    else if (command[0] == 's')
    {
        std::string zarfs = "";
        for(int i = 0; i < 6; i++)
        {
            zarfs += command[i];
        }
        if(zarfs == "signup")
        {
            std::string zarfUn2 = "";
            for(int i = 7; i < command.size(); i++ )
            {
                if(command[i] != '@')
                {
                    zarfUn2 += command[i];
                    cout << zarfUn2 << endl;
                }
            }
        signup(zarfUn2);
        login = true;
        }
    }

    else if (command[0]== 'l' && command.size() > 5)
    {
        std::string zarfCom3 = "";
        for(int h = 0; h< 5; h++)
        {
            zarfCom3 += command[h];
        }

        if(zarfCom3 == "login")
        {
        std::string zarfUN = "";
        for(int i = 6; command[i] != ' '; i++)
        {
            zarfUN += command[i];
            if(command[i+1] == ' ')
            {
                std::string zarfPass = "";
                for(int j = i+2; j < command.size(); j++)
                {
                    zarfPass += command[j];
                }
                if(zarfPass == "")
                {
                    std::getline(cin, zarfPass);
                }
                logIn(zarfUN, zarfPass);
            }
        }
        }
    }

    else if (command == "login")
    {
        logIn("", "");
        cin.ignore();
    }

    else if(command == "exit" || command == "q" || command == "quit")
    {
        std::cout << "mammad ma ro door nandaz ma unghadram be dard nakhor nistim!" << endl << "bye bye mammad!";
        abort();
    }

}

void tweeter ::getCommandLogIn()
{
    std::string newone;
    for(int i = 0; i < 5; i++)
    {
        newone += command[i];
    }
    // bool find
    if (command == "help")
    {
        help();
    }

    if (command == "logout")
    {
        delete current;
        login = false;
    }

    else if (command == "me" || command == "profile")
    {
        current->displayProfile();
    }

    else if (command.substr(0, 8) == "profile @")
    {
        for (int i = 0; i < members.size(); i++)
        {
            if (command.substr(9) == members[i].getUn())
            {
                members[i].displayProfile();
            }
        }
    }
    
    else if (newone == "tweet")
    {
        std::string zarfNewTweet;
        if(command[6] == '"')
        {
            for(int i = 7; i < command.size() - 1; i++)
            {
                zarfNewTweet+= command[i];
            }
        }
        else
        {
            for(int i = 6; i < command.size(); i++)
            {
                zarfNewTweet+= command[i];
            }
        }
        current->addTweet(zarfNewTweet);
    }

    else if (command == "delete account")
    {
        cout << "> @" << current-> getUn() << " >are you surue? y/n: ";
        char ch;
        cin >> ch;

        if (ch == 'y')
        {
            for (int i = 0; i < members.size(); i++)
            {
                members.erase(members.begin()+i);
                delete current;
                setLog(false);
            }
        }
    }

    else if (command[0] == 'd')
    {
        std::string comChecker = "d";
        for(int i = 1; i < 12; i++)
        {
            comChecker += command[i];
        }
        if(comChecker == "delete tweet")
        {
        int temp = 0;
        std::string zarfTweetNum;
        for(int i = 12; i < command.size(); i++){
            zarfTweetNum += command[i];
        }
        temp = stoi(zarfTweetNum);
        current -> deleteTweet(temp);
        }
    }

    else if (command[0] == '@')
    {
      if(command == "@me")
      {
            current -> displayPosts();
      }
      else
      {
        bool check = 0;
        int num = 0;
        num = command.find(':');
        if (num > -1)
        {
            int tweetid;
            tweetid = stoi(command.substr(num+1));
            for (int i=0 ; i<members.size() ; i++)
            {
                if (members[i].getUn() == command.substr(1,num-1) )
                {
                    cout << members[i].search(tweetid);
                    check = 1;
                }
            }
            if (!check)
            {
                cout << "! no such username" << endl;
            }
        }
        else 
        {
            for (int i=0 ; i<members.size() ; i++)
            {
                if (members[i].getUn() == command.substr(1) )
                {
                    members[i].displayPosts();
                }
            }
            if (!check)
            {
                cout << "! no such username" << endl;
            }
        }
      }
    }


    else if (command == "@me")
    {
        current -> displayPosts();
    }

    else if(command == "exit" || command == "q" || command == "quit")
    {
        std::cout << "mammad ma ro door nandaz ma unghadram be dard nakhor nistim!" << endl << "bye bye mammad!";
        abort();
    }

    else
    {
        std::string zarfEdit;
        for(int i = 0; i < 4; i++){
            zarfEdit += command[i];
        }
        if(zarfEdit == "edit"){
            std::string zarfCom;
            int zarfI = 0;
            for(int i = 5; ; i++){
                if(command[i] == ' ')
                    break;
                zarfCom+= command[i];
                zarfI = i;
            }
            if(zarfCom == "tweet"){
                if(current -> getAge() > 18 )
                {
                    int zarfNumTwwet = stoi(command.substr(zarfI+2));
                    current -> editTweet(zarfNumTwwet);
                }
                else
                {
                    cerr << "! sorry! you are unde eighteen... you can't tweet." << endl;
                }
            }
            else if( zarfCom == "profile")
            {
                std::string zarfCom2;
                std::string jaigozin;
                for(int i = zarfI+2; i < command.size(); i++)
                {
                    if(command[i] == ' ')
                    {   
                        if(command[i+1] == '"')
                        {
                            for(int j = i+2; j < command.size() - 1; j++)
                            {
                                jaigozin += command[j];
                            }
                        }
                        else
                        {
                            for(int j = i+1; j < command.size(); j++)
                            {
                                jaigozin += command[j];
                            }
                        }
                        break;
                    }
                    zarfCom2 += command[i];
                }
                if(zarfCom2 == "name")
                {
                    current -> setName();
                }
                else if(zarfCom2 == "username")
                {
                    current -> setUn();
                }
                else if(zarfCom2 == "password")
                {
                    current -> setPc();
                }
                else if(zarfCom2 == "location")
                {
                    current -> setLocation(jaigozin);
                }
                else if(zarfCom2 == "phone")
                {
                    current -> setPhone();
                }
                else if(zarfCom2 == "color")
                {
                    current -> setColor(jaigozin);
                }
                else if(zarfCom2 == "bio" || zarfCom2 == "biography" )
                {
                    current -> setBio(jaigozin);
                }
                else
                {
                    cout << "! Undefined command for edit(mammad havaset jaam nista!)" << endl;
                }

            }

        }
    }
}

void tweeter ::logIn(std::string username1 = "", std::string pass1 = "")
{

    std::string username;
    std::string password;
    bool flag = true;
    if (members.size() == 0)
    {
        cout << "! there is no user yet!!";
    }
    else
    {
        bool findmember = false;
        while (flag && !findmember)
        {
            if(username1 == "")
            {
            cout << "> enter username : ";
            cin >> username;
            }
            else
            {
            username = username1;
            }
            
            for (int i = 0; i < members.size() && findmember == false; i++)
            {
                if (username == members[i].getUn())
                {
                    findmember = true;
                    cout << "username o peyda kardam" << endl;
                    bool findpass = false;
                    while(!findpass)
                    {
                    if(pass1 == "")
                    {
                    cout << "> enter password:";
                    cin >> password;
                    }
                    else
                    {
                        password = pass1;
                    }
                    if (members[i].getPc() == password)
                    {   
                        setLog(true);
                        cout << "> @" << username << " > *log in successfully.\n";
                        current = &members[i];
                        flag = false;
                        findpass = true;
                        break;
                    }
                    else
                    {
                        cout << pass1 << "! wrong password!" << endl;
                        pass1 = "";
                    }
                    }
                }
            }
            if(!findmember)
            {
                cerr << "! invalid username... please try again:(" << endl;
                username1 == "";
            }
        }
    }
}

void tweeter ::setLog(bool f)
{
    login = f;
}

void tweeter ::help()
{

    cout << "\n> help:\n\n"
         << "sign up     ---> "
         << "creat an account\n"
         << "log in      ---> "
         << "sign in your account\n"
         << "log out     ---> "
         << "sign out your account\n"
         << "help        ---> "
         << "display menu\n"
         << "profile     ---> "
         << "show profs\n"
         << "like        ---> "
         << "liking tweets\n"
         << "dislike     ---> "
         << "disliking tweets\n"
         << "edit        ---> "
         << "can edit any option by adding after edit with --\n"
         << "link      ---> "
         << "add or edit your web link\n"
         << "color     ---> "
         << "edit your header color\n"
         << "biography ---> "
         << "add , edit or delete biogaraphy in 160 characters\n"
         << "locatin   ---> "
         << "edit your location\n"
         << "birthday  ---> "
         << "edit your birthday\n"
         << "tweet     ---> "
         << "only for age upper than 18\n"
         << "phone     ---> "
         << "change your phone number \n"
         << "username  ---> "
         << "edit your username with told parameters\n"
         << "password  ---> "
         << "edit password with told parameters\n";
}

void tweeter :: signup(std::string username1 = "")
{

    user test;
    bool findun2 = false;
    bool parametr = false;
    while(true)
    {
        if(username1 == "" )
        {
        cout << "$ enter username: ";
        test.setUn();
        }
        else{
            parametr = true;
        }
        for (int i=0 ; i<members.size(); i++)
        {
            if (test.getUn() == members[i].getUn())
            {
                cout << "the username must be special";
                findun2 = true;
                username1 = "";
            }
        }
        if(!findun2)
        {
            test.setUn(username1);
            break;
        }
    }
    if(!parametr)
    {
        cin.ignore();
    }
    cout << endl << "$ enter name: ";
    test.setName();
    cout <<endl << "$ enter password: ";
    test.setPc();
    cout << endl << "$ enter phone: ";
    test.setPhone();
    members.push_back(test);
    current = &members[members.size()-1];
    setLog(true);
}