#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <valarray>
using namespace std;

struct Elem {
    int data;
    Elem *next;
};

typedef struct Elem list;

list* create(const string& fileName) {
    fstream f(fileName);
    list* head = nullptr;
    list* prev = nullptr;
    if (!f) {
        cout << "File could not be opened" << endl;
        exit(1);
    }
    int n;
    f >> n;
    for (int i = 0; i < n; i++) {
        list* newHead = (list*)malloc(sizeof(list));
        f >> newHead->data;
        newHead->next = nullptr;
        if(!head)
            head = newHead;
        else
            prev->next = newHead;
        prev = newHead;
    }
    return head;
}

void display(list* head) {
    if(head == nullptr)
        cout << "empty list" << endl;
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

bool isPrime(const int x) {
    if(x == 1 || x==3) return true;
    if(x == 2) return false;

    for (int i = 2; i <= sqrt(x); i++) {
        if(x%i == 0)
            return false;
    }
    return true;
}

list* removePrime(list* lst) {
    list* current = lst;
    list* prev = nullptr;
    while(current) {
        if (isPrime(current->data)) {
            list* old = current;
            if(prev) {
                prev->next = current->next;
                current = current->next;
                delete old;
            }
            else {
                current = current->next;
                lst = current;
                delete old;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    return lst;
}

int main() {
    string fileName = "D:/Projects/C++/Zadatak48/data.txt";
    list* list1 = create(fileName);
    display(list1);
    free(list1);
    if(isPrime(9))
        cout << "Prime" << endl;
    display(removePrime(list1));
    return 0;
}
