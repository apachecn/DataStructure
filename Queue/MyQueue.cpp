#include"MyQueue.h"
#include<iostream>
using namespace std;

MyQueue::MyQueue(int queueCapacity) {
    m_iQueueCapacity = queueCapacity;		// 队列的容量
    m_pQueue = new Customer[m_iQueueCapacity];    // new一个新的队列
    ClearQueue();					// 清空队列，确保队列为空
}


MyQueue::~MyQueue() {
    delete []m_pQueue;				// 删除队列
    m_pQueue = NULL;
}

void MyQueue::ClearQueue() {
    // 初始化队列的头、尾、队列长度
    m_iHead = 0;
    m_iTail = 0;
    m_iQueueLen = 0;
}

bool MyQueue::QueueEmpty() {
    return m_iQueueLen == 0 ? true:false;		// 如果队列长度为空就返回true否则返回false
}

bool MyQueue::QueueFull() {
    return m_iQueueLen == m_iQueueCapacity ? true:false; // 如果队列长度达到了队列容量大小就返回true否则就返回false
}

int MyQueue::QueueLength() {
    return m_iQueueLen;				// 返回队列的长度
}

bool MyQueue::EnQueue(Customer element) {
    /*
     * 在队列没有满的情况下，
     * 向队尾进行赋值，队尾指针后移
     * 队尾指针重新赋值为，队尾指针对队列容量取余
     * 队列长度+1
    */
    if (QueueFull()) {
        return false;
    }
    m_pQueue[m_iTail] = element;
    m_iTail++;
    m_iTail = m_iTail % m_iQueueCapacity;
    m_iQueueLen++;
    return true;
}

bool MyQueue::DeQueue(Customer &element) {
    /*
     * 如果队列不为空的话，
     * 取出队首元素，队首指针后移
     * 队首指针重新赋值为，队首指针对队列容量取余
     */
    if (QueueEmpty()) {
        return false;
    }
    element = m_pQueue[m_iHead];
    m_iHead++;
    m_iHead = m_iHead % m_iQueueCapacity;
    m_iQueueLen--;
    return true;
}

void MyQueue::QueueTraverse() {
    // 遍历队列元素，从队头到队列长度+队头，
    cout << endl;
    for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++ ) {
        m_pQueue[i%m_iQueueCapacity].printInfo();
        cout << "前面还有" << (i-m_iHead) << "人" << endl;
    }
    cout << endl;
}

