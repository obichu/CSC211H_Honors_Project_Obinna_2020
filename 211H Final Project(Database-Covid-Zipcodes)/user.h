#ifndef _USER_H_
#define _USER_H_
#include "DATA.h"
#include "sqllite/sqlite3.h"
#include <iostream>
using namespace std;
class user : public Data
{
private:

	
	string name;
	string areaname;
	int zipcode;
	int deathcount;
	double deathrate;
	int casecount;
	double caserate;
	int totaltest;
	double pospercent;


public:
	void setprofile(const char*, int, string);
	void returnstats();

};
#endif

