#include<iostream>
#include"stdlib.h"
#include"MyStack.h"
#include"Coordinate.h"
using namespace std;


int main(void) {
    MyStack<char> *pStack = new MyStack<char>(5);

    Coordinate coor1(1,2);
    Coordinate coor2(3,2);
    pStack->push('2');  // 栈底
    pStack->push('2');

    pStack->stackTraverse(true);

    pStack->stackTraverse(false);

    pStack->clearStack();


    cout << pStack->stackLength() << endl;

    if (pStack->stackEmpty()) {
        cout << "栈为空" << endl;
    }

    if (pStack->stackFull()) {
        cout << "栈为满" << endl;
    }

    delete pStack;
    pStack = NULL;


    // system("pause");
    return 0;
}
