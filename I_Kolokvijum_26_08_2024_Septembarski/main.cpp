#include <iostream>
#include <fstream>
using namespace std;
#define FILE_NAME_PRVI_ZADATAK "D:/Projects/C++/I_Kolokvijum_26_08_2024_Septembarski/prvi_zadatak_data.txt"
#define FILE_NAME_DRUGI_ZADATAK "D:/Projects/C++/I_Kolokvijum_26_08_2024_Septembarski/drugi_zadatak_data.txt"
struct Node {
    int data;
    Node* next;
};

struct Doubly {
    int data;
    Doubly* next;
    Doubly* prev;
};

struct Cvor {
    int data;
    int id;
    Cvor* next;
};

void loadFromFileTwoLists(Node** l1, Node** l2) {
    fstream f(FILE_NAME_PRVI_ZADATAK);
    if (!f.is_open())
        return;
    int n1, n2;
    Node* prev = nullptr;
    Node* headL1 = nullptr, * headL2 = nullptr;
    f >> n1;
    for (int i = 0; i < n1; i++) {
        Node* newNode = new Node();
        f >> newNode->data;
        newNode->next = nullptr;
        if(!headL1)
            headL1 = newNode;
        else
            prev->next = newNode;
        prev = newNode;
    }
    f >> n2;
    prev->next = nullptr;
    prev = nullptr;
    for (int i = 0; i < n2; i++) {
        Node* newNode = new Node();
        f >> newNode->data;
        newNode->next = nullptr;
        if(!headL2)
            headL2 = newNode;
        else
            prev->next = newNode;
        prev = newNode;
    }
    f.close();
    *l1 = headL1;
    *l2 = headL2;
}

Node* createFromTwoLists(Node* l1, Node* l2) {
    Node* curr1 = l1, *curr2 = l2;
    Node* prev = nullptr;
    while(curr1 && curr2) {
        Node* newNode = new Node();
        newNode->next = prev;
        if(curr1->data > curr2->data) {
            newNode->data = curr1->data;
            curr1 = curr1->next;
        }
        else {
            newNode->data = curr2->data;
            curr2 = curr2->next;
        }
        prev = newNode;
    }
    Node* remaining = curr1 ? curr1 : curr2;
    while(remaining) {
        Node* newNode = new Node();
        newNode->data = remaining->data;
        newNode->next = prev;
        remaining = remaining->next;
        prev = newNode;
    }
    return prev;
}

void display(Node* l) {
    Node* temp = l;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void display(Doubly* l) {
    Doubly* temp = l;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Doubly* findMax(Doubly* l) {
    Doubly* temp = l;
    Doubly* max = l;
    while (temp) {
        if (temp->data > max->data)
            max = temp;
        temp = temp->next;
    }
    return max;
}

void moveMaxToFirst(Doubly** l) {
    Doubly* max = findMax(*l);
    if(max->next == nullptr) {
        max->prev->next = nullptr;
    }
    else if(max->prev == nullptr) {
        cout << "Max je vec prvi element" << endl;
        return;
    }
    else {
        max->prev->next = max->next;
        max->next->prev = max->prev;
    }
    max->next = *l;
    (*l)->prev = max;
    *l = max;
}

Doubly* loadDoublyListFromFile(const string& fileName) {
    fstream f(fileName);
    if(!f) {
        cout << "File could not be opened" << endl;
        exit(1);
    }
    int n;
    f >> n;
    Doubly* prev = nullptr;
    Doubly* head = nullptr;
    for (int i = 0; i < n; i++) {
        Doubly* newNode = new Doubly();
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
    f.close();
    return head;
}

int broj_pobeda(Cvor* glava) {
    if(glava == nullptr)
        return 0;
    return glava->data + broj_pobeda(glava->next);
}

int main() {
    Node* l1 = nullptr;
    Node* l2 = nullptr;
    Doubly* l4 = loadDoublyListFromFile(FILE_NAME_DRUGI_ZADATAK);
    loadFromFileTwoLists(&l1, &l2);
    Node* l3 = createFromTwoLists(l1, l2);
    display(l1);
    display(l2);
    display(l3);
    display(l4);
    moveMaxToFirst(&l4);
    display(l4);
    return 0;
}
