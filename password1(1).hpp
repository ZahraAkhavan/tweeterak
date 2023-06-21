#include <iostream>
#include <string>

#ifndef PASSWORD
#define PASSWORD

class password
{
	private:
    	std::string code;

	public:
    	void setCode(); // cin and set code
    	std::string getCode(); // get back code
};

#endif // PASSWORD