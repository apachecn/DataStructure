#include"MyStack.h"
#include"Coordinate.h"
#include<iostream>
using namespace std;

template <typename T>			// 实现模板操作，声明T
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
    return 0 == m_iTop ? true:false   // if(m_iTop == 0)
}

template <typename T>
bool MyStack<T>::stackFull() {
    return m_iSize == m_iTop ? true:false  // >=
}

template <typename T>
void MyStack<T>::clearStack() {
    m_iTop = 0;
}

int MyStack<T>::stackLength() {
    return m_iTop;
}

template <typename T>
bool MyStack<T>::push(T elem) {
    if (stackFull()) {
        return false;
    }
    m_pBuffer[m_iTop] = elem;
    m_iTop++;
    return true;
}

template <typename T>
bool MyStack<T>::pop(T &elem) {
    if (stackEmpty()) {
        return false;
    }
    m_iTop--;
    elem = m_pBuffer[m_iTop];
    return true;
}

template <typename T>
void MyStack<T>::stackTraverse(bool isFromButtom) {
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


