#pragma once
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
};

inline Queue* createQueue() {
    Queue* queue = new Queue();
    queue->head = nullptr;
    queue->tail = nullptr;
    return queue;
}

inline bool isEmpty(Queue* queue) {
    return queue->head == nullptr;
}

inline void push(Queue** queue, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if((*queue)->tail)
        (*queue)->tail->next = newNode;
    (*queue)->tail = newNode;
    if(!(*queue)->head)
        (*queue)->head = (*queue)->tail;
}

inline int pop(Queue** queue) {
    if(isEmpty(*queue))
        return INT_MIN;
    Node* toDelete = (*queue)->head;
    int x = toDelete->data;
    (*queue)->head = (*queue)->head->next;
    if(!(*queue)->head)
        (*queue)->tail = nullptr;
    delete toDelete;
    return x;
}

inline void deleteQueue(Queue** queue) {
    Node* tmp = (*queue)->head;
    while(tmp) {
        Node* toDelete = tmp;
        tmp = tmp->next;
        delete toDelete;
    }
    (*queue)->head = nullptr;
    (*queue)->tail = nullptr;
}

inline int top(Queue* queue) {
    return queue->head->data;
}

inline void display(Queue* queue) {
    Node* tmp = queue->head;
    while(tmp) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

