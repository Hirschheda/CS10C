#include "Heap.h"

#include <iostream>

using namespace std;

Heap::Heap() {
    numItems = 0;
}

/*void Heap::enqueue(PrintJob* insert) {
    if (numItems < MAX_HEAP_SIZE) {
        int i = numItems;
        PrintJob* curr = arr[numItems];
        bool done = false;
        if (numItems == 0) {
            arr[0] = insert;
            numItems++;
        }
        else {
            PrintJob* next = arr[numItems-1];
            while (done == false) {
                if ((curr == arr[0]) || insert->getPriority() < next->getPriority()) {
                    arr[i] = arr[i-1];
                    curr = arr[i-1];
                    i--;
                    if (next != arr[0]) {
                        next = arr[i-1];
                        
                    }
                    else {
                        done = true;
                    }
                }
                else {
                    done = true;
                }
            }
            arr[i] = insert;
            numItems++;
            done = true;
        }
    }
    else {
        cout << "Heap is full, enqueue failed." << endl;
    }
}*/

/*void Heap::enqueue(PrintJob* insert) {
    if (numItems+1 > MAX_HEAP_SIZE) 
        return;
    if (numItems == 0) 
    {
        arr[0] = insert;
        numItems++;
        return;
    }
    
    if(arr[numItems-1]->getPriority()<=insert->getPriority())
    {
        arr[numItems]=insert;
        numItems++;
        return;
    }
    int count=0;
    if(insert->getPriority()<arr[0]->getPriority())
    {
        count=numItems;
        while(count!=0)
            {
                arr[count]=arr[count-1];
                count--;
            }
            arr[0]=insert;
            numItems++;
            return;
    }
    while(count!=numItems)
    {
        if(insert->getPriority()<arr[count]->getPriority())
        {
            int x=numItems;
            while(count!=x)
            {
                arr[x]=arr[x-1];
                x--;
            }
            arr[count]=insert;
            numItems++;
            return;
        }
        count++;
    }
}*/
void Heap::enqueue( PrintJob* insert)
{
 if(numItems < MAX_HEAP_SIZE)
 {
 if(!numItems)
 {
 arr[numItems ] = insert;
 ++numItems;
 }
 else
 {
 int x = numItems;
while (x > 0 && (arr[(x-1)/2]->getPriority() < insert->getPriority()) )
{
arr[x] = arr[(x-1)/2];
x = (x-1)/2;
}
arr[x] = insert;
++numItems;
 }
 }
}

void Heap::dequeue ( )
{
 if(!numItems)
 {
 return;
 }

 if(numItems > 2 && arr[1]->getPriority() < arr[numItems - 1]->getPriority() && arr[2]->getPriority() <
arr[numItems - 1]->getPriority())
 {//enters if order will be kept after !rst swap (no trickledown)
 //cout << "entered second if in dequeue" << endl;
arr[0] = arr[numItems-1];
 --numItems;

 }
 else
 {
 //cout << "entered else in dequeue" << endl;
 trickleDown(0);
 --numItems;
 }


}

/*void Heap::dequeue() {
    if(numItems==0)
        return;
    PrintJob* temp=arr[0];
    int count =0;
    while(count!=numItems-1)
    {
        arr[count]=arr[count+1];
        count++;
    }
    delete temp;
    numItems--;
}*/

PrintJob* Heap::highest() {
    if(numItems==0)
        return nullptr;
    return arr[0];
}

void Heap::print ( )
{
 cout << "Priority: " << arr[0]->getPriority()
 << ", Job Number: " << arr[0]->getJobNumber()
 << ", Number of Pages: " << arr[0]->getPages()
 << endl;
}

void Heap::trickleDown(int num)
{
if (((2 * num + 1) < numItems) && ((2 * num + 2) < numItems))
{// enters if both children exist (1)


if (arr[2 * num + 1]->getPriority() > arr[2 * num + 2]->getPriority())
{//enters if left child is greater than the right(2)
arr[num] = arr[2 * num + 1];
trickleDown(2 * num + 1);

}//(2)
else
{//enters if right child is greater than the left (3)
arr[num] = arr[2 * num + 2];
trickleDown(2 * num + 2);
}//(3)
}//(1)

else if (((2 * num + 1) < numItems)) {//enters if only left exists

arr[num] = arr[2 * num + 1];
}
return;
}