#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class stack { 
   private:
        int size;
        const int MAX_SIZE = 20;
        T data[20];
    public:
        stack();
        void push(T val);
        void pop();
        void pop_two();
        T top();
        bool empty();
};

template <typename T>
stack<T>::stack() {
    size = 0;
}

template <typename T>
void stack<T>::push(T val) {
    if(size>=MAX_SIZE) {
        throw out_of_range("Called push on full stack.");
    }
    data[size]=val;
    size++;
}

template <typename T>
void stack<T>::pop() {
    if (empty() == true) {
        throw out_of_range("Called pop on empty stack.");
    }
    size--;
}

template <typename T>
void stack<T>::pop_two() {
    if (empty() == true) {
        throw out_of_range("Called pop_two on empty stack.");
    }
    if (size == 1) {
        throw out_of_range("Called pop_two on a stack of size 1.");
    }
    size = size - 2;
}

template <typename T>
T stack<T>::top() {
    if(empty()) {
        throw underflow_error("Called top on empty stack.");
    }
    return data[size-1];
}

template <typename T>
bool stack<T>::empty() {
    if (size == 0) {
        return true;
    }
    return false;
}