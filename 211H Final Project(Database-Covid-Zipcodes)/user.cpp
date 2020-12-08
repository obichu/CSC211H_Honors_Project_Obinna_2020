#include "user.h"
#include "Data.h"
#include <iostream>
#include "sqllite/sqlite3.h"
using namespace std;



void user::setprofile(const char* dir, int zip, string n) {
	
	zip = this->convertzip(dir, zip);
	
	cout << "\nzip at this moment is " << zip;
	if (zip == 0) {
		throw runtime_error("\nInvalid Zipcode");
	}
	casecount = this->getcases(dir, zip);
	deathcount = this->getdeaths(dir, zip);
	caserate = this->getcaserate(dir, zip);
	deathrate = this->getdeathrate(dir, zip);
	pospercent = this->getpercentpos(dir, zip);
	totaltest = this->gettotaltest(dir, zip);
	//areaname = this->getareaname(dir, zip);
	name = n;
}
