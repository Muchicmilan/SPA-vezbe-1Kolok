#include <iostream>
#include <fstream>
using namespace std;
struct sNode {
    string data;
    sNode* next;
};

struct Doubly {
    int data;
    Doubly* next;
    Doubly* prev;
};

struct Stack {
    int data;
    Stack* next;
};

struct Queue {
    Stack* s1;
    Stack* s2;
};

Queue* createQueue() {
    Queue* queue = new Queue();
    queue->s1 = nullptr;
    queue->s2 = nullptr;
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->s2 == nullptr;
}


Stack* createStack() {
    return nullptr;
}
bool isEmpty(Stack* top) {
    return top == nullptr;
}
void push(Stack** top, int data) {
    Stack* newNode = new Stack();
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}
int pop(Stack** top) {
    if (isEmpty(*top))
        return INT_MIN;
    Stack* toDelete = *top;
    int x = toDelete->data;
    *top = (*top)->next;
    delete toDelete;
    return x;
}

int top(Stack* top) {
    return top->data;
}

void push(Queue** queue, int data) {
    if(isEmpty(*queue))
        push(&(*queue)->s2,data);
    while(!isEmpty((*queue)->s2))
        push(&(*queue)->s1,pop(&(*queue)->s2));
    push(&(*queue)->s1,data);
    while(!isEmpty((*queue)->s1))
        push(&(*queue)->s2,pop(&(*queue)->s1));
}

int pop(Queue** queue) {
    return pop(&(*queue)->s2);
}

int top(Queue* queue) {
    return top(queue->s2);
}

void display(Stack* top) {
    Stack* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void display(Queue* queue) {
    display(queue->s2);
}
void display(sNode* head) {
    sNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void display(Doubly* l) {
    if(!l)
        cout << "Empty list" << endl;
    Doubly* temp = l;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

sNode* create(const string& fileName) {
    fstream f(fileName);
    if(!f) {
        cout << "File could not be opened" << endl;
        exit(1);
    }
    int n;
    sNode* head = nullptr, *prev = nullptr;
    f>>n;
    f.ignore();
    for(int i=0;i<n;i++) {
        sNode* newNode = new sNode();
        getline(f, newNode->data);
        newNode->next = nullptr;
        if(!head)
            head = newNode;
        else
            prev->next = newNode;
        prev = newNode;
    }
    return head;
}

Doubly* createDoubly(const string& fileName) {
    fstream f(fileName);
    if(!f) {
        cout << "File could not be opened" << endl;
        exit(1);
    }
    Doubly* head = nullptr, *prev = nullptr;
    int n;
    f>>n;
    for(int i=0;i<n;i++) {
        Doubly* newNode = new Doubly();
        f>>newNode->data;
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
    return head;
}

bool compareString(string s1,string s2) {
    if(s1.length()!=s2.length())
        return false;
    for(int i=0;i<s1.length();i++) {
        if(s1[i]!=s2[i])
            return false;
    }
    return true;
}

int equalStringsInList(sNode* l, string A) {
    sNode* curr = l;
    int count = 0;
    while(curr) {
        if(compareString(curr->data,A))
            count++;
        curr = curr->next;
    }
    return count;
}

int izbaciN(Doubly** glava, int N) {
    int count = 0;
    Doubly* curr = *glava;
    while(curr->next)
        curr = curr->next; //Idemo do poslednje elementa u listi
    while(curr && count <= N) {
        Doubly* toDelete = curr;
        if(toDelete->prev != nullptr) {
            toDelete->prev->next = nullptr;
            curr = curr->prev;
        }
        else {
            *glava = nullptr;
            curr = nullptr;
        }
        count++;
        delete toDelete;
    }
    return count;
}

int main() {
    sNode* l = create("D:/Projects/C++/I_Kolokvijum_18_01_2024/data.txt");
    display(l);
    cout << equalStringsInList(l,"koji si ti") << endl;
    Doubly* l2 = createDoubly("D:/Projects/C++/I_Kolokvijum_18_01_2024/ulaz.txt");
    display(l2);
    cout << izbaciN(&l2,11) << endl;
    display(l2);
    fstream f("D:/Projects/C++/I_Kolokvijum_18_01_2024/ulaz_3_zadatak.txt");
    int i =1;
    Queue* queue = createQueue();
    push(&queue,6);
    push(&queue,7);
    push(&queue,8);
    pop(&queue);
    push(&queue,9);
    push(&queue,10);
    push(&queue,11);
    pop(&queue);
    pop(&queue);
    push(&queue,12);
    pop(&queue);
    display(queue);
    return 0;
}
