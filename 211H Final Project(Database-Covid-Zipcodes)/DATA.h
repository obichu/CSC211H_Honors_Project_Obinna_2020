#ifndef _DATA_H_
#define _DATA_H_
#include <iostream>
#include "sqllite/sqlite3.h"
#include <string>
class Data
{
private:

public:
	int convertzip(const char*, int);
	int getdeaths(const char*, int);
	int getcases(const char*, int);
	double getdeathrate(const char*, int);
	double getcaserate(const char*, int);
	double getpercentpos(const char*, int);
	int gettotaltest(const char*, int);
	//string getareaname(const char*, int);

};
//now the issue is organizing the program so that it fits within class paradigms set up in this class.

#endif