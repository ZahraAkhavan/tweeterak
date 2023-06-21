#include<iostream>
#include<vector>
#include<string>

#include "user1.hpp"

using namespace std;

user::user()
{
}

user :: user (std::string str){
    if(str[0] == '@' ){
        un.setUsername(str.substr(1));
    }
    else {
        un.setUsername(str);
    }
    cout << "$ password: ";
    Pc.setCode ();
    cin.ignore();
    cout << "$ name: ";
    setName();
    cout << "$ phone: ";
    setPhone();
    cout << endl << "* Registration was successful.\n" << endl;
    cin.ignore();
}

void user :: setName()
{
  std::getline(cin, name);
}

void user::setUn(std::string un1 = "")
{
    if( un1 == "")
        un.cinUsername();
    else
    {
        un.setUsername(un1);
    }
}

void user :: setPc()
{
	Pc.setCode();
}

void user :: setBio(std::string bio = "")
{
    bool flag = true;
    try
	{
        if (bio.length() > 160)
            throw invalid_argument("! biography must be less than 160 letter. \n please try again: ");
    }
    catch(invalid_argument obj)
	{
        cerr << obj.what();
        flag = false;
    }
    if (flag)
	{
        biography = bio;
    }
    else
    {
        std::string bio2;
        std::getline(cin, bio2);
		setBio(bio2);
    }
}

void user :: setLocation(std::string loc = "")
{
    location = loc;
}

void user :: setLink(std::string link0 = "")
{
    if (link0.substr(0 , 4) == "https")
	{
        link = link0;
    }
    else
		link = "https" + link0;
}

void user :: setBirthday(int a, int b, int c)
{
    bool flag = true;
    
    	try
		{
    		if (a>0 && a<32)
        		birthday.day = a;
    		else
				throw invalid_argument ("! wrong input for day! \n");
   			if (b>0 && b<31)
       			birthday.month = b;
    		else 
				throw invalid_argument ("! wrong input for month! \n");
    		birthday.age = 2023 - c;
    	}
    	catch (invalid_argument obj)
		{
        	cerr << obj.what();
        	flag = false;
    	}
        if(!flag)
        {
            int a1 = 0, b1 = 0, c1 = 0;
            cerr << "$ Enter again date of birth: ";
            cin >> a1 >> b1 >> c1;
            setBirthday(a1, b1, c1);
        }
  	
}

void user :: setPhone()
{
    bool flag = true;
    std::string str;
    while(flag)
	{
    	cin >> str;
    	if (str.length() < 12 && str.length() > 14)
		{
        	cerr << "! wrong length for phone number! \n";
            flag = 0;
    	}
    	for (int i=0; i<str.length(); i++)
		{
        	if (str[i]<48 && str[i]>57)
            {
                cerr <<"! wrong content!! \n";
                flag = 0;
                break;
            }
        }
    if (flag)
	{
        phone = str;
        break;
    }
    flag = 1;
  }
}

void user :: setColor(std::string color = "none")
{
    if(color != "none")
    {
        if( color == "white" || color == "red" || color == "orange" || color == "black")
	    {
            this -> color = color;
        }
        else
        {
		    if( color == "yellow" || color == "green" || color == "blue" || color =="violet")
		    {
        	    this -> color = color;
    	    }
        }
    }

    else
    {
        this -> color = "no color";
    }
}

std::string user :: getUn()
{
    return un.getUsername();
}

std::string user::getPc()
{
    return Pc.getCode();
}

int user :: getAge()
{
    return birthday.age;
}

void user :: addTweet(std::string zarfNewTweet = "")
{
    tweet temp;
    if(zarfNewTweet == "")
        temp.setPost();
    else
    {
        temp.setPost(zarfNewTweet);
    }
    tweets.push_back(temp);	
    cout << "* posted successfuly.";
}


int user :: vecSize()
{
    return tweets.size(); 
}


void user :: displayProfile()
{
    cout << "name: " << name << endl
        << "username: " << un.getUsername() << endl
        << "biography: " << biography << endl
        << "location: " << location << endl 
        << "link: " << link << endl 
        << "phone number: " << phone << endl
        << "header: " << color << endl;
        birthday.displayBirthday();
}


std :: string user :: search (int n)
{
    for (int i=0 ; i< tweets.size() ; i++)
    {
        if (tweets[i].getPostId() == n)
            return tweets[i].getPost();
    }
    return ("!no such tweet number");
}

void user :: deleteTweet (int n)
{
    int temp;
    for (int i=0 ; i<tweets.size() ; i++)
    {
        if (tweets[i].getPostId() == n)
            tweets.erase(tweets.begin() + i + 1);
    }
    cout << "* deleted compeletly. \n";
}

void user :: displayPosts()
{
    if(tweets.size() == 0 )
    {
        cout << "! you have 0 tweet...:(" << endl;
    }
    else
    {
        cout << "are fahmidam tweetat 0 nis!" << endl;
        for (int i=0 ; i<tweets.size() ; i++)
        {
            tweets[i].displayPost();
        }
    }
}

void birth :: displayBirthday()
{
    cout << month << "/" << day << "/" << year << endl;
}

void user::editTweet(int tweetID)
{
    for(int i = 0; i < tweets.size(); i++)
    {
        if( tweets[i].getPostId() == tweetID)
        {
            cout << "type new content of your tweet: ";
            tweets[i].setPost();
        }
    }
}
