#include<iostream>
#include<string>

#ifndef USERNAME
#define USERNAME

class username
{
    private :
        std::string ID;

        //static vector <std::string> uns;

    public :
        void setUsername(std::string); // gain id as parameter
		void cinUsername(); // gain user id 
        bool checkUsername(std::string); // check parameters
        
        void printUsername(); // display
        std::string getUsername(); // get back
        
        
} ;
#endif // USERNAME