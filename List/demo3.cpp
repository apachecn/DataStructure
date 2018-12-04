#include"List2.h"

#include<stdlib.h>
#include<iostream>
using namespace std;

int main(void) {
    Node node1;
    node1.data = 3;
    Node node2;
    node2.data = 4;
    Node node3;
    node3.data = 5;
    Node node4;
    node4.data = 6;
    Node node5;
    node5.data = 7;
    List *pList = new List();


    // pList->ListInsertHead(&node1);
    // pList->ListInsertHead(&node2);
    // pList->ListInsertHead(&node3);
    // pList->ListInsertHead(&node4);
    // pList->ListInsertHead(&node5);


    // pList->ListInsertTail(&node1);
    // pList->ListInsertTail(&node2);
    // pList->ListInsertTail(&node3);
    // pList->ListInsertTail(&node4);
    // pList->ListInsertTail(&node5);


    Node temp;

    pList->ListInsert(0, &node1);

    pList->ListInsert(1, &node2);

    // pList->ListDelete(1, &temp);

    cout << "temp:" << temp.data << endl;

    pList->GetElem(1, &temp);
    // cout << "temp:" << temp.data << endl;

    cout << "getelem: " << temp.data << endl;


    pList->PriorElem(&node2, &temp);

    cout << "priorelem: " << temp.data << endl;

    pList->NextElem(&node1, &temp);

    cout << "nextelem: " << temp.data << endl;

    pList->ListTraverse();

    delete pList;
    pList = NULL;


    return 0;
}
