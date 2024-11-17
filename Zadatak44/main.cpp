#include <iostream>
using namespace std;
struct ElemS {
    char data;
    ElemS* next;
};

typedef struct ElemS list;

list* create(int n) {
    list* firstNode = nullptr;
    list* prevNode = nullptr;
    for (int i = 0; i < n; i++) {
        list* newNode = (list*)malloc(sizeof(list));
        cin >> newNode->data;
        newNode->next = nullptr;
        if(!firstNode)
            firstNode = newNode;
        else {
            prevNode->next = newNode;
        }
        prevNode = newNode;
    }
    return firstNode;
}

void display(list* l) {
    while(l) {
        cout << l->data;
        l = l->next;
    }
    cout << endl;
}

list* compare(list* l1, list* l2) {
    while(l1 && l2) {
        if(l1->data != l2->data) {
            return l1;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return nullptr;
}

void sort(list* l1) {
    bool swapped;
    do {
        swapped = false;
        list* temp = l1;
        list* prevNode = nullptr;
        while(temp && temp->next) {
            if(temp->data > temp->next->data) {
                list* temp1 = temp->next;
                temp->next = ;
            }
        }
    }
}


int main() {
    list* s = create(5);
    list* t = create(5);
    display(s);
    display(t);
    if(compare(s, t) == nullptr) {
        cout << "Equal" << endl;
        cout << compare(s, t) << endl;
    }
    else
        cout << "Not equal" << endl;
    cout << compare(s, t) << endl;
    return 0;
}
