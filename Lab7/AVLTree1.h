#ifndef __AVLTREE_H__
#define __AVLTREE_H__
#include "Node.h"

using namespace std;

class AVLTree {
     private:
        Node findUnbalancedNode(Node *);
        // Node rotate();
        Node rotateLeft(Node* root);
        Node rotateRight(Node* root);
        void printBalanceFactors(Node *root);
        // void visualizeTree(ofstream &, Node *);
        
        Node *root;
    public:
        int balanceFactor(Node*);
        void printBalanceFactors();
        // void visualizeTree(const string &);
        void insert(const string &str);
        AVLTree();
        ~AVLTree();
        void erase(Node *);
        void rotate(Node *currNode);
        void insert(Node *currNode, Node *newNode);  //Needs to be Updated
        bool search(const string &key) const;
        bool search(const string &, Node *) const;
        int height(Node *currNode) const;
        void height(int heightCounter, int &finalHeight, Node *currNode) const;
        bool isEmpty() const;
};

#endif