// Name: Xueyu Wang
// USC NetID: 2670589054
// CS 455 PA5
// Fall 2019

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>
#include "listFuncs.h"
using namespace std;




int main() {
	ListType list = NULL;
	listInsert(list, "wang", 100);
	listInsert(list, "li", 90);
	listInsert(list, "yang", 80);
	listPrintAll(list);
	cout << listLookup(list, "wang") << endl;
	listChange(list, "wang", 120);
	listPrintAll(list);
    cout << listLookup(list, "wang") << endl;
	listRemove(list, "yang");
	cout << listSize(list) << endl;
	listPrintAll(list);


	return 0;
}
