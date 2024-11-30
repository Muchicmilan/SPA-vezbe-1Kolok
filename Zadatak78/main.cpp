#include <iostream>
using namespace std;
struct stack {
    char data;
    stack *next;
};

bool isEmpty(stack *s) {
    return s == nullptr;
}
void push(stack** s, char x) {
    auto* newNode = new stack();
    newNode->data = x;
    newNode->next = *s;
    *s = newNode;
}

char top(stack *s) {
    return s->data;
}

char pop(stack** s) {
    if (isEmpty(*s))
        return ' ';
    char x = (*s)->data;
    stack* toDelete = *s;
    *s = (*s)->next;
    delete toDelete;
    return x;
}

stack * createStack() {
    return nullptr;
}

void display(stack* s) {
    while (s) {
        cout << s->data << ' ';
        s = s->next;
    }
    cout << endl;
}

void removeBombs(stack** s) {
    stack* helper = createStack();
    char bomb = '*';
    while (!isEmpty(*s)) {
        char x = pop(s);
        if(x != bomb)
            push(&helper, x);
    }
    stack* helper2 = createStack();
    while (!isEmpty(helper)) {
        char x = pop(&helper);
        push(&helper2, x);
    }
    delete helper;
    while (!isEmpty(helper2)) {
        char x = pop(&helper2);
        push(s,x);
    }
    delete helper2;
}

int main() {
    stack* s = createStack();
    push(&s, '*');
    push(&s, 'A');
    push(&s, 'B');
    push(&s, '*');
    push(&s, 'C');
    push(&s, 'D');
    push(&s, '*');
    display(s);
    removeBombs(&s);
    display(s);
    return 0;
}
