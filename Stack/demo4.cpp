#include<iostream>
#include"stdlib.h"
#include"MyStack.h"
#include"Coordinate.h"
using namespace std;

int strlen(const char *str) {
    // 实现strlen,返回字符串长度
    if ('\0' == *str)
        return 0;
    else
        return strlen(str + 1) + 1;
}

int main(void) {
    MyStack<char> *pStack = new MyStack<char>(30);

    MyStack<char> *pNeedStack = new MyStack<char>(30);

    char str[] = "[()])";

    char currentNeed = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != currentNeed) {
            pStack->push(str[i]);
            switch(str[i]) {
            case '[':
                if (currentNeed != 0) {
                    pNeedStack->push(currentNeed);
                }
                currentNeed = ']';
                break;
            case '(':
                if (currentNeed != 0) {
                    pNeedStack->push(currentNeed);
                }
                currentNeed = ')';
                break;
            case  '{':
                if (currentNeed != 0) {
                    pNeedStack->push(currentNeed);
                }
                currentNeed = '}';
                break;
            default:
                cout << "fail" << endl;
                return 0;
            }
        } else {
            char elem;
            pStack->pop(elem);
            pNeedStack->pop(currentNeed);
        }
    }

    if (pStack->stackEmpty()) {
        cout << "success" << endl;
    } else {
        cout << "fail" << endl;
    }

    delete pStack;
    pStack = NULL;


    delete pNeedStack;
    pNeedStack = NULL;

    return 0;
}
