#include"List2.h"

#include<stdlib.h>
#include<iostream>
using namespace std;


int main(void) {
    Node node1;
    node1.data.name = "test1";
    node1.data.phone = "123456";
    Node node2;
    node2.data.name = "test2";
    node2.data.phone = "234567";

    List2 *pList = new List2();

    pList->ListInsertTail(&node1);
    pList->ListInsertTail(&node2);

    pList->ListTraverse();

    delete pList;
    pList = NULL;

    return 0;
}
