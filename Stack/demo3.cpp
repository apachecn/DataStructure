#include<iostream>
#include"stdlib.h"
#include"MyStack.h"
#include"Coordinate.h"
using namespace std;


#define BINARY		2
#define OCTONARY	8
#define HEXADECIMAL	16

int main(void) {
    char num[] = "0123456789ABCDEF";
    MyStack<int> *pStack = new MyStack<int>(30);

    int N = 2016;
    int mod = 0;

    while (N > 0) {
        mod = N % HEXADECIMAL;
        pStack->push(mod);
        N /= HEXADECIMAL;
    }

    /* for (int i =pStack->stackLength() - 1; i >= 0;)
    {
      num[pStack]
    }
    */

    int elem = 0;
    while (!pStack->stackEmpty()) {
        pStack->pop(elem);
        cout << num[elem];
    }

    //pStack->stackTraverse(false);
    delete pStack;
    pStack = NULL;

    return 0;
}
