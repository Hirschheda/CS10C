#include "WordEntry.h"


WordEntry::WordEntry(const string &text)
 : token(text), numAppearances(1), code(-1){ 
}


void WordEntry::addNewAppearance() {
	++numAppearances;
}


const string & WordEntry::getToken() {
    return token;
}

const int & WordEntry::getNumAppearances() {
	return numAppearances;
}

const int & WordEntry::getCode() {
	return code;
}

void WordEntry::setToken(string word) {
	token = word;
}

void WordEntry::setNumAppearances(int number) {
	numAppearances = number;
}

void WordEntry::setCode(int number) {
	code = number;
}