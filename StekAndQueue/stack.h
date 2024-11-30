#pragma once
#include <iostream>
using namespace std;

struct Stack {
    int data;
    Stack* next;
};

inline Stack* createStack() {
    return nullptr;
}

inline bool isEmpty(Stack* stack) {
    return stack == nullptr;
}

inline void push(Stack** top, int data) {
    Stack* newNode = new Stack();
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

inline int pop(Stack** top) {
    if (isEmpty(*top))
        return INT_MIN;
    Stack* toDelete = *top;
    int x = toDelete->data;
    *top = (*top)->next;
    delete toDelete;
    return x;
}

inline int top(Stack* top) {
    return top->data;
}

inline void deleteStack(Stack** top) {
    Stack* tmp = *top;
    while (tmp) {
        Stack* toDelete = tmp;
        tmp = tmp->next;
        delete toDelete;
    }
    *top = nullptr;
}

inline void displayStack(Stack* top) {
    Stack* curr = top;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
