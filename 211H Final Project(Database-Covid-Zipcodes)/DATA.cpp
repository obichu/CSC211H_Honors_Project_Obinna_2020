#include "DATA.h"
#include <iostream>
#include "sqllite/sqlite3.h"
using namespace std;

int Data::convertzip(const char* dir, int zip) {
	sqlite3* db;
	sqlite3_stmt* stmt;
	int a;
	sqlite3_open(dir, &db);
	string sql = "SELECT modded FROM ZIPCONVERTER WHERE normal = " + to_string(zip);
	int rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, nullptr);
	if (rc != SQLITE_OK) { //this line of code should check if it returns something wrong
		sqlite3_finalize(stmt);
		throw "no such zip";
	}
	sqlite3_step(stmt);
	a = sqlite3_column_int(stmt, 0);
	sqlite3_finalize(stmt);
	return a;

}
int Data::getdeaths(const char* dir, int zip) {

	sqlite3* db;
	sqlite3_stmt* stmt;
	int a;
	const unsigned char* b;

	sqlite3_open(dir, &db);
	string sql = " SELECT death_count, name  FROM DATA_BY_ZIP WHERE ZIP = " + to_string(zip) + " ;";
	int rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, nullptr);//executes query above, places stmt reference

	sqlite3_step(stmt);//specifically iterates through rows of selection that is in statement
	a = sqlite3_column_int(stmt, 0);//creates data in interger equal to indicated column of stmt
	b = sqlite3_column_text(stmt, 1);//" "
	cout << endl << a << " Covid deaths cumulatively in the " << b << " area.\n ";
	sqlite3_finalize(stmt); //frees memory 
	return a;
}//modify to return death value
int Data::getcases(const char* dir, int zip) {
	sqlite3* db;
	sqlite3_stmt* stmt;
	int a;
	const unsigned char* b;

	sqlite3_open(dir, &db);
	string sql = " SELECT casecount, name  FROM DATA_BY_ZIP WHERE ZIP = " + to_string(zip) + " ;";
	int rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, nullptr);//executes query above, places stmt reference
	sqlite3_step(stmt);//specifically iterates through rows of selection that is in statement
	a = sqlite3_column_int(stmt, 0);//creates data in interger equal to indicated column of stmt
	b = sqlite3_column_text(stmt, 1);//" "
	cout << endl << a << " cases cumulatively in the " << b << " area.\n ";
	sqlite3_finalize(stmt); //frees memory 
	return a;
}//MODIFY TO RETURN CASE VALUE
double Data::getdeathrate(const char* dir, int zip) {
	sqlite3* db;
	sqlite3_stmt* stmt;
	double a;
	const unsigned char* b;

	sqlite3_open(dir, &db);
	string sql = " SELECT death_rate, name  FROM DATA_BY_ZIP WHERE ZIP = " + to_string(zip) + " ;";
	int rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, nullptr);//executes query above, places stmt reference
	sqlite3_step(stmt);//specifically iterates through rows of selection that is in statement
	a = sqlite3_column_double(stmt, 0);//creates data in interger equal to indicated column of stmt
	b = sqlite3_column_text(stmt, 1);//" "
	cout << endl << "The death rate in the  " << b << " area ,per 100,000 people, is currently " << a << ".\n";
	sqlite3_finalize(stmt); //frees memory 
	return a;
}
double Data::getcaserate(const char* dir, int zip) {
	sqlite3* db;
	sqlite3_stmt* stmt;
	double a;
	const unsigned char* b;

	sqlite3_open(dir, &db);
	string sql = " SELECT caserate, name  FROM DATA_BY_ZIP WHERE ZIP = " + to_string(zip) + " ;";
	int rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, nullptr);//executes query above, places stmt reference
	sqlite3_step(stmt);//specifically iterates through rows of selection that is in statement
	a = sqlite3_column_double(stmt, 0);//creates data in interger equal to indicated column of stmt
	b = sqlite3_column_text(stmt, 1);//" "
	cout << endl << "The case rate in the  " << b << " area ,per 100,000 people, is currently " << a << ".\n";
	sqlite3_finalize(stmt); //frees memory 
	return a;
}
double Data::getpercentpos(const char* dir, int zip) {
	sqlite3* db;
	sqlite3_stmt* stmt;
	double a;
	const unsigned char* b;

	sqlite3_open(dir, &db);
	string sql = " SELECT percent_pos, name  FROM DATA_BY_ZIP WHERE ZIP = " + to_string(zip) + " ;";
	int rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, nullptr);//executes query above, places stmt reference
	sqlite3_step(stmt);//specifically iterates through rows of selection that is in statement
	a = sqlite3_column_double(stmt, 0);//creates data in interger equal to indicated column of stmt
	b = sqlite3_column_text(stmt, 1);//" "
	cout << endl << "The positive test rate in the " << b << " area is currently " << a << "%.\n";
	sqlite3_finalize(stmt); //frees memory 
	return a;
}
int Data::gettotaltest(const char* dir, int zip) {
	sqlite3* db;
	sqlite3_stmt* stmt;
	int a;
	const unsigned char* b;

	sqlite3_open(dir, &db);
	string sql = " SELECT total_tests, name  FROM DATA_BY_ZIP WHERE ZIP = " + to_string(zip) + " ;";
	int rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, nullptr);//executes query above, places stmt reference
	sqlite3_step(stmt);//specifically iterates through rows of selection that is in statement
	a = sqlite3_column_int(stmt, 0);//creates data in interger equal to indicated column of stmt
	b = sqlite3_column_text(stmt, 1);//" "
	cout << endl << "The total given tests in the " << b << " area  is currently " << a << ".\n";
	sqlite3_finalize(stmt); //frees memory 
	return a;
}
/*string Data::getareaname(const char* dir, int zip) {
	sqlite3* db;
	sqlite3_stmt* stmt;
	int a;
	const unsigned char* b;
	string name;
	string area;
	sqlite3_open(dir, &db);
	string sql = " SELECT total_tests, name  FROM DATA_BY_ZIP WHERE ZIP = " + to_string(zip) + " ;";
	int rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, nullptr);//executes query above, places stmt reference
	sqlite3_step(stmt);//specifically iterates through rows of selection that is in statement
	a = sqlite3_column_int(stmt, 0);//creates data in interger equal to indicated column of stmt



	name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));//important line of code that intital input of a const unsigned char pointer to a string.
	cout << endl << "\nThe total given tests in the " << name << " area  is currently " << a << ".\n";
	sqlite3_finalize(stmt); //frees memory 

	return name;
}*/