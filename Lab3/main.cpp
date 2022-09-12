#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    int minIndex = index;

    for (unsigned int i = index; i < vals.size(); i++) {
        if (vals.at(i) < vals.at(minIndex)) {
            minIndex = i;
        }
    }
    return minIndex;
}

template<typename T>
void selection_sort(vector<T> &vals) {

    unsigned int i = 0;
    unsigned int smallIndex;
    T smallVal;
    T indexVal;

    while (i < vals.size()) {
        //getting the numbers of the smallest in the index to end and the index location
        smallIndex = min_index(vals, i);
        smallVal = vals.at(smallIndex);
        indexVal = vals.at(i);
        //swapping the index location and smallest in index to end locations if the smallest is not in the index location
        if (smallIndex != i) {
            vals.at(i) = smallVal;
            vals.at(smallIndex) = indexVal;
        }
        i++;
    }
    
}

template<typename T>
T getElement(vector<T> vals, int index) {
    return vals.at(index);
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    
    return vals;
}

int main(){
    //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int unsigned index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         
         try {
            cout << "Enter a number: " << endl;
            cin >> index;
            if(index>vals.size())
                throw out_of_range("out of range exception occured");
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
         catch (out_of_range& excpt){
            cout<<excpt.what()<<endl;
        }         
    }
    return 0;
}    
