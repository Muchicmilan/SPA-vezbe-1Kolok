#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



struct List { //Definicija liste
    int data;
    List* next;
};

typedef struct List list;

inline int getSize(const List* lst) { //Zadatak 14
    int i =0;
    while(lst) {
        i++;
        lst = lst->next;
    }
    return i;
}

inline void writeList(const List* lst) { //Zadatak 15
    while(lst) {
        cout << lst->data << " ";
        lst = lst->next;
    }
    cout<<endl;
}

inline List* addFirst(List* lst, int data) { //Zadatak 16
    List* newList = new List();
    newList->data = data;
    newList->next = lst;
    while(lst)
        lst = lst->next;
    return newList;
}

inline List* addLast(List* lst, int data) { //Zadatak 17
    List* newList = new List();
    if(newList != nullptr) {
        newList->data = data;
        newList->next = nullptr;
    }
    if(!lst)
        return newList;
    else {
        while(lst->next)
            lst = lst->next;
        lst->next = newList;
        return newList;
    }
}

inline List* loadNFromConsoleFront(int n) { //Zadatak 18
    List* ptr = nullptr;
    for(int i=0; i<n; i++) {
        int data;
        cin >> data;
        List* newList = new List();
        newList->data = data;
        newList->next = ptr;
        ptr = newList;
    }
    return ptr;
}

inline List* loadFromFileFront(string const &fileName) {
    list* ptr = nullptr;
    ifstream file(fileName);
    int data;
    file >> data;
    if(!file.is_open())
        cout << "File could not be opened" << endl;
    for(int i=0; i<data; i++) {
        List* newList = new List();
        file >> newList->data;
        newList->next = ptr;
        ptr = newList;
    }
    file.close();
    return ptr;
}

inline list* loadNFromConsoleBack(int n) { //Zadatak 19
    list* head = nullptr;
    list* ptrBack = nullptr;
    for(int i=0; i<n; i++) {
        list* newList = new List();
        cin >> newList->data;
        newList->next = nullptr;
        if(!head) {
            head = newList;
            ptrBack = newList;
        }
        else {
            ptrBack->next = newList;
            ptrBack = newList;

        }
    }
    return head;
}

inline void listDelete(List* head) { //Zadatak 20
    while(head) {
        list* last = head;
        head = head->next;
        delete last;
    }
}

inline list* ignoreDataN(list* head, int n) { //Zadatak 21
    list* ptr = head, *last = nullptr;
    while(ptr) {
        if(ptr->data != n) {
            last = ptr;
            ptr = ptr->next;
        }
        else {
            list* nodeN = ptr;
            ptr = ptr->next;
            if(!last)
                head = ptr;
            else
                last->next = ptr;
            delete nodeN;
        }
        return head;
    }

}

inline int countBiggerThanFirst(list* head) { //Zadatak 29
    int count = 0;
    int n = head->data;
    while(head->next) {
        if(head->next->data > n)
            count++;
        head = head->next;
    }
    return count;
}

inline int countRepetitionOfN(list* head, int n) { //Zadatak 30
    int count = 0;
    while(head) {
        if(head->data == n)
            count++;
        head = head->next;
    }
    return count;
}

inline list* getMin(list* head) { //Zadatak 31
    int min = head->data;
    list* minNode = head;
    while(head) {
        if(head->data < min) {
            min = head->data;
            minNode = head;
        }
        head = head->next;
    }
    return minNode;
}

inline void removeNodeAfterMinNode(list* head) {
    list* minNode = getMin(head);
    if(minNode == nullptr || minNode->next == nullptr)
        return;
    list* redudant1 = minNode->next;
    minNode->next = minNode->next->next;
    delete redudant1;
}

inline int recursiveCountPositiveNodes(list* head) { //34
    if(head->next == nullptr)
        return 0;
    else {
        if(head->data >= 0) {
            return recursiveCountPositiveNodes(head->next) + 1;
        }
        else
            return recursiveCountPositiveNodes(head->next);
    }
}

