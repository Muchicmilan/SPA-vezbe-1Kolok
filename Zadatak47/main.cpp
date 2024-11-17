#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Elem {
    int data;
    Elem *next;
};

typedef Elem list;

list* createTwoLists(const string& fileName, list*& other) {
    fstream f(fileName);
    if (!f) {
        cout << "File could not be opened" << endl;
        exit(1);
    }
    int n;
    list* first = nullptr;
    list* prevNode = nullptr;
    f >> n;
    for (int i = 0; i < n; i++) {
        list *head = new list();
        f >> head->data;
        head->next = nullptr;
        if(!first)
            first = head;
        else
            prevNode->next = head;
        prevNode = head;
    }
    other = first;
    first = nullptr;
    prevNode = nullptr;
    int m;
    f >> m;
    for (int i = 0; i < m; i++) {
        list *head = new list();
        f >> head->data;
        head->next = nullptr;
        if(!first)
            first = head;
        else
            prevNode->next = head;
        prevNode = head;
    }
    return first;
}

void printL(const list* list) {
    while(list) {
        cout << list->data << ' ';
        list = list->next;
    }
    cout << endl;
}

list* copyListInverted(const list* lst) {
    list* prevNode = nullptr;
    while(lst) {
        list* newNode = new list();
        newNode->data = lst->data;
        newNode->next = prevNode;
        prevNode = newNode;
        lst = lst->next;
    }
    return prevNode;
}

list* unionR(list* first, list* second) {
    list* secondInverted = copyListInverted(second);
    list* result = copyListInverted(first);
    list* headResult = result;
    list* prevNode=nullptr;
        while(result && secondInverted) {
            list* newNode = new list();
            newNode->data = secondInverted->data;
            if(newNode->data <= result->data) {
                newNode->next = result;
                if(prevNode != nullptr)
                    prevNode->next = newNode;
                else
                    headResult = newNode;
                prevNode = newNode;
                secondInverted = secondInverted->next;
            }
            else {
                prevNode = result;
                result = result->next;
            }
        }
   while(secondInverted) {
       list* newNode = new list();
       newNode->data = secondInverted->data;
       newNode->next = nullptr;
       prevNode->next = newNode;
       prevNode = newNode;
       secondInverted = secondInverted->next;
    }
    return headResult;
}


int main() {
    string fileName = "D:/Projects/C++/Zadatak47/data.txt";
    list* first = nullptr;
    list* second = createTwoLists(fileName,first);
    printL(second);
    printL(first);
    printL(unionR(first,second));
    return 0;
}
