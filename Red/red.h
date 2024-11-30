#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#ifndef RED_H
#define RED_H

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
};

inline Queue* createQueue() {
    auto* queue = new Queue();
    Node* node = new Node();
    if(!queue || !node)
        return nullptr;
    queue->head = queue->tail = nullptr;
    return queue;
}

inline bool isEmpty(Queue* queue) {
    return queue->head == nullptr;
}

inline void enQueue(Queue* queue, int data) {
    Node* node = new Node();
    if(!node)
        return;
    node->data = data;
    node->next = nullptr;
    if(queue->tail)
        queue->tail->next = node;
    queue->tail = node;
    if(!queue->head)
        queue->head = queue->tail;
}

inline int deQueue(Queue* queue) {
    if(!isEmpty(queue)) {
        cout << "Queue is empty!";
        return INT_MIN;
    }
    Node* toDelete = queue->head;
    int ret = toDelete->data;
    queue->head = queue->head->next;
    delete toDelete;
    return ret;
}

inline void deleteQueue(const Queue* queue) {
    const Node* tmp = queue->head;
    while(tmp) {
        const Node *toDelete = tmp;
        tmp = tmp->next;
        delete toDelete;
    }
    delete queue;
}

#endif //RED_H
