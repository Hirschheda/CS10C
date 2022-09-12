#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList()
{
    dummyHead=new IntNode(0);
    dummyTail=new IntNode(0);
    dummyTail->prev=dummyHead;
    dummyHead->next=dummyTail;
}

IntList::~IntList() 
{
    while(!empty())
        pop_front();
}

void IntList::push_front(int value) {
    IntNode *newNode = new IntNode(value);
    //update newNode so it is pointing to surrounding nodes in list
    newNode->prev = dummyHead;
    newNode->next = dummyHead->next;
    //set the previous and next nodes to be pointing to newNode, forwards and backwards
    //This updates the dummy nodes automatically
    dummyHead->next = newNode;
    IntNode *temp=newNode->next;
    temp->prev = newNode;
}

void IntList::pop_front() {
    if(empty())
        return;
    IntNode *curr = dummyHead->next;
    dummyHead->next = curr->next;
    delete curr;
    curr = dummyHead->next;
    curr->prev = dummyHead;
}

void IntList::push_back(int value) {
    IntNode *newNode = new IntNode(value);
    newNode->next = dummyTail;
    newNode->prev = dummyTail->prev;
    dummyTail->prev->next = newNode;
    dummyTail->prev = newNode;
}

void IntList::pop_back() 
{
    if(empty())
        return;
    IntNode *curr = dummyTail->prev;
    dummyTail->prev = curr->prev;
    delete curr;
    curr = dummyTail->prev;
    curr->next = dummyTail; 
}

bool IntList::empty() const 
{
    if(dummyHead->next==0||dummyHead->next==dummyTail)
        return true;
    return false;
}

ostream & operator<<(ostream &out, const IntList &rhs) 
{
    if(!rhs.empty())
    {
    IntNode *curr=(rhs.dummyHead)->next;
    while(curr!=(rhs.dummyTail)->prev)
    {
        out<<curr->data<<' ';
        curr=curr->next;
    }
    out<<((rhs.dummyTail)->prev)->data;
    }
    return out;
}

void IntList::printReverse() const 
{
    if(empty())
        return;
    IntNode *curr=dummyTail->prev;
    while(curr!=dummyHead->next)
    {
        cout<<curr->data<<' ';
        curr=curr->prev;
    }
    cout<<dummyHead->next->data;
}