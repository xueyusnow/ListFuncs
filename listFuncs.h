// Name: Xueyu Wang
// USC NetID: 2670589054
// CSCI 455 PA5
// Fall 2019


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to not put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
#include <string>

struct Node {
	std::string key;
	int value;

	Node *next;

	Node(const std::string &theKey, int theValue);

	Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

//Insert the name and score in the list.
//If the name was already present, return false.
bool listInsert(ListType &list, const std::string &key, int val);

//Remove the student.
//If this student wasn't in the list, return false.
bool listRemove(ListType &list, const std::string &target);

//Lookup the name, and return the address of his or her score.
//if the student is not in the list, return false.
int *listLookup(ListType &list, const std::string &target);

//Change the score for name. 
//returns false if this name isn't present.
bool listChange(ListType &list, const std::string &target, int val);

//Prints out all names and scores in the list.
void listPrintAll(ListType &list);

//returns the number of entries in the list.
int listSize(ListType &list);

// keep the following line at the end of the file
#endif
