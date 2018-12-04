#include<iostream>
#include"stdlib.h"
#include"MyStack.h"
using namespace std;


int main(void) {
    MyStack *pStack = new MyStack(5);

    pStack->push('h');  // 栈底
    pStack->push('e');
    pStack->push('l');
    pStack->push('l');
    pStack->push('o');  // 栈顶

    pStack->stackTraverse(true);

    char elem = 0;
    pStack->pop(elem);

    cout << elem << endl;

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
