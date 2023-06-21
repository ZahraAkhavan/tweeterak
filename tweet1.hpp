#include<iostream>
#include<string>

#ifndef TWEET
#define TWEET

struct moment
{
    int hour;
    int minute;
    
    void displayTime(); // time displaying
};

class tweet
{
    private:
        int like;
        std :: string post;
        static int counter; // to be constant even after delete any tweet
        int postId; 
        moment shareTime;
        
    public:
        tweet(); // push back the vector
        void likePost();
        void dislike();
        
        /*setter: */
        void setPost(std::string); // get the line from user
        
        /*getters: */
        int getLike(); // get back the like number
        std :: string getPost(); // get back the tweet
        int getPostId(); // get back the post code
        static int getCounter(); // get back that static counter
        
        /*displayers: */
        void timeShowing();
        void displayPost();
};
int tweet :: counter = 0 ;






#endif // TWEET_HPP