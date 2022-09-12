#include <iostream>
#include <stack>
#include <sstream>
#include <fstream>
#include "arithmeticExpression.h"

using namespace std;

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void arithmeticExpression::visualizeTree(ofstream &outputFilename, TreeNode *root) {
    if (root->left != nullptr) {
        outputFilename << "key" << root->key << " -> " << "key" << root->left->key << ";"<< endl;
        visualizeTree(outputFilename, root->left);
    }
    if (root->right != nullptr) {
        outputFilename << "key" << root->key << " -> " << "key" << root->right->key << ";" << endl;
        visualizeTree(outputFilename, root->right);
    }
    return;
}

arithmeticExpression::arithmeticExpression(const string &infix)
{
    infixExpression=infix;
    root=new TreeNode(0,0);
}

void arithmeticExpression::buildTree()
{
    string post=infix_to_postfix();
    string post1 = post;
    root->key = post.back();
    post.pop_back();
    buildTree(root, post);
}
void arithmeticExpression::buildTree(TreeNode *root, string &post) {
    if (post.empty() == false) {

        TreeNode *newNode = new TreeNode(0, post.back());
        post.pop_back();
        root->right = newNode;
        if (newNode->key == '+' || newNode->key == '-' || newNode->key == '*' || newNode->key == '/') {
            buildTree(newNode, post);
        }

        TreeNode *newNode1 = new TreeNode(0, post.back());
        post.pop_back();
        root->left = newNode1;
        if (newNode1->key == '+' || newNode1->key == '-' || newNode1->key == '*' || newNode1->key == '/') {
            buildTree(newNode1, post);
        }
    }
}

void arithmeticExpression::infix(TreeNode *root)
{
    if (root != NULL) {
        if (root->left != nullptr)
            cout << '(';
      infix(root->left);
      cout<<root->key;
      infix(root->right);
      if (root->left != 0)
            cout << ')';
   }
}

void arithmeticExpression::infix()
{
    infix(root);
}

void arithmeticExpression::prefix(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->key;
    prefix(root->left);
    prefix(root->right);
}

void arithmeticExpression::prefix()
{
    prefix(root);
}

void arithmeticExpression::postfix(TreeNode *root)
{
    if (root == NULL)
        return;
    postfix(root->left);
    postfix(root->right);
    cout << root->key;
}

void arithmeticExpression::postfix()
{
    postfix(root);
}