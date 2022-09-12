#include <vector>
#include <fstream>
#include "HashTable.h"

using namespace std;

bool contains(vector<WordEntry> vect, const string &s) {
    for (unsigned int i = 0; i < vect.size(); i++) {
        if (vect.at(i).getToken() == s) {
            return true;
        }
    }
    return false;
}

void sortVector(vector<WordEntry> &vect) {
    for (unsigned int i = 1; i < vect.size(); ++i) {
        unsigned int j = i;
        while (j > 0 && vect.at(j).getNumAppearances() > vect.at(j - 1).getNumAppearances()) {
            WordEntry temp = vect.at(j);
            vect.at(j) = vect.at(j - 1);
            vect.at(j - 1) = temp;
            --j;
        }
    }
}

int main () {
    ifstream input;
    string inputFile;

    cout << "Enter input file name:" << endl;
    cin >> inputFile;

    input.open(inputFile);
    if (!input.is_open()) {
        cout << "1) Error opening input file." << endl;
        return -1;
    }

    //collect data inserting into vector
    vector<WordEntry> words;
    string word;
    int i = 0;
    int j = 0;
    
    while (input >> word) {
        char lastLetter = word.at(word.size()-1);
        string back;
        back.push_back(lastLetter);
        if (back=="." || back=="," || back=="!" || back=="?" || back=="'") {
            word.pop_back();
            if (contains(words, back) == true) {
                j = 0;
                while (words.at(j).getToken() != back) {
                    j++;
                }
                words.at(j).addNewAppearance();
            }
            else {
                WordEntry newWord = WordEntry(back);
                words.push_back(newWord);
                i++;
            }
        }
        if (contains(words, word) == true) {
            j = 0;
            while (words.at(j).getToken() != word) {
                j++;
            }
            words.at(j).addNewAppearance();
        }
        else {
            WordEntry newWord = WordEntry(word);
            words.push_back(newWord);
            i++;
        }
    }
    input.close();

    //sort data by frequency in vector
    sortVector(words);
    
    //assign codes to each element in the vectore in order. Code is built into workdEntry
    for (unsigned int i = 0; i < words.size(); i++) {
        words.at(i).setCode(i);
    }

    //fill encoder and decoder with the data
    HashTable encoder = HashTable(words.size());	//token -> code
    HashTable decoder = HashTable(words.size());	//code -> token

    for (unsigned int i = 0; i < words.size(); i++) {
        encoder.insertEncoder(words.at(i));
    }
    for (unsigned int i = 0; i < words.size(); i++) {
        decoder.insertDecoder(words.at(i));
    }
    
    //output data in code
    input.open(inputFile);
    if (!input.is_open()) {
        cout << "2) Error opening input file." << endl;
        return -1;
    }

    // cout << "Encoder table: " << endl;
    // for (unsigned int i = 0; i < words.size(); i++) {
    //     cout << "Code: " << i;
    //     cout << "      Token: " << encoder.getToken(i) << endl;
    // }
    cout << endl << "Decoder table: " << endl;
    for (unsigned int i = 0; i < words.size(); i++) {
        cout << "Code: " << i;
        cout << "      Token: " << decoder.getToken(i) << endl;
    }
    cout << endl;
   
    while (input >> word) {
        char lastLetter = word.at(word.size()-1);
        string back;
        back.push_back(lastLetter);
        if (back=="." || back=="," || back=="!" || back=="?" || back=="'") {
            word.pop_back();
            cout << encoder.getCode(word) << " " << encoder.getCode(back) << " ";
        }
        else {
            cout << encoder.getCode(word) << " ";
        }
    }
}