/*#include <iostream>
#include "Node.h"

using namespace std;
Node::Node() {
    left = nullptr;
    right = nullptr;
    contents = nullptr;
    parent = nullptr;
}

Node::Node(string content) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    contents = content;
}

string Node::getContents() {
    return this->contents;
}

void Node::setLeft(Node *node) {
    left = node;
}

Node *Node::getLeft() {
    return left;
}

void Node::setRight(Node *node) {
    right = node;
}

Node *Node::getRight() {
    return right;
}

void Node::setParent(Node * node) {
    parent = node;
}

Node *Node::getParent() {
    return parent;
}

int Node::findLongestPath() {
    if (getLeft() == nullptr && getRight() == nullptr) {
        return 0;
    }
    Node *temp;
    int a = 0;
    int b = 0;
    if (getLeft() != nullptr) {
        temp = getLeft();
        a = 1 + (temp->findLongestPath());
    }
    if (getRight() != nullptr) {
        temp = getRight();
        b = 1 + (temp->findLongestPath());
    }

    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}*/
#include "Node.h"

Node::Node(string contents){
    this-> contents = contents;
    left = 0;
    right = 0;
    parent = 0;
}

