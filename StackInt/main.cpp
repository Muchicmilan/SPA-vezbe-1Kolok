#include "Stack.h"
int main() {
    string fileName = "D:/Projects/C++/StackInt/data.txt";
    fstream file(fileName);
    if (!file)
        return 1;
    int n;
    stack* s1 = createStack();
    stack* s2 = createStack();
    file >> n;
    for (int i = 0; i < n; i++) {
        int data;
        file >> data;
        push(&s1,data);
    }
    displayStack(s1);
    push(&s2,1);
    push(&s2,2);
    push(&s2,3);
    push(&s2,4);
    push(&s2,10);
    push(&s2,7);
    displayStack(s2);
    displayStack(merge(s1,s2));
    file.close();
    return 0;
}
