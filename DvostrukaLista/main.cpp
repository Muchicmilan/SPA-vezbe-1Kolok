
#include "DvostrukaLista.h"
int main() {
    string fileName = "D:/Projects/C++/DvostrukaLista/data.txt";
    dblList* lst = createList(fileName);
    dblList** lstPtr = &lst;
    display(lst);
    invertedDisplay(lst);
    dblList* tmp = lst->next->next->next->next;
    cout << biggerSumList(tmp) << endl;
    displayBiggerListPart(tmp);


}

