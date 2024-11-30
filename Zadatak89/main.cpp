#include <iostream>

struct Queue {
    int data;
    Queue* next;
};
Queue* createQueue() {
    return nullptr;
}
bool isEmpty(Queue** head, Queue** tail) {
    return *head == nullptr;
}

void push(Queue** head, Queue** tail, int x) {
    Queue* newNode = new Queue();
    newNode->data = x;
    newNode->next = nullptr;
    if(*tail)
        (*tail)->next = newNode;
    *tail = newNode;
    if(!*head)
        *head = *tail;
}

int pop(Queue** head, Queue** tail) {
    Queue* temp = *head;
    int x = temp->data;
    *head = (*head)->next;
    if(!*head)
        *tail = nullptr;
    delete(temp);
    return x;
}

int top(Queue** head) {
    return (*head)->data;
}

void deleteQueue(Queue** head, Queue** tail) {
    Queue* temp = *head;
    while(temp) {
        Queue* toDelete = temp;
        temp = temp->next;
        delete(toDelete);
    }
    *head = nullptr;
    *tail = nullptr;
}

void display(Queue* head) {
    Queue* tmp = head;
    while(tmp) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

void redNegativnih(Queue** glavaZadani, Queue** repZadani, Queue** glavaTrazeni, Queue** repTrazeni) {
    Queue* tempHead = nullptr;
    Queue* tempTail = nullptr;
    while(!isEmpty(glavaZadani, repZadani)) {
        int elem = pop(glavaZadani, repZadani);
        if(elem < 0)
            push(glavaTrazeni, repTrazeni, elem);
        push(&tempHead, &tempTail, elem);
    }
    while(!isEmpty(&tempHead, &tempTail)) {
        int elem = pop(&tempHead, &tempTail);
        push(glavaZadani, repZadani, elem);
    }

}

int main() {
    Queue* glavaZadani = nullptr;
    Queue* repZadani = nullptr;
    Queue* glavaTrazeni = nullptr;
    Queue* repTrazeni = nullptr;
    push(&glavaZadani,&repZadani,2);
    push(&glavaZadani,&repZadani,-3);
    push(&glavaZadani,&repZadani,4);
    push(&glavaZadani,&repZadani,-5);
    push(&glavaZadani,&repZadani,6);
    display(glavaZadani);
    redNegativnih(&glavaZadani,&repZadani,&glavaTrazeni,&repTrazeni);
    display(glavaTrazeni);
    display(glavaZadani);
    return 0;
}
