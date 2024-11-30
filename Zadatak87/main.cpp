#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MAX_CHARS 128

struct Node {
    char data;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
};

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = nullptr;
    queue->tail = nullptr;

    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->head == nullptr;
}

void push(Queue* queue, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = nullptr;
    if(queue->tail)
        queue->tail->next = newNode;
    queue->tail = newNode;
    if(isEmpty(queue))
        queue->head = queue->tail;
}

char pop(Queue* queue) {
    if(isEmpty(queue))
        return NULL;
    Node* toDelete = queue->head;
    char c = toDelete->data;
    queue->head = queue->head->next;
    free(toDelete);
    return c;
}

char top(Queue* queue) {
    return queue->head->data;
}

void deleteQueue(Queue* queue) {
    Node* toDelete = nullptr;
    Node* tmp = queue->head;
    while(tmp) {
        toDelete = tmp;
        tmp = tmp->next;
        free(toDelete);
    }
    free(queue);
}

void display (Queue* queue) {
    if(isEmpty(queue))
        return;
    Node* tmp = queue->head;
    while(tmp) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void firstAppearence (Queue* queue) {
    Queue* helper = createQueue();
    bool c[MAX_CHARS] = {false};
    while(!isEmpty(queue)) {
        if(c[(int)(top(queue))] == true)
            pop(queue);
        else {
            push(helper, top(queue));
            c[(int)(top(queue))] = true;
            pop(queue);
        }
    }
    while(!isEmpty(helper))
        push(queue, pop(helper));
    deleteQueue(helper);
}


int main() {
    fstream f("D:/Projects/C++/Zadatak87/data.txt");
    if(!f)
        return 1;
    Queue* queue = createQueue();
    while(f.good()) {
        char c;
        c = f.get();
        push(queue, c);
    }
    display(queue);
    firstAppearence(queue);
    display(queue);
    deleteQueue(queue);
    return 0;
}
