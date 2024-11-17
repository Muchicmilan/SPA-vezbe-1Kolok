#include <iostream>
#include<string>
#include<fstream>
using namespace std;

struct JednostrukaLista {
    int data;
    JednostrukaLista *next;
};

struct DvostrukaLista {
    JednostrukaLista* head;
    DvostrukaLista* next;
    DvostrukaLista* prev;
};

typedef struct JednostrukaLista list;
typedef struct DvostrukaLista dList;

dList* addNew(dList* lst) {
    auto newDList = new dList();
    auto newNode = new list();
    newDList->head = newNode;
    newDList->next = nullptr;
    if(!lst) {
        newDList->prev = nullptr;
        return newDList;
    }
    dList* curr = lst;
    while(curr->next)
        curr = curr->next;
    newDList->prev = curr;
    curr->next = newDList;
    return lst;
}

dList* insert(dList* lst,int data) {
    if(!lst->head) {
        auto newNode = new list();
        newNode->data = data;
        newNode->next = nullptr;
        return lst;
    }
    dList* curr = lst;
    while(curr) {
        if(curr->head->data > data) {
            auto newNode = new list();
            newNode->data = data;
            newNode->next = nullptr;
            while(curr->head->next)
                curr->head = curr->head->next;
            curr->head->next = newNode;
            return lst;
        }
            if(curr->next)
                curr = curr->next;
            else {
                curr = addNew(curr);
                curr = curr->next;

        }
    }
    return lst;
}

void display(dList* lst) {
    auto curr = lst;
    while(curr) {
        while(curr->head) {
            cout << "Double Node: ";
            cout << curr->head->data << " ";
            curr->head = curr->head->next;
        }
        curr = curr->next;
    }
}


int main() {
    dList* lst;
    lst = insert(lst,1);
    display(lst);
    return 0;
}
