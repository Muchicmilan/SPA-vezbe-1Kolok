
//
// Created by Milan on 11/24/2024.
//
#pragma once

#include<iostream>
#include <string>
#include <fstream>

#define VALID 0
#define NOT_CLOSED 1
#define NOT_OPENED 2
#define INVALID_CLOSE_1 3
#define INVALID_CLOSE_2 4
#define INVALID_CLOSE_3 5

using namespace std;

#ifndef STACK_H
#define STACK_H

struct Node {
    char data;
    Node* next;
};

typedef Node Stack;

inline Stack* createStack() {
    return nullptr;
}

inline bool isEmpty(const Stack* stack) {
    return stack == nullptr;
}

inline void push(Stack** top, char data) {
    Stack* newStack = new Stack();
    newStack->data = data;
    newStack->next = *top;
    *top = newStack;
}

inline char pop(Stack** top) {
    Stack* toDelete = *top;
    *top = (*top)->next;
    char data = toDelete->data;
    delete toDelete;
    return data;
}

inline char top(Stack* vrh) {
    if(isEmpty(vrh))
        return INT_MIN;
    return vrh->data;
}

inline short priority(const char c) { //Zadatak 71
    switch(c) {
        case '+': case '-' : return 0;
        case '*': case '/' : return 1;
        case '^': return 2;
        default: return -1;
    }
}
inline string infixToPostfix(string s) {
    Stack* stack = createStack();
    string result;
    for(int i=0; i<s.length(); i++) {
        char c = s[i];
        if((c >= 'a' && c <= 'z') || (c>='A' && c<='Z'))
            result += c;
        else if(c == '(')
            push(&stack, c);
        else if(c == ')') {
            while(top(stack) != '(') {
                result += top(stack);
                pop(&stack);
            }
            pop(&stack);
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while(!isEmpty(stack) && priority(top(stack)) >= priority(c)) {
                result += top(stack);
                pop(&stack);
            }
            push(&stack, c);
        }
    }
    while(!isEmpty(stack)) {
        result += top(stack);
        pop(&stack);
    }
    return result;
}

inline void reverseStrings(const string& fileName, const string& fileNameExit) {
    fstream f(fileName);
    if(!f)
        return;
    ofstream out(fileNameExit);
    Stack* stack = createStack();
    while(!f.eof()) {
        char c = f.get();
        if(c ==' ' || c == '\t' || c == '\n') {
            while(!isEmpty(stack))
                out << pop(&stack);
            out << c;
        }
        else
            push(&stack, c);
    }
    while(!isEmpty(stack))
        out << pop(&stack);
    out.close();
    f.close();
}

inline unsigned short validParenthesis(string& s) {
    Stack *stack = createStack();
    for(int i=0; i<s.length(); i++) {
        char c = s[i];
        if(c == '(' || c == '{' || c == '[')
            push(&stack, c);
       else if(c == ')') {
            if(top(stack) == '[')
                return INVALID_CLOSE_2;
            if(top(stack) == '{')
                return INVALID_CLOSE_3;
            if(isEmpty(stack))
                return NOT_OPENED;
            pop(&stack);
        }
        else if(c==']') {
            if(top(stack) == '(')
                return INVALID_CLOSE_1;
            if(top(stack) == '{')
                return INVALID_CLOSE_3;
            if(isEmpty(stack))
                return NOT_OPENED;
            pop(&stack);
        }
        else if(c== '}') {
            if(top(stack) == '(')
                return INVALID_CLOSE_1;
            if(top(stack) == '[')
                return INVALID_CLOSE_2;
            if(isEmpty(stack))
                return NOT_OPENED;
            pop(&stack);
        }

    }
    if(isEmpty(stack))
        return VALID;

    return NOT_CLOSED;
}
#endif //STACK_H
