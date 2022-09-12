#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WordEntry {
 private:
	string token;
	int numAppearances;
	int code; 		//but should be string?
 public:
	WordEntry(const string &);
	
	void addNewAppearance();
	const string & getToken();
	const int & getNumAppearances();
	const int & getCode();
	void setToken(string);
	void setNumAppearances(int);
	void setCode(int);
};
#endif