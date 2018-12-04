#include<iostream>
#include<stdlib.h>
#include"MyQueue.h"
#include"Customer.h"
using namespace std;

int main(void) {
    MyQueue *p = new MyQueue(4);
    Customer c1("zhangsan", 20);
    Customer c2("lisi", 30);
    Customer c3("wangwu", 24);

    p->EnQueue(c1);
    p->EnQueue(c2);
    p->EnQueue(c3);

    Customer c4("", 0);
    p->DeQueue(c4);
    c4.printInfo();

    p->QueueTraverse();

    p->QueueTraverse();
    delete p;
    p = NULL;


    //system("pause");
    return 0;
}
