// Name: Xueyu Wang
// USC NetID: 2670589054
// CSCI 455 PA5
// Fall 2019


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
	key = theKey;
	value = theValue;
	next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
	key = theKey;
	value = theValue;
	next = n;
}

//*************************************************************************
// put the function definitions for your list functions below
bool listInsert(ListType & list, const std::string & key, int val)
{
	Node *p = list;

	if (p == NULL) {
		list = new Node(key, val);
		return true;
	}
	if (listLookup(list, key)!=NULL) {
		return false;
	}
	list = new Node(key, val, list);
	return true;
}

bool listRemove(ListType & list, const std::string & target)
{
	Node *p = list;
	Node *former = NULL;
    
	while (p != NULL) {
		if (p->key == target) {
           if(former != NULL){
			  former->next = p->next;
              return true;
           }
           else{
              list = list->next;
              return true;
           }
		}
        else{
           former = p;
		   p = p->next;
        }
	}
	return false;
}
int *listLookup(ListType & list, const std::string & target)
{
	if (list == NULL) {
		return NULL;
	}
	Node *p = list;
	while (p != NULL) {
		if (p->key == target) {
			return &p->value;
		}
		p = p->next;
	}
	return NULL;
}
bool listChange(ListType &list, const std::string & target, int val)
{
	if (listLookup(list, target) == NULL) {
		return false;
	}
	Node *p = list;
	while (p != NULL) {
		if (p->key == target) {
			p->value = val;
			return true;
		}
		p = p->next;
	}
	return false;
}

void listPrintAll(ListType & list)
{
	Node *p = list;
	while (p != NULL) {
		cout << p->key << " " << p->value << endl;
		p = p->next;
	}
}

int listSize(ListType & list)
{
   if (list == NULL) {
		return 0;
	}
	int num = 0;
	Node *p = list;
	while (p != NULL) {
		num++;
		p = p->next;
	}
	return num;
}

