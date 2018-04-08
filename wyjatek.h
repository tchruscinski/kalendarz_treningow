#ifndef _WYJATEK_H_
#define _WYJATEK_H_
#include <iostream>
#include <stdexcept>

using namespace std;

class blankField: public exception
{
public:
	virtual const char* what()const throw();
};
#endif