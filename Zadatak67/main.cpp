#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
#define FILE_NAME "D:/Projects/C++/Zadatak67/data.txt"

struct DoubleElem {
    int data;
    DoubleElem* next;
    DoubleElem* prev;
};
typedef DoubleElem list;

list* create() {
    fstream f(FILE_NAME);
    if (!f)
        exit(1);
    int n;
    f >> n;
    list* head = nullptr,*prev = nullptr;
    for (int i = 0; i < n; i++) {
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
    return head;
}

void display(list* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

list* insert(list* head, int n) {

    list* newNode = new list();
    newNode->data = n;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if(!head) {
        return newNode;
    }
    list* tail = head;
    while(tail->next)
        tail = tail->next;
    tail->next = newNode;
    newNode->prev = tail;
    return head;
}

bool isInList(const list* head, int n) {
    while(head) {
        if(head->data == n)
            return true;
        head = head->next;
    }
    return false;
}

int zbirDuplikata(list* lst) {
    int sum =0;
    list* curr = lst;
    list* tmpHead = lst;
    list* helper = nullptr;
    while(lst) {
        int seen = 0;
        while(curr) {
            if(curr->data == lst->data) {
                seen++;
            }
            curr = curr->next;
        }
        if(seen >= 2 && !isInList(helper, lst->data)) {
            sum += lst->data;
            helper = insert(helper, lst->data);
        }
        lst = lst->next;
        curr = tmpHead;
    }

    while (helper) {
        list* toDelete = helper;
        helper = helper->next;
        delete toDelete;
    }

    return sum;
}

int main() {
    list* lst = create();
    display(lst);
    cout << zbirDuplikata(lst) << endl;
}
