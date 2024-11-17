#include <iostream>
#include <string>
#include <fstream>
#define FILE_NAME "D:/Projects/C++/Zadatak65/data.txt"
using namespace std;

struct DoubleList {
    int data;
    DoubleList *next;
    DoubleList *prev;
};
typedef DoubleList list;

list* create(const string& fileName) {
    fstream f(fileName);
    if(!f)
        exit(1);
    list* head = nullptr;
    list* prev = nullptr;
    int n;
    f >> n;
    for(int i = 0; i < n; i++) {
        list* newNode = new list();
        f >> newNode->data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if(!head)
            head = newNode;
        else {
            prev->next = newNode;
            newNode->prev = prev;
        }
        prev = newNode;
    }
    head->prev = prev;
    prev->next = head;
    return head;
}

void display(list* head) {
    const list* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    }while(curr != head);
    cout << endl;
}

list* invert(list* head) {
    list* curr = head;
    list* newHead = nullptr;
    list* prev = nullptr;
    do {
        curr = curr->next;
    }while(curr->next != head);
    do {
        list* newNode = new list();
        newNode->data = curr->data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if(!newHead)
            newHead = newNode;
        else {
            prev->next = newNode;
            newNode->prev = prev;
        }
        prev = newNode;
        curr = curr->prev;
    }while(curr != head->prev);
    newHead->prev = prev;
    prev->next = newHead;
    return newHead;
}

int main() {
    list* lst = create(FILE_NAME);
    display(lst);
    display(invert(lst));
}
