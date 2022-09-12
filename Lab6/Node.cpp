#include <iostream>
#include "Node.h"
#include <string>

using namespace std;

Node::Node() {
left = nullptr;
right = nullptr;
count = 0;
word = "";
}
Node::Node(string x, int y) {
right = nullptr;
left = nullptr;
word = x;
count = y;
}

string Node::getWord(){
    return this->word;
}

int Node::getCount(){
    return this->count;
}

Node* Node::getRight(){
    return this->right;
}
Node* Node::getLeft(){
    return this->left;
}

void Node::setWord(string newWord){
    this->word = newWord;
}

void Node::addCount(int add){
    this->count+=add;
}
void Node::setCount(int newCount){
    this->count = newCount;
}

void Node::setRight(Node* newRight){
    this->right = newRight;
}

void Node::setLeft(Node* newLeft){
    this->left = newLeft;
}
