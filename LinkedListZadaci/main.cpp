#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Elem {
    int data;
    Elem* next;
};
typedef Elem list;

list* createList(const string& fileName, int &x) {
    int n;
    list* firstNode = nullptr;
    list* lastNode = nullptr;
    ifstream file(fileName);
    if(!file.is_open())
        exit(1);
    file >> n;
    for (int i = 0; i < n; i++) {
        list* lst = new list();
        file >> lst->data;
        lst->next = nullptr;
        if(!firstNode)
            firstNode = lst;
        else
            lastNode->next = lst;
        lastNode = lst;
    }
    file >> x;
    file.close();
    return firstNode;

}

void printList(list* l) {
    if(l == nullptr)
        cout << "Empty list" << endl;
    while(l) {
        cout << l->data << " ";
        l = l->next;
    }
    cout << endl;
}

void eliminate(list** l, int x) {
    list* prevNode = nullptr;
    if(l == nullptr) //Ako je lista prazna nemamo sta da brisemo
        return;
    list* tmpList = *l;
    while(tmpList) {
        if(tmpList->data > x) { //Ako je vece od x brisemo
            list* old = tmpList;
            tmpList = tmpList->next;
            if(!prevNode) //U slucaju da obrisemo glavu liste potrebno je updejtovati listu do sledece glave
                *l = tmpList;
            else
                prevNode->next = tmpList; //Prethnodni node pokazuje na trenutni deo liste
            delete old;
        }
        else {
            prevNode = tmpList; //Kad se zavrsi iteracija idemo za 1 unapred i prev nam postaje trenutni
            tmpList = tmpList->next;
        }
    }
}


int main() {
    string fileName = "D:/Projects/C++/LinkedListZadaci/data.txt.txt";
    int x;
    list* lst = createList(fileName,x);
    printList(lst);
    cout << x << endl;
    eliminate(&lst,x);
    printList(lst);
    return 0;
}
