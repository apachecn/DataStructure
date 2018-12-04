#include"List.h"
#include"Coordinate.h"
#include<stdlib.h>
#include<iostream>
using namespace std;



int main(void) {
    // 3 5 7 2 9 1 8
    Coordinate e1 (3, 2);
    Coordinate e2 (5, 4);
    Coordinate e3 (7, 1);
    Coordinate e4 (2, 1);
    Coordinate e5 (9, 1);
    Coordinate e6 (100, 1);

    Coordinate temp (0, 0);
    List *list1 = new List(10);

    // cout << "length:" << list1->ListLength() << endl;

    list1->ListInsert(0, &e1);

    // cout << "length:" << list1->ListLength() << endl;


    list1->ListInsert(1, &e2);
    list1->ListInsert(2, &e3);
    list1->ListInsert(3, &e4);
    list1->ListInsert(4, &e5);
    list1->ListInsert(2, &e6);

    // list1->ListDelete(0, &temp);

    // if (!list1->ListEmpty())
    // {
    //   cout << "not empty" << endl;
    // }

    // list1->ClearList();

    // cout << "#" << temp << endl;

    // if (list1->ListEmpty())
    // {
    //   cout << "is empty" << endl;
    // }
    list1->ListTraverse();

    cout << "GetElem" << endl;

    list1->GetElem(10, &temp);
    cout << "temp:" << temp << endl;

    // temp = 101;
    // cout << list1->LocateElem(&temp) << endl;

    // list1->PriorElem(&e4, &temp);
    // cout << "temp:" << temp << endl;

    // list1->NextElem(&e4, &temp);
    // cout << "temp:" << temp << endl;


    delete list1;
    list1 = NULL;

    return 0;
}
