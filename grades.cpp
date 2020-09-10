// Name: Xueyu Wang
// USC NetID: 2670589054
// CSCI 455 PA5
// Fall 2019

/*
* grades.cpp
* A program to test the Table class.
* How to run it:
*      grades [hashSize]
*
* the optional argument hashSize is the size of hash table to use.
* if it's not given, the program uses default size (Table::HASH_SIZE)
*
*/

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
void printCmdSummary() {
	cout << "Valid commands are c(change the score for name), i(insert), l(print out the score for name),"
		<< endl;
	cout << "         r(remove), s(print out the number of entries), sta(print out statistics) ,"
		<< endl;
	cout << "         p(print out all names and scores), h(help), q(quit)."
		<< endl;

}

int main(int argc, char * argv[]) {

	// gets the hash table size from the command line

	int hashSize = Table::HASH_SIZE;

	Table * grades;  // Table is dynamically allocated below, so we can call
					 // different constructors depending on input from the user.

	if (argc > 1) {
		hashSize = atoi(argv[1]);  // atoi converts c-string to int

		if (hashSize < 1) {
			cout << "Command line argument (hashSize) must be a positive number"
				<< endl;
			return 1;
		}

		grades = new Table(hashSize);

	}
	else {   // no command line args given -- use default table size
		grades = new Table();
	}


	grades->hashStats(cout);

	// add more code here
	// Reminder: use -> when calling Table methods, since grades is type Table*
	char com;
	bool keepgoing = true;
	do {
		cout << "cmd>";
		cin >> com;

		if (cin.fail()) {
			cout << "ERROR: invalid command" << endl;
			printCmdSummary();
			keepgoing = false;
		}
		else {
			switch (com) {
			case 'i':
			{
				string name;
				int score;
				cout << "Name to insert: ";
				cin >> name;
				cout << "Score to insert: ";
				cin >> score;
				bool b = grades->insert(name, score);
				if (b == false) {
					cout << "The name was already present." << endl;
				}
				break;
			}
			case 'c':
			{
				string name;
				int score;
				cout << "Name to refer: ";
				cin >> name;
				cout << "New score to change: ";
				cin >> score;
				bool b = grades->change(name, score);
				if (b == false) {
					cout << "The student is not in the table." << endl;
				}
				break;
			}
			case 'r':
			{
				string name;
				cout << "Name to refer: ";
				cin >> name;
				bool b = grades->remove(name);
				if (b == false) {
					cout << "The student was not in the grade table." << endl;
				}
				break;
			}
			case 'l':
			{
				string name;
				cout << "Name to refer: ";
				cin >> name;
				int *output = grades->lookup(name);
				if (output == NULL) {
					cout << "The student is not in the table." << endl;
				}
				else {
					cout << "Score for name: " << *output << endl;
				}
				break;
			}
			case 'p':
				cout << "All names and scores in the table: " << endl;
				grades->printAll();
				break;
			case 's':
				cout << "The number of entries in the table: " << grades->numEntries() << endl;
				break;
			case 'a':
				grades->hashStats(cout);
				break;
			case 'h':
				printCmdSummary();
				break;
			case 'q':
				keepgoing = false;
				break;
			default:
                cout << "ERROR: invalid command" << endl;
			    printCmdSummary();
				break;
			}
		}
	} while (keepgoing);

	return 0;
}
