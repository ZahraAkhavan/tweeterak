#include<iostream>
#include<string>
#include<exception>
#include <ctime>

#include "tweet1.hpp"

using namespace std ;


void moment::displayTime()
{
    time_t now = time(0);
    char* dt = ctime(&now);

    cout << endl << "The local date and time of this tweet is: " << dt << endl;
}

tweet::tweet()
{
    like = 0;
    postId = counter;
}


void tweet::likePost()
{
    like++;
}

void tweet :: dislike()
{
    like--;
}

void tweet :: setPost(std::string post1 = "")
{
    if(post1 == "")
        std::getline(cin, post);
    else
    {
        post = post1;
    }
    counter ++;
}

int tweet :: getLike()
{
    return like;
}

std ::string tweet :: getPost()
{
    return post;
}

int tweet :: getPostId()
{
    return postId;
}


int tweet :: getCounter ()
{
    return counter;
}

void tweet :: timeShowing()
{
   shareTime.displayTime();
}


void tweet :: displayPost()
{
    cout << post << endl 
        << "likes by " << like << " people" 
        << endl << "at";
    // cout << "shod?" << endl;
        timeShowing();
    cout << endl;
}