#include "WordLadder.h"
#include <iostream>
#include <list>
#include <fstream>
#include <ostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <deque>

WordLadder::WordLadder(const string &input){
    ifstream in;
    
    in.open(input.c_str());
    if(!in.is_open()) {
        cout << "Error opening input file." << endl;
    }

    else {
        string dictWord;
        while(!in.eof()) {
            in >> dictWord;
            if(dictWord.length() != 5) {
                cout << "Error: Word must have 5 characters." << endl;
                return;
            }
            dict.push_back(dictWord);
        }
        in.close();
    }
}

void WordLadder::outputLadder(const string &s, const string &final, const string &outputFile) {
    ofstream out;
    out.open(outputFile.c_str());
    if (!out.is_open()) {
        cout << "Opening output file failed." << endl;
    }

    queue<stack<string> > initialQueue;
    stack<string> initialStack;
    string word;
    list<string>::iterator diction;
    bool start = false; 
    bool end = false;

    for (diction=dict.begin(); diction!=dict.end(); ++diction) {
        if (*diction == s) {
            start = true;
        }
        if (*diction == final) {
            end = true;
        }
    }
    if (!start || !end) {
        cout << "Not found in the dictionary." << endl;
        return;
    }
    if (s == final) {
        out<< s;
        out.close();
        return;    
    }

    initialStack.push(s);
    initialQueue.push(initialStack);

    dict.remove(s);
    while(!initialQueue.empty()) {
      
        word = initialQueue.front().top();
        for (diction=dict.begin();diction!=dict.end();++diction) {
           
            if (check(word,*diction)) {
                stack<string> copyStack = initialQueue.front();
                copyStack.push(*diction);
                
                if(*diction == final){
                    outputToFile(copyStack, out);
                    return;
                }
                initialQueue.push(copyStack);
                diction = dict.erase(diction);
             
                diction--;
            }
        }
        initialQueue.pop();
    }

    if (out.is_open()) {
        out << "No Word Ladder Found.";
    }
}


bool WordLadder::check(string word, string dictionaryWord) {
    int ch = 0;
    for (unsigned x=0; x<5; x++) {
        if (word[x] == dictionaryWord[x]) { 
            ch++; 
            }
        }
    if (ch == 4) {
        return true;
    } else {
        return false;
    }
}

void WordLadder::outputToFile(stack<string> stack, ofstream &out) {

    int i = 0;
    vector<string> ladder;
    
    while (!stack.empty()) {
        ladder.push_back(stack.top());
        stack.pop();
        i++;
    }
    if (out.is_open()) {
        while (i!=0) {
            i--;
            out << ladder.at(i);
     
            if (i != 0) {
                out << " ";
                
            }
        }
    }
}

int WordLadder::compare(string first, string second) {
    int i = 0;
    int numLettOff = 0;
    for (i = 0; i < 5; i++) {
        if (first.at(i) != second.at(i)) {
            numLettOff++;
        }
    }
    return numLettOff;
}