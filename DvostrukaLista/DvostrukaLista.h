//
// Created by Milan on 11/9/2024.
//
#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef DVOSTRUKALISTA_H
#define DVOSTRUKALISTA_H

struct Elem {
    int data;
    Elem *next;
    Elem *prev;
};

typedef struct Elem dblList;

inline dblList* createList(const string& fileName) {
    fstream f(fileName);
    if (!f.is_open()) {
        cout << "Error opening file " << fileName << endl;
        exit(1);
    }
    dblList* head = nullptr;
    dblList* prev = nullptr;
    int n;
    f >> n;
    for (int i = 0; i < n; i++) {
        auto* newNode = new dblList();
        f >> newNode->data;
        newNode->prev = nullptr;
        newNode->next = nullptr;
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

inline dblList* getHead(dblList* head) {
    return head;
}

inline dblList** getTail(dblList* head) {
    while (head->next)
        head = head->next;
    return &head;
}

inline int getSize(dblList* head) {
    int size = 0;
    while (head) {
        head = head->next;
        size++;
    }
    return size;
}

inline void display(dblList* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

inline void invertedDisplay(dblList* head) {
    while (head->next)
        head = head->next;
    while (head) {
        cout << head->data << ' ';
        head = head->prev;
    }
    cout << endl;
}

inline dblList* getMin(dblList* head) { //53
    dblList* minNode = nullptr;
    int min = head->data;
    while (head->next) {
        if (head->next->data < min)
            min = head->next->data;
        head = head->next;
    }
    while(head->prev) {
        if (head->prev->data == min)
            minNode = head->prev;
        head = head->prev;
    }
    return minNode;
}

inline dblList* filler(dblList* lst) { //54
    dblList* prevNode = nullptr;
    dblList* currNode = lst;
    while (currNode->next) {
        if(currNode->data + 1 != currNode->next->data) {
            auto* newNode = new dblList();
            newNode->data = currNode->data + 1;
            newNode->next = currNode->next;
            currNode->next = newNode;
            newNode->prev = currNode;
        }
        else
            currNode = currNode->next;
    }
    return lst;
}

inline dblList* deleteMin(dblList* lst) { //55 Ne radi samo u slucaju kad je prosledjen rep liste, probao sam i chatgpt i on ne zna sto
    if (!lst) return nullptr; // Handle empty list case

    // Find the minimum value in the list
    int min = lst->data;
    dblList* currNode = lst;
    while (currNode->next) { // Traverse forward to find min value
        if (currNode->data < min) {
            min = currNode->data;
        }
        currNode = currNode->next;
    }

    // Traverse backward from the end, deleting nodes with min value
    while (currNode) {
        cout << "i am working" << endl;
        dblList* prevNode = currNode->prev; // Store the previous node
        if (currNode->data == min) {
            if (currNode == lst) {
                // Deleting the head node
                lst = currNode->next;
                if (lst) lst->prev = nullptr;
            }
            else if (currNode->next == nullptr) {
                // Deleting the tail node
                currNode->prev->next = nullptr;
            }
            else {
                // Deleting a middle node
                currNode->prev->next = currNode->next;
                currNode->next->prev = currNode->prev;
            }
            delete currNode;
            break;
        }
        currNode = prevNode; // Move to the previous node
    }
    return lst;
}

inline int deleteN(dblList** head, dblList** tail, int n) { //56 ne radi ne znam sto
    // If n is larger than the size of the list, delete all nodes
    if (n > getSize(*head)) {
        int size = getSize(*head);
        while (*head) {
            dblList* old = *head;
            *head = (*head)->next;
            delete old;
        }
        *tail = nullptr;  // Reset tail to nullptr if the list is empty
        return size;  // Return the original size before deletion
    }

    // Start from the tail and move backwards to delete n nodes
    dblList* currNode = *tail;
    int i = 0;

    while (currNode && i < n) {
        dblList* old = currNode;
        currNode = currNode->prev;  // Move to the previous node

        if (currNode) {
            currNode->next = nullptr;  // Break the link to the deleted node
        }

        delete old;  // Delete the current node
        i++;
    }

    // Update the tail pointer to the new last node
    *tail = currNode;

    // If the list is now empty, reset the head as well
    if (!*tail) {
        *head = nullptr;
    }

    return n - i;  // Return how many nodes were actually deleted
}

inline dblList* moveMaxNodeToBeginning(dblList* head) { //57
    dblList* currNode = head;
    dblList* maxNode = head;
    while(currNode) {
        if (currNode->data > maxNode->data)
            maxNode = currNode;
        currNode = currNode->next;
    }
    if(!maxNode->prev) {
        return head;
    }

    else if(!maxNode->next) {
        maxNode->prev->next = nullptr;
    }
    else if(maxNode->next) {
        maxNode->prev->next = maxNode->next;
        maxNode->next->prev = maxNode->prev;
    }
    maxNode->next = head;
    head->prev = maxNode;
    head = maxNode;
    return head;
}

inline int biggerSumList(dblList* ptr) { //58 part 1
    int left = 0, right = 0;
        dblList* leftNode = ptr->prev;
        dblList* rightNode = ptr->next;
    if(leftNode) {
        while(leftNode->prev) {
            left += leftNode->data;
            leftNode = leftNode->prev;
        }
        left += leftNode->data;
    }
    if(rightNode) {
        while(rightNode->next) {
            right += rightNode->data;
            rightNode = rightNode->next;
        }
        right += rightNode->data;
    }
    if(right == left)
        return 0;
    return left>right ? -1 : 1;
}

inline void displayBiggerListPart(dblList* ptr) { //58 part 2
    int unsigned short const biggerSum = biggerSumList(ptr);
    dblList* currNode = nullptr;
    if(biggerSum == 0) {
        cout << "Jednake su obe strane" << endl;
        return;
    }
    else if(biggerSum == 1)
        currNode = ptr->next;
    else
        currNode = ptr->prev;
    while(currNode) {
        cout << currNode->data << "->";
        if(biggerSum == 1)
            currNode = currNode->next;
        else
            currNode = currNode->prev;
    }
    cout << "NULL" << endl;
}


#endif //DVOSTRUKALISTA_H
