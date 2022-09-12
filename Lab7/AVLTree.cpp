#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree() {
    root = 0;
}

void AVLTree::insert(const string &str) {
    Node *newNode = new Node(str);
    insert(root,newNode);
}

void AVLTree::insert(Node *currNode, Node *newNode) {

    if (!root) {
        root = newNode;
        root->parent = 0;
        return;
    }
    currNode = root;
    //change 1
    while (currNode!=nullptr) {
        if (newNode->contents == currNode->contents) {
            currNode = 0;
        }
        else if (newNode->contents < currNode->contents) {
            if (currNode->left==0) {
                currNode->left=newNode;
                newNode->parent=currNode;
                currNode= 0;
            }
            else
                currNode=currNode->left;
        }
        else{
            if (currNode->right == 0) {
                currNode->right=newNode;
                newNode->parent=currNode;
                currNode=0;
            }
            else
                currNode=currNode->right;
        }
    }

    newNode = newNode->parent;
    while (newNode) {
        rotate(newNode);
        newNode = newNode->parent;

    }
}

void AVLTree::printBalanceFactors() const {
    printBalanceFactors(root);
    cout<<endl;
}

void AVLTree::printBalanceFactors(Node *currNode) const {
    if(currNode) {
        printBalanceFactors(currNode->left);
        cout<<currNode->contents<<"("<< balanceFactor(currNode)<< "), ";
        printBalanceFactors(currNode->right);
    }
}

int AVLTree::balanceFactor(Node *currNode) const {
    return height(currNode->left)-height(currNode->right);
}

int AVLTree::height(Node *currNode) const {
    if(currNode){
        int Height = 0;
        height(0,Height,currNode);
        return Height - 1;
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

void AVLTree::rotate(Node *currNode) {

    if(balanceFactor(currNode) == 2) {
        if(balanceFactor(currNode->left) == -1) {
            rotateLeft(currNode->left);
        }
        rotateRight(currNode);

    }
    else if(balanceFactor(currNode)==-2) {

        if(balanceFactor(currNode->right)==1) {
            rotateRight(currNode->right);
        }

        rotateLeft(currNode);
    }
}

void AVLTree::rotateRight(Node *currNode) {

    Node *temp = currNode->left->right;

    if(!currNode->parent) {
        root = currNode->left;
        root->parent = 0;


    }

    else if(currNode->parent){
        replaceChild(currNode->parent,currNode,currNode->left);
    }

    setChild(currNode->left,"right",currNode);
    setChild(currNode,"left",temp);
}

void AVLTree::rotateLeft(Node *currNode) {

    Node *temp = currNode->right->left;

    if(currNode->parent) {
        replaceChild(currNode->parent,currNode,currNode->right);
    }

    else {
        root = currNode->right;
        root->parent = 0;
    }

    setChild(currNode->right,"left",currNode);
    setChild(currNode,"right",temp);
}

void AVLTree::setChild(Node *parent, string childPick, Node *child) {

    if(childPick == "left") {
        parent->left = child;
    }

    else {
        parent->right = child;
    }

    if(child) {
        child->parent = parent;
    }
}

void AVLTree::replaceChild(Node *parent, Node *currNode,Node *newChild) {
    if(parent->left == currNode){
        setChild(parent,"left",newChild);
    }

    else if(parent->right == currNode){
        setChild(parent,"right",newChild);
    }
}

void AVLTree::visualizeTree(const string &outputFilename) {

    ofstream outFS(outputFilename.c_str());

    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }

    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string fileName = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string cmd = "dot -Tjpg " + outputFilename + " -o " + fileName;
    system(cmd.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *newNode){

    if(newNode){

        if(newNode->left){
            visualizeTree(outFS,newNode->left);
            outFS<<newNode->contents <<" -> " <<newNode->left->contents<<";"<<endl;
        }

        if(newNode->right){
            visualizeTree(outFS,newNode->right);
            outFS<<newNode->contents <<" -> " <<newNode->right->contents<<";"<<endl;
        }
    }
}