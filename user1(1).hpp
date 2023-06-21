#include<iostream>
#include<string>
#include<vector>

#include"username1.cpp"
#include"password1.cpp"
#include"tweet1.cpp"

#ifndef USER
#define USER

class tweet;

struct birth
{
    int day = 1;
    int month = 1;
    int year = 1990;
    int age = 33;
    void displayBirthday();
};

class user
{
private:
    std::vector <tweet> tweets;
    std::string name;
    username un;
    password Pc;
    std::string biography;
    std::string location;
    std::string link;
    birth birthday;
    std::string phone;
    std::string color;


public:
    
    // constructor: // when some one signing up
    user();
    user(std::string);
    // setters:
    void setName();
	void setUn(std::string);
    void setPc();
    void setPhone();
    void setBio(std::string);
    void setLocation(std::string);
    void setLink(std::string);
    void setBirthday(int, int, int);
    void setColor(std::string);

    // getters:
    std::string getUn();
    std::string getPc();
    int getAge();
    void addTweet(std::string); // push back the tweets vector
    int vecSize(); // give the length of tweets vector

    // to show profile info:
    void displayProfile();

    std ::string search(int); // to show the n_th tweeet of an account

    void deleteTweet(int);
    
    // void displayPost(int);
    void displayPosts();

    //editors:
    void editTweet(int);
};

#endif // USER