inline void sortList(list* head) { //35
    list* tmp = head;
    bool swap;
    do {
        swap = false;
        list* tmp = head;
        while(tmp->next) {
            if(tmp->data > tmp->next->data) {
                int temp = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = temp;
                swap = true;
            }
            tmp = tmp->next;
        }

    }while(swap);
}

inline void removeBiggerThanN (list* head, int n) {
    list* newHead = head;
    list* tmp = nullptr;
    while(newHead) {
        if(newHead->data < n)
            newHead = newHead->next;
        else
            break;
    }
    list *poslednjiManjOdN = newHead;
    while(newHead) {
        const list* old = newHead;
        newHead = newHead->next;
        delete old;
    }
    while(head->next != poslednjiManjOdN) {
        head = head->next;
    }
    head->next = nullptr;

}

inline void removeEvenNodes(list*& head) {
    while(head && head->data % 2 == 0) {
        list* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    if(!head)
        return;

    list* newHead = head;
    while(newHead->next) {
        if(newHead->next->data % 2 == 0) {
            list* toDelete = newHead->next;
            newHead->next = newHead->next->next;
            delete toDelete;
        }
        else
            newHead = newHead->next;

    }

}

inline list* copyInverted(const list* head) {
    list* newHead = nullptr;
    list* tmpPointer = nullptr;
    while(head) {
        newHead = new list();
        newHead->data = head->data;
        newHead->next = tmpPointer;
        tmpPointer = newHead;
        head = head->next;
    }
    return newHead;
}

inline list* copy(const list* head) {
    list* newHead = nullptr;
    list* frontPointer = nullptr;
    list* backPointer = nullptr;
    while (head) {
        newHead = new list();
        newHead->data = head->data;
        newHead->next = nullptr;
        if(!frontPointer)
            frontPointer = newHead;
        else
            backPointer->next = newHead;
        backPointer= newHead;
        head = head->next;
    }
    return frontPointer;

}

inline int* convertListToArray(const list* head) {
    int s = getSize(head);
    int* array = new int[s];
    for(int i =0; i < s; i++) {
        array[i] = head->data;
        head = head->next;
    }
    return array;
}

inline bool isInList(const list* head, const int b) {
    while(head) {
        if(head->data == b)
            return true;
        head = head->next;
    }
    return false;
}

inline list* listUnion(const list* l1,const list* l2) {
    list* newHead = nullptr;
    list* nextNode = nullptr;
    while(l1) {
        if(!isInList(newHead,l1->data)) {
            newHead = new list();
            if(newHead != nullptr) {
                newHead->data = l1->data;
                newHead->next = nextNode;
                nextNode = newHead;
            }
        }
        l1 = l1->next;
    }
    while(l2) {
        if(!isInList(newHead,l2->data)) {
            newHead = new list();
            newHead->data = l2->data;
            newHead->next = nextNode;
            nextNode = newHead;
        }
        l2 = l2->next;
    }
    return newHead;
}

inline list* listInsertKBehindM(list* l1,int m,int k) {
    list* l2 = l1;
    while(l2 && l2->data != m)
      l2 = l2->next;
    list* newNode = new list();
    newNode->data = k;
    if(l2 == nullptr) {
        newNode->next = l1;
        l1 = newNode;
    }
    else {
        newNode->next = l2->next;
        l2->next = newNode;
    }
    return l1;
}

inline int miniLists(list* l1,int m,int d) {
    int miniLists = 0;
    list* l2;
    while(l1) {
        int i=0;
        int sum =0;
        l2 = l1;
        while(l2 && i < m) {
            sum += l2->data;
            i++;
            l2 = l2->next;
        }
        if(m == i && sum == d)
            miniLists++;
        l1 = l1->next;
    }
    return miniLists;
}

