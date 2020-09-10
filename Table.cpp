// Name: Xueyu Wang
// USC NetID: 2670589054
// CSCI 455 PA5
// Fall 2019

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
	table = new ListType[HASH_SIZE]();
	hashSize = HASH_SIZE;
}


Table::Table(unsigned int hSize) {
	table = new ListType[hSize]();
	hashSize = hSize;
}


int * Table::lookup(const string &key) {
	int index = hashCode(key);
	int *val = listLookup(table[index], key);
	return val;
}

bool Table::remove(const string &key) {
	int index = hashCode(key);
	bool b = listRemove(table[index], key);
	return b; 
}

bool Table::insert(const string &key, int value) {
	int index = hashCode(key);
	bool b = listInsert(table[index], key, value);
	return b; 
}

int Table::numEntries() const {
	int num = 0;
	for (int i = 0; i < hashSize; i++) {
		if (table[i] != NULL) {
			num += listSize(table[i]);
		}
	}
	return num;
}


void Table::printAll() const {
	for (int i = 0; i < hashSize; i++) {
		if (table[i] != NULL) {
			listPrintAll(table[i]);
		}
	}
}

bool Table::change(const std::string & key, int val)
{
	int index = hashCode(key);
	bool b = listChange(table[index], key, val);
	return b;
}

void Table::hashStats(ostream &out) const {
	out << "number of buckets: " << hashSize << endl;
	out << "number of entries: " << numEntries() << endl;
	out << "number of non-empty buckets: " << numNonEntries() << endl;
	out << "longest chain: " << longestChain() << endl;
}

// add definitions for your private methods here

int Table::numNonEntries() const
{
	int num = 0;
	for (int i = 0; i < hashSize; i++) {
		if (table[i] != NULL) {
			num++;
		}
	}
	return num;
}

int Table::longestChain() const
{
	int max = 0;
	for (int i = 0; i < hashSize; i++) {
		if (table[i] != NULL && max < listSize(table[i])) {
			max = listSize(table[i]);
		}
	}
	return max;
}
