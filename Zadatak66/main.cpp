#include <iostream>
#include <string>
#include <fstream>
#define FILE_NAME_ONE "D:/Projects/C++/Zadatak66/data.txt"
#define FILE_NAME_TWO "D:/Projects/C++/Zadatak66/data2.txt"
using namespace std;

struct DoubleElem {
    int data;
    DoubleElem* next;
    DoubleElem* prev;
};
typedef DoubleElem list;

list* create(const string& fileName) {
    fstream f(fileName);
    if (!f)
        exit(1);
    int n;
    f >> n;
    list* head = nullptr, *prev = nullptr;
    for (int i = 0; i < n; i++) {
        list* newNode = new list();
        f >> newNode->data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (!head)
            head = newNode;
        else {
            prev->next = newNode;
            newNode->prev = prev;
        }
        prev = newNode;
    }
    return head;
}

void display(list* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

list* razlika(list* lst1, list* lst2) {
    list* newHead = nullptr,* prev = nullptr;
    bool direction = false;
    while(lst1) {
        list* newNode = new list();
        newNode->data = lst1->data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if(!newHead)
            newHead = newNode;
        else {
            prev->next = newNode;
            newNode->prev = prev;
        }
        prev = newNode;
        lst1 = lst1->next;
    }
    list* toDelete = nullptr, *curr = newHead;
    while(lst2) {
        while(curr) {
            if(curr->data == lst2->data) {
                toDelete = curr;
                if(!toDelete->prev) {
                    toDelete->next->prev = nullptr;
                    newHead = toDelete->next;
                }
                else if(!toDelete->next)
                    toDelete->prev->next = nullptr;
                else {
                    toDelete->prev->next = toDelete->next;
                    toDelete->next->prev = toDelete->prev;
                }
                curr = curr->next;
                delete toDelete;
            }
            else
            curr = curr->next;
        }
        lst2 = lst2->next;
        curr = newHead;
    }
    return newHead;
}
int main() {
    list* lst1 = create(FILE_NAME_ONE);
    list* lst2 = create(FILE_NAME_TWO);
    display(lst1);
    display(lst2);
    display(razlika(lst1, lst2));
}
