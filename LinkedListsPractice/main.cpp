
#include "linkedlist.h"
#include "Array.h"
int main()
{
 /*   List *list1 = new List();
    List *list2 = new List();
    List *list3 = new List();
    List *list4 = new List();
    List *list5 = new List();
    list1->next = list2;
    list2->next = list3;
    list1->data = 5;
    list2->data = 6;
    list3->data = 7;
    list4 = addFirst(list1, 4);
    list5 = addLast(list1, 8);
    cout << getSize(list1) << endl;
    writeList(list4);
    cout << getSize(list4) << endl;
    */
    list* lst = loadNFromConsoleBack(5);
    writeList(lst);
    list* lst2 = listInsertKBehindM(lst,3,5);
    writeList(lst2);
    return 0;
}
