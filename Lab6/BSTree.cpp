#include <iostream>
#include "BSTree.h"
#include <string>

using namespace std;


BSTree::BSTree(){
    root=nullptr;
}

BSTree::~BSTree(){
    if (n != nullptr)
	{
		DestroyRecursive(n->getLeft());
		DestroyRecursive(n->getRight());
		delete n;
	}
}

void BSTree::insert(Node *root, const string &data) {
if (root == nullptr) {
Node *temp = new Node(data, 1);
this->root = temp;
}
else {
if (root->getWord() == data) {
root->addCount(1);
}
else if (root->getWord() < data) {
if (root->getRight() == NULL) {
//Node *newnode = new Node(data, 1);
}
else {
insert(root->getRight(), data);
}
}
else {
if (root->getLeft() == nullptr) {
Node *temp = new Node(data, 1);
root->setLeft(temp);
}
else {
insert(root->getLeft(), data);
}
}
}
}

void BSTree::insert(const string &newString){
   insert(root,newString);
}

Node* BSTree::remove(Node *target, const string &key){


if (target == nullptr){

return target;
}

if (key < target->getWord()){

target->setLeft(remove(target->getLeft(), key));
}

else if (key > target->getWord()){
    
    target->setRight(remove(target->getRight(), key));

}
else{
    if (target->getCount() > 1){
            target->addCount(-1);
            return target;
    }

    if (target->getLeft()){

        Node *rep = target->getLeft();
        Node *parent = target;

        while (rep->getRight() != nullptr){
            parent = rep;
            rep = rep->getRight();
        }

        target->setWord(rep->getWord());
        target->setCount(rep->getCount());
        parent->setRight(rep->getLeft());
        free(rep);
        return target;
    }
    else if (target->getRight()){

        Node *rep = target->getRight();
        Node *parent = target;
        
        while (rep->getLeft() != nullptr)
        {
            parent = rep;
            rep = rep->getLeft();
        }
        
        target->setWord(rep->getWord());
        target->setCount(rep->getCount());
        parent->setLeft(rep->getRight());
        free(rep);
        return target;
    }
    // leaf node.
    else
    {
    free(target);
    return nullptr;
    }
}
return target;
}


void BSTree::remove(const string &key)
{
Node *target = search(this->root, key);

if (target == nullptr)
{
    cout << "Value not found" << endl;
}

else
{
    this->root = remove(root, key);
}
}


bool BSTree::search(const string &key) const{

Node *result = search(root, key);

if (result) {
    return true;
}

else {
    return false;
}
}

Node *BSTree::search(Node *nodePtr, const string &key) const {

if (!nodePtr) {
    return nullptr;
}

else if (nodePtr->getWord()==key) {
    return nodePtr;
}

else if (nodePtr->getWord()>key) {
    return search(nodePtr->getLeft(),key);
}

else {
    return search(nodePtr->getRight(),key);
}

}

string BSTree::largest() const{
    Node *curr = root;
    while(curr!=nullptr){
        curr = curr->getRight();
    }
    return curr->getWord();
}

string BSTree::smallest() const{
    Node *curr = root;
    while(curr!=nullptr){
        curr = curr->getLeft();
    }
    return curr->getWord();
}

/*int BSTree::height(const string&) const{
    Node *curr = root;
    int counter = 0;
    while(curr!=nullptr){
        curr = curr->getRight();
        ++counter;
    }
    return counter;

}*/

void BSTree::preOrder() const{
    preOrder(root);
}

void BSTree::postOrder() const{
    //Node *temp = new Node();
    postOrder(root);
}
void BSTree::inOrder() const{
   inOrder(root);
}
void BSTree::postOrder(Node *root) const{

if (root != nullptr) {

    postOrder(root->getLeft());
    postOrder(root->getRight());
    cout << root->getWord() << "(" << root->getCount() << "), ";

    }

}

void BSTree::inOrder(Node *root) const{

if (root != nullptr) {

    inOrder(root->getLeft());
    cout << root->getWord() << "(" << root->getCount() << "), ";
    inOrder(root->getRight());

    }

}

void BSTree::preOrder(Node *root) const{

if (root != nullptr) {
    
    cout << root->getWord() << "(" << root->getCount() << "), ";
    preOrder(root->getLeft());
    preOrder(root->getRight());

    }

}