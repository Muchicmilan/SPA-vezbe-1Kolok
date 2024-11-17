#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct doubleLinkedList {
    char data;
    doubleLinkedList* next;
    doubleLinkedList* prev;
};

typedef doubleLinkedList list;

list* create(const string& word) {
    list* head = nullptr;
    list* prev = nullptr;
    for (const char c : word) {
        auto newNode = new list();
        newNode->data = c;
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
    return head;
}

void display(list* lst) {
    while(lst) {
        cout << lst->data;
        lst = lst->next;
    }
    cout << endl;
}

bool isPalindrom(list* head) {
    list* tail = head;
    while(tail->next)
        tail = tail->next;
    while(tail && head) {
        while(tail->data == ' ')
            tail = tail->prev;
        while(head->data == ' ')
            head = head->next;
        if(tolower(tail->data) == tolower(head->data)) {
            tail = tail->prev;
            head = head->next;
        }
        else
            return false;
    }
    return true;
}

int main() {
    list* head = create("Ana voli Milovana");
    display(head);
    if(isPalindrom(head))
        cout << "Palindrom" << endl;
    else
        cout << "Not a palindrom" << endl;
}
