#include <iostream>
using namespace std;

struct Queue {
    int data;
    Queue* next;
};

Queue* createQueue() {
    return nullptr;
}

bool isEmpty(Queue* head, Queue* tail) {
    return head == nullptr;
}

void push(int data, Queue** head, Queue** tail) {
    Queue* newNode = new Queue();
    newNode->data = data;
    newNode->next = nullptr;
    if (*tail)
        (*tail)->next = newNode;
    *tail = newNode;
    if (!*head)
        *head = *tail;
}

int pop(Queue** head, Queue** tail) {
    if (isEmpty(*head, *tail)) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    Queue* temp = *head;
    int x = temp->data;
    *head = (*head)->next;
    if (!*head)
        *tail = nullptr;
    delete temp;
    return x;
}

int top(Queue* head, Queue* tail) {
    if (isEmpty(head, tail)) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return head->data;
}

void display(Queue* head, Queue* tail) {
    Queue* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteQueue(Queue** head, Queue** tail) {
    while (*head) {
        Queue* temp = *head;
        *head = (*head)->next;
        delete temp;
    }
    *tail = nullptr;
}

int mostOfNumber(int x, Queue** head, Queue** tail) {
    int count = 0;
    Queue* newHead = nullptr;
    Queue* newTail = nullptr;

    while (!isEmpty(*head, *tail)) {
        if (top(*head, *tail) == x) {
            if (count == 0) {
                push(pop(head, tail), &newHead, &newTail);
                count++;
            } else {
                pop(head, tail);
                count++;
            }
        } else {
            push(pop(head, tail), &newHead, &newTail);
        }
    }

    while (!isEmpty(newHead, newTail)) {
        push(pop(&newHead, &newTail), head, tail);
    }

    return count;
}

int mostAppeared(Queue** head, Queue** tail) {
    int most = 0;
    Queue* newHead = nullptr;
    Queue* newTail = nullptr;

    while (!isEmpty(*head, *tail)) {
        int currentMost = mostOfNumber(top(*head, *tail), head, tail);
        most = max(most, currentMost);
        push(pop(head, tail), &newHead, &newTail);
    }

    while (!isEmpty(newHead, newTail)) {
        push(pop(&newHead, &newTail), head, tail);
    }

    return most;
}

int main() {
    Queue* head = nullptr;
    Queue* tail = nullptr;

    push(1, &head, &tail);
    push(2, &head, &tail);
    push(3, &head, &tail);
    push(4, &head, &tail);
    push(2, &head, &tail);
    push(1, &head, &tail);
    push(2, &head, &tail);

    cout << "Original queue: ";
    display(head, tail);

    int count = mostOfNumber(2, &head, &tail);
    cout << "Occurrences of 2: " << count << endl;

    cout << "Modified queue: ";
    display(head, tail);

    int most = mostAppeared(&head, &tail);
    cout << "Most appeared element count: " << most << endl;

    deleteQueue(&head, &tail);

    return 0;
}
