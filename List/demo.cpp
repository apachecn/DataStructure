#include"List.h"
#include<stdlib.h>
#include<iostream>
using namespace std;



int main(void) {
    // 3 5 7 2 9 1 8
    int e1 = 3;
    int e2 = 5;
    int e3 = 7;
    int e4 = 2;
    int e5 = 9;
    int e6 = 100;
    int temp = 0;
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

    cout << "#" << temp << endl;

    // if (list1->ListEmpty())
    // {
    //   cout << "is empty" << endl;
    // }
    // list1->ListTraverse();

    list1->GetElem(0, &temp);
    cout << "temp:" << temp << endl;

    temp = 101;
    cout << list1->LocateElem(&temp) << endl;

    list1->PriorElem(&e4, &temp);
    cout << "temp:" << temp << endl;

    list1->NextElem(&e4, &temp);
    cout << "temp:" << temp << endl;


    delete list1;
    list1 = NULL;

    return 0;
}
