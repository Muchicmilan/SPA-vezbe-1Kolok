#pragma once
#include <iostream>
#include<string>
#include<fstream>
using namespace std;
#ifndef KRUZNELISTE_H
#define KRUZNELISTE_H

struct DoubleElem { //Zadatak 64
    int data;
    DoubleElem* next;
    DoubleElem* prev;
};
typedef DoubleElem list;

inline list* create(const string& fileName) {
    fstream f(fileName);
    if(!f) {
        cout << "Can't open file " << fileName << endl;
        exit(1);
    }
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
    prev->next = head;
    head->prev = prev;
    return head;
}

inline void display(list* head) {
    list* curr = head;
    do {
        cout << curr->data << ' ';
        curr = curr->next;
    }while(curr != head);
    cout << endl;
}

inline list* filler(list* lst, int x, int y, int z) {
    list* curr = lst;
    do{
        if(curr->data == x && curr->next->data == y) {
            list* newNode = new list();
            newNode->data = z;
            newNode->next = curr->next;
            curr->next->prev = newNode;
            newNode->prev = curr;
            curr->next = newNode;
        }
        curr = curr->next;
    }while(curr != lst);
    return lst;
}

#endif //KRUZNELISTE_H
