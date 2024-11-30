#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//#define STACK_GROWTH 10
#define MAX 100
#define MAX_VALUE(a,b) ((a>b)?a:b)
struct Stack {
    int data;
    Stack* next;
};
typedef Stack stack;

inline stack* createStack() {
    return nullptr;
}

inline bool isEmpty(const stack* top) {
    return top == nullptr;
}

inline void push(stack** top, const int data) {
    auto* newTop = static_cast<stack *>(malloc(sizeof(stack)));
    if (newTop == nullptr) {
        return;
    }
    newTop->data = data;
    newTop->next = *top;
    *top = newTop;
}

inline int top(const stack* s) {
    return s->data;
}

inline int pop(stack** s) {
    const int data = (*s)->data;
    stack* toDelete = *s;
    *s = (*s)->next;
    free(toDelete);
    return data;
}

inline void deleteStack(stack** s) {
    while(*s) {
        stack* toDelete = *s;
        *s = (*s)->next;
        free(toDelete);
    }
}

inline void displayStack(stack* s) {
    while (s) {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

inline void izbaciBroj (stack* stek, int n, stack* novi) { //Zadatak 75
    int counter = 0;
    stack* helper = createStack();
    while (!isEmpty(stek)) {
        if(top(stek) == n) {
            push(&novi, counter);
            pop(&stek);
        }
        else
            push(&helper, pop(&stek));
        counter++;
    }
    while (!isEmpty(helper))
        push(&stek, pop(&helper));
    deleteStack(&helper);
}

//Zadatak 76
// struct DynamicStack {
//     int* data;
//     int size;
//     int top;
// };
//
// typedef DynamicStack dynStack;
//
// inline dynStack& create() {
//     dynStack s;
//     s.size = STACK_GROWTH;
//     s.top = -1;
//     s.data = new int[s.size]{};
//     return s;
// }
//
// inline bool isEmpty(const dynStack stk) {
//     return stk.top == -1;
// }
//
//
// inline void push(dynStack& stk, const int data) {
//     if (stk.top == stk.size-1) {
//         int* newData = new int[stk.size+STACK_GROWTH];
//         for (int i = 0; i < stk.size; i++)
//             newData[i] = stk.data[i];
//         int* toDelete = stk.data;
//         stk.data = newData;
//         delete toDelete;
//     }
//     stk.top = stk.top + 1;
//     stk.data[stk.top] = data;
// }
//
// inline int pop(dynStack& stk) {
//     if(isEmpty(stk)) {
//         cout << "Stack is empty" << endl;
//         exit(1);
//     }
//     const int data = stk.data[stk.top];
//     delete &stk.data[stk.top];
//     stk.top = stk.top - 1;
//     if(stk.top+1 <= stk.size+STACK_GROWTH) {
//         int* newData = new int[stk.size-STACK_GROWTH];
//         for (int i = 0; i < stk.size; i++)
//             newData[i] = stk.data[i];
//         int* toDelete = stk.data;
//         stk.data = newData;
//         delete toDelete;
//     }
//     return data;
// }

inline void removeDupes(stack** s) { //zadatak 77
    int pojavljivanja[MAX] = {0};
    stack* helper = createStack();
    while (!isEmpty(*s)) {
        const int x = pop(s);
        pojavljivanja[x]++;
        cout << x<< ' ' << pojavljivanja[x] << endl;
        push(&helper,x);
    }
    while (!isEmpty(helper)) {
        const int x = pop(&helper);
        if (pojavljivanja[x] == 1) {
            cout << "guram " << x << endl;
            push(s, x);
        }
    }
}

inline void insertSecond(int x, stack**s) { //zadatak 79
    stack* helper = createStack();
    while (!isEmpty(*s)) {
        const int y = pop(s);
        push(&helper, y);
    }
    int counter =0;
    while (!isEmpty(helper)) {
        if(counter == 1)
            push(s,x);
        else {
            const int y = pop(&helper);
            push(s, y);
        }
        counter++;
    }
    deleteStack(&helper);
}

inline stack* merge(stack* s1, stack* s2) { //zadatak 80
    stack* result = createStack();
    while (!isEmpty(s1) && !isEmpty(s2)) {
        if(top(s1) >= top(s2))
            push(&result, pop(&s2));
        else
            push(&result, pop(&s1));
    }
    stack* remaining = isEmpty(s1) ? s2 : s1;
    while (!isEmpty(remaining))
        push(&result, pop(&remaining));
    return result;
}

inline bool isSequence(int pushed[], int popped[], int n) { //zadatak 81
    int i=0,j=0;
    stack* s = createStack();
    while(i<n) {
        while(!isEmpty(s) && (top(s) == popped[j])) {
            pop(&s);
            j++;
        }
        push(&s, pushed[i]);
        i++;
    }
    while(j<n) {
        if(isEmpty(s) || top(s) != popped[j])
            return false;
        pop(&s);
        j++;
    }
    return true;
}

inline bool validSequence(const int sequence[]) { //zadatak 82
    int currPush = 0;
    stack* s = createStack();
    for (int i=0; i<9; i++) {
        while(currPush <= 9 && (isEmpty(s) || top(s) != sequence[i])) {
            push(&s, currPush);
            currPush++;
        }
        if(!isEmpty(s) && top(s) == sequence[i])
            pop(&s);
        else
            return false;
    }
    return true;
}

inline int histogramArea(int histogram[], int size) { //zadatak 83
    stack* index = createStack();
    int area = 0;
    for(int i=0; i<=size; i++) {
        int currHeight = (i==size) ? 0 : histogram[i];
        while(!isEmpty(index) && currHeight < histogram[top(index)]) {
            int height = histogram[top(index)];
            pop(&index);
            int width = isEmpty(index) ? i : i - top(index)-1;
            area = MAX_VALUE(area, width * height);
        }
        push(&index, i);
    }
    return area;

}

#ifndef STACK_H
#define STACK_H

#endif //STACK_H
