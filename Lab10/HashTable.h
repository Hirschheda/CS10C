#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include "WordEntry.h"

using namespace std;

class HashTable {

 private:
	list<WordEntry> *hashTable;
	int size;

 public:
	HashTable(int);
	void insertEncoder(WordEntry);		//add a word to Encoder Table
	void insertDecoder(WordEntry);		//add a word to Decoder Table
	int computeHash(string);	//compute hash value from the string
	const int & getSize();
	int getCode(string);
	string getToken(int);
};

#endif