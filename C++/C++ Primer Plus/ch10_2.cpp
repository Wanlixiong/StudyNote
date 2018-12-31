#include<iostream>
#include"head.h"
#pragma warning(disable : 4996)

Person::Person(const string & ln, const char * fn)
{
	lname = ln;
	strncpy(fname, fn, LIMIT);
	fname[LIMIT - 1] = '\0';		//×Ö·û´®Î²²¿±êÊ¶'\0'
}

void Person::Show()const
{
	std::cout << "name: " << lname << " " << fname << std::endl;
}

void  Person::FormalShow()const
{
	std::cout << "name: " << fname << " " << lname << std::endl;
}