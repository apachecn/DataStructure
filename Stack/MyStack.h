#ifndef MYSTACK_H
#define MYSTACK_H
#include "Coordinate.h"
#include<stdio.h>
#include<iostream>
using namespace std;
template <typename T>

class MyStack {
  public:
    MyStack(int size);	 // 分配内存初始化栈空间，设定栈容量，栈顶
    ~MyStack();		 // 回收栈空间内存
    bool stackEmpty();	 // 判定栈是否为空，为空返回true，否则返回false
    bool stackFull() ;	 // 判定栈是否已满，为满返回true，否则返回false
    void clearStack();	 // 清空栈
    int stackLength();	 // 栈中已有元素个数
    bool push(T elem);  // 元素入栈，栈顶上升
    bool pop(T &elem);  // 元素出栈，栈顶下降
    void stackTraverse(bool isFromButtom);  // 遍历栈中所有元素

  private:
    T *m_pBuffer;	         // 栈空间指针
    int m_iSize;		 // 栈容量
    int m_iTop;		 // 栈顶或者栈中元素个数，不需要额外一个变量说明栈中个数和位置，因为这是栈
};




template <typename T>
MyStack<T>::MyStack(int size) {
    m_iSize = size;
    m_pBuffer = new T[m_iSize];
    m_iTop = 0;
}

template <typename T>
MyStack<T>::~MyStack() {
    delete []m_pBuffer;
}


template <typename T>
bool MyStack<T>::stackEmpty() {
    if (0 == m_iTop) { // if(m_iTop == 0)
        return true;
    }
    return false;
}

template <typename T>
bool MyStack<T>::stackFull() {
    if (m_iSize == m_iTop) { // >=
        return true;
    }
    return false;
}

template <typename T>
void MyStack<T>::clearStack() {
    m_iTop = 0;
}

template <typename T>
int MyStack<T>::stackLength() {
    return m_iTop;
}


template <typename T>
bool MyStack<T>::push(T elem) {
    if (stackFull()) {
        return false;
    }
    m_pBuffer[m_iTop] = elem;    // 因为栈的特性，所以可以直接在最后一个位置进行赋值
    m_iTop++;
    return true;
}

template <typename T>
bool MyStack<T>::pop(T &elem) {
    if (stackEmpty()) {
        return false;
    }
    m_iTop--;
    elem = m_pBuffer[m_iTop];   // 因为栈的特性，可以直接将m_iTop减1
    return true;
}

template <typename T>
void MyStack<T>::stackTraverse(bool isFromButtom) {
    // 遍历栈，由isFromButtom决定顺序
    if (isFromButtom) {
        for (int i = 0; i < m_iTop; i++) {
            // m_pBuffer[i].printCoordinate();
            cout << m_pBuffer[i];
        }
    } else {
        for (int i = m_iTop - 1; i >= 0; i--) {
            // m_pBuffer[i].printCoordinate();
            cout << m_pBuffer[i];
        }
    }
}

#endif
