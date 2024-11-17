#include "kruzneliste.h"

int main() {
    string fileName = "D:/Projects/C++/KruzneListe/data.txt";
    list* lst = create(fileName);
    display(filler(lst,3,6,10));
}
