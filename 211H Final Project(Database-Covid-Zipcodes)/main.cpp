// 211H Final Project(Database-Covid-Zipcodes).cpp : This file contains the 'main' function. Program execution begins and ends there.
//Obinna Chukwu
//211H final Project
//Dr. Azhar

#include <iostream>
#include <stdio.h>
#include <string>
#include "sqllite/sqlite3.h"
#include "Data.h"
#include "user.h"
#include <sstream>

using namespace std;



int main()
{
	cout << "Hello World!\n";
	string name;
	sqlite3* DB;
	const char* dir = "CovidData.db";
	bool STATE = true;
	cout << "what is your name?\n";
	getline(cin, name);
	cout << "\nHello " << name << ", this is a program that gives you the Covid Information of your Zip Code. This is data as of 11/22/2020.";
	
	
	
	

	user me;
	
	while (STATE) {
		int zip = 0;
		string szip;
		char arr[5];

		char test;
		
		try {
			
			//create a string into a char array with a 5 limit to use isdigit, then convert the array to a string, then convert to an int
			cout << "\ngive me your zipcode";
			cin >> szip;
			if (szip.size() < 5) {
				throw runtime_error("\nInput is too short");
			}
			for (int i = 0; i < 5; i++) {
				arr[i] = szip[i];
			}
			if (isdigit(arr[0]) && isdigit(arr[1]) && isdigit(arr[2]) && isdigit(arr[3]) && isdigit(arr[4])) {
				szip = szip.substr(0, 5);
				stringstream convert(szip);
				convert >> zip;
			}
			else {
				throw runtime_error("\n You gave me characters");
			}

			
			
			me.setprofile(dir, zip, name);
		}
		catch (runtime_error& error) {
			cout << error.what();
		}
		
		cout << "\npress q to quit! anything else to repeat";
		cin >> test;
		if (test == 'q') {
			STATE = false;
			
		}

		cin.clear();
		cin.ignore(1000, '\n');

	}
	cout << "\nGood Bye!";


	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
