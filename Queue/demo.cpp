#include<iostream>
#include<stdlib.h>
#include"MyQueue.h"
using namespace std;
int main(void) {
    MyQueue *p = new MyQueue(4);
    // 插入
    p->EnQueue(10);
    p->EnQueue(12);
    p->EnQueue(16);
    p->EnQueue(20);
    p->EnQueue(22); // 第五个元素插入失败
    cout << "插入4个元素后遍历" << endl;
    p->QueueTraverse(); // 遍历

    // 删除头部元素
    int e = 0;
    p->DeQueue(e);
    cout << "第一次删除头部元素" << endl;
    cout << e << endl;
    // 继续删除头部元素
    p->DeQueue(e);
    cout << "第二次删除头部元素" << endl;
    cout << e << endl;

    cout << "两次删除后的遍历" << endl;
    cout << endl;
    p->QueueTraverse(); // 遍历

    // 删除所有元素
    p->ClearQueue();
    cout << "删除所有元素后的遍历" << endl;
    p->QueueTraverse(); // 遍历

    // 新插入两个元素
    p->EnQueue(20);
    p->EnQueue(30);
    cout << "新插入两个元素进行遍历" << endl;
    p->QueueTraverse();



    delete p;
    p = NULL;


    //system("pause");
    return 0;
}
