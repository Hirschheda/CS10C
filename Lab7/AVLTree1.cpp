#include <iostream>
#include "AVLTree.h"

using namespace std;

Node AVLTree::findUnbalancedNode(Node *root) {
    if (root == nullptr) {
        return *root;
    }
    
    int temp = balanceFactor(root);
    if (temp > 2 || temp < -2) {
        return *root;
    }

    Node *tempNode = root;

    *tempNode = findUnbalancedNode(root->left);
    if (tempNode != nullptr) {
        return *tempNode;
    }

    *tempNode = findUnbalancedNode(root->right);
    if (tempNode != nullptr) {
        return *tempNode;
    }

    return *root;
}

int AVLTree::balanceFactor(Node* root) {
    return height(root->left)-height(root->right);
}

void AVLTree::printBalanceFactors() {
    printBalanceFactors(root);
    cout << endl;
}

void AVLTree::printBalanceFactors(Node *root) {
    if (root == nullptr) {
        return;
    }
    printBalanceFactors(root->left);
    cout << root->contents << "(" << balanceFactor(root) << "), ";
    printBalanceFactors(root->right);
}

Node AVLTree::rotateLeft(Node *root) {
    Node *temp = root->right;

    temp->parent = root->parent;

    if (temp->left != nullptr) {
        root->right = temp->left;
        temp->left->parent = root;
        temp->left = nullptr;
    }
    else {
        root->right = nullptr;
    }
    
    if (root->parent != nullptr) {
        if (root->parent->left) {
            root->parent->left = temp;
        }
        else {
            root->parent->right = temp;
        }
    }
    root->parent = temp;
    temp->left = root;

    return *temp;
}

Node AVLTree::rotateRight(Node* root) {
    Node *temp = root->left;

    temp->parent = root->parent;

    if (temp->right != nullptr) {
        root->left = temp->right;
        temp->right->parent = root;
        temp->right = nullptr;
    }
    else {
        root->left = nullptr;
    }
    
    if (root->parent != nullptr) {
        if (root->parent->left) {
            root->parent->left = temp;
        }
        else {
            root->parent->right = temp;
        }
    }
    root->parent = temp;
    temp->right = root;

    return *temp;
}


AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    if (!isEmpty()){
        erase(root);
    }
}

void AVLTree::erase(Node *root) {
    if (root->getRight() != nullptr) {
        erase(root->getRight());
    }
    if (root->getLeft() != nullptr) {
        erase(root->getLeft());
    }
    delete root;
}

void AVLTree::insert(const string &newString) {   //Needs updating
    Node *newNode = new Node(newString);
    bool done = false;

    if (!root) {
                                            // cout << "1" << endl;
        root = newNode;
    }
    else {
                                            // cout << "2" << endl;
        Node *curr = root;
        Node *temp = root;
        while (done == false) {
                                            // cout << "3" << endl;
            if (curr->getContents() == newNode->getContents()) {
                                            // cout << "4" << endl;
                return;
            }
            else if (curr->getContents() > newNode->getContents()) {
                                            // cout << "5" << endl;
                temp = curr->getLeft();
                if (temp == nullptr) {
                    curr->setLeft(newNode);
                    newNode->setParent(curr);
                    done = true;
                }
                else {
                    curr = temp;
                }
            }
            else {
                                            // cout << "6" << endl;
                temp = curr->getRight();
                if (temp == nullptr) {
                    curr->setRight(newNode);
                    newNode->setParent(curr);
                    done = true;
                }
                else {
                    curr = temp;
                }
            }
        }
    }
}

void AVLTree::rotate(Node *root) {

    if(balanceFactor(root) == 2) {
        if(balanceFactor(root->left) == -1) {
            rotateLeft(root->left);
        }
        rotateRight(root);

    }
    else if(balanceFactor(root)==-2) {

        if(balanceFactor(root->right)==1) {
            rotateRight(root->right);
        }

        rotateLeft(root);
    }
}

bool AVLTree::search(const string &key) const {
    return search(key, root);
}

bool AVLTree::search(const string &key, Node *root) const {
    if (root == nullptr) {
        return false;
    }
    if (root->getContents() == key) {
        return true;
    }
    else {
        if (key > root->getContents()) {
            return search(key, root->getRight());
        }
        else {
            return search(key, root->getLeft());
        }
    }
    return false;
}

int AVLTree::height(Node *currNode) const {
    if(currNode){
        int fHeight = 0;
        height(0,fHeight,currNode);
        return fHeight - 1;
    }
    return -1;
}

void AVLTree::height(int heightCounter, int &finalHeight, Node *currNode) const {
    if(currNode) {
        heightCounter++;
        if(heightCounter>finalHeight){
            finalHeight=heightCounter;
        }
        height(heightCounter,finalHeight,currNode->left);
        height(heightCounter,finalHeight,currNode->right);
    }
}


bool AVLTree::isEmpty() const {
    if (root == nullptr) {
        return true;
    }
    return false;
}