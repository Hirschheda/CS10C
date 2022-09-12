#ifndef __NODE_H__
#define __NODE_H__
#include <string>


using namespace std;
class Node{
    private:
        int count;
        string word;
        Node *left;
        Node *right;
    
    public:
    Node();
    Node(string, int);
    string getWord();
    int getCount();
    Node *getLeft();
    Node *getRight();
    void setWord(string newWord);
    void setCount(int newCount);
    void addCount(int add);
    void setLeft(Node* newLeft);
    void setRight(Node* newRight);
};

#endif