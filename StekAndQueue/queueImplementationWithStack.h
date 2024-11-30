#pragma once
#include "queue.h"
#include "stack.h"

struct stackQueue {
    Stack* s1;
    Stack* s2;
};

inline stackQueue* createStackQueue() {
    stackQueue* queue = new stackQueue();
    queue->s1 = createStack();
    queue->s2 = createStack();
}

inline bool isEmpty(stackQueue* queue) {
    return isEmpty(queue->s2);
}

inline void push(stackQueue** queue, int data) {
    if(isEmpty(*queue))
        push(&(*queue)->s2, data);
    else {
        while(!isEmpty((*queue)->s2))
            push(&(*queue)->s1, pop(&(*queue)->s2));
        push(&(*queue)->s1, data);
        while(!isEmpty((*queue)->s1))
            push(&(*queue)->s2, pop(&(*queue)->s1));
    }
}

inline int pop(stackQueue** queue) {
    if(isEmpty(*queue))
        return INT_MIN;
    return pop(&(*queue)->s2);
}

inline int top(stackQueue* queue) {
    return top(queue->s2);
}

inline void display(stackQueue* queue) {
    Stack* tmp = queue->s2;
    displayStack(tmp);
}
