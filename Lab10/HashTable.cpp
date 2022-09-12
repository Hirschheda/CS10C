#include "HashTable.h"
#include "WordEntry.h"


HashTable::HashTable (int s) {
	size = s;
    hashTable = new list<WordEntry> [s];
}


const int & HashTable::getSize() {
    return size;
}


void HashTable::insertEncoder(WordEntry entry) {
    int hash = computeHash(entry.getToken());
    while (hashTable[hash].empty() == false) {

        if (hash >= size) {
            hash = 0;
        }
        else {
            hash++;
        }
    }
    hashTable[hash].push_front(entry);
}

void HashTable::insertDecoder(WordEntry entry) {
    int hash = entry.getCode();
    if (hashTable[hash].empty() == true) {
        hashTable[hash].push_front(entry);
    }
    else {
        cout << "Collision occured entering a Decoder element." << endl;
    }
}

int HashTable::computeHash(string s) {
    int total = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        total = total + s.at(i);
    }
    total = total % size;
    return total;
}

int HashTable::getCode(string word) {
    int hash = computeHash(word);
    while (hashTable[hash].front().getToken() != word) {
        if (hash == size-1) {
            hash = 0;
        }
        else {
            hash++;
        }
    }
    return hashTable[hash].front().getCode();
}

string HashTable::getToken(int i) {
    if (hashTable[i].empty() == false) {
        string token = hashTable[i].front().getToken();
        return token;
    }
    return "EMPTY";
}