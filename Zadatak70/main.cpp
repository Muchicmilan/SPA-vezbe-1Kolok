#include <iostream>
#include <string>
#include <climits>
using namespace std;

struct Stack {
    int data;
    Stack* next;
};

Stack* CreateStack() {
    return nullptr;
}

void Push(Stack** top, int data) {
    auto* temp = new Stack;
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

bool isEmptyStack(const Stack* top) {
    return top == nullptr;
}

int pop(Stack** top) {
    if (isEmptyStack(*top)) {
        cerr << "Error: Stack underflow" << endl;
        exit(EXIT_FAILURE);
    }
    Stack* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    delete temp;
    return data;
}

int peek(const Stack* top) {
    if (isEmptyStack(top)) {
        cerr << "Error: Stack is empty" << endl;
        exit(EXIT_FAILURE);
    }
    return top->data;
}

void deleteStack(Stack** top) {
    while (!isEmptyStack(*top)) {
        pop(top);
    }
}

int computePolish(const string& s) {
    Stack* S = CreateStack();
    size_t n = s.length();

    for (size_t i = 0; i < n; i++) {
        char symbol = s[i];
        if ((symbol - '0' >= 0) && (symbol - '0' <= 9)) {
            Push(&S, symbol - '0');
        } else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
            int n1 = pop(&S);
            int n2 = pop(&S);
            int sum;
            switch (symbol) {
                case '+': sum = n2 + n1; break;
                case '-': sum = n2 - n1; break;
                case '*': sum = n2 * n1; break;
                case '/':
                    if (n1 == 0) {
                        cerr << "Error: Division by zero" << endl;
                        deleteStack(&S);
                        exit(EXIT_FAILURE);
                    }
                    sum = n2 / n1;
                    break;
                default:
                    cerr << "Error: Invalid operator" << endl;
                    deleteStack(&S);
                    exit(EXIT_FAILURE);
            }
            Push(&S, sum);
        }
    }

    int result = peek(S);
    deleteStack(&S);
    return result;
}

int main() {
    cout << computePolish("3564-*6+*2/") << endl;
    return 0;
}
