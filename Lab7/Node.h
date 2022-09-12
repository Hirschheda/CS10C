/*#ifndef __NODE_H__
#define __NODE_H__
#include <string>
using namespace std;

class Node {
    friend class AVLTree;
    private:
        Node *left;
        Node *right;
        Node *parent;
        string contents;
    public:
        Node();
        Node(string);
        string getContents();
        void setLeft(Node *);
        Node *getLeft();
        void setRight(Node *);
        Node *getRight();
        void setParent(Node *);
        Node *getParent();
        int findLongestPath();
};

#endif*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;
class Node {
    friend class AVLTree;

private:
    string contents;
    Node *left;
    Node *right;
    Node *parent;
    Node(string contents);
};

#endif
