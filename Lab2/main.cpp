#include <iostream>
#include "IntList.h"

using namespace std;

int main()
{
    IntList i;
    i.push_back(2);
    i.push_back(2);
    i.push_front(3);
    i.push_back(7);
    i.push_front(7);
    i.printReverse();
    cout<<i<<endl;
    i.pop_front();
    i.pop_back();
    cout<<i;
    return 0;
}
