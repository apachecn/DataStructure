#include"List2.h"
#include<iostream>
using namespace std;

List2::List2() {
    m_pList = new Node;
    // m_pList->data = 0;			// 实现Node类的时候，注释掉这一句，防止报错
    m_pList->next = NULL;
    m_iLength = 0;
}

List2::~List2() {
    ClearList();
    delete m_pList;
    m_pList = NULL;
}

void List2::ClearList() {
    // 清空单链表
    Node *currentNode = m_pList->next;
    while (currentNode != NULL) {	// 遍历整个链表，删除每个结点
        Node *temp = currentNode->next;
        delete currentNode;
        currentNode = temp;
    }
    m_pList->next = NULL;
    m_iLength = 0;
}

bool List2::ListEmpty() {
    return m_iLength == 0 ? true:false;
}

int List2::ListLength() {
    return m_iLength;
}

bool List2::GetElem(int i, Node *pNode) {
    // 指定位置获取元素
    if (i < 0 || i >= m_iLength) {
        return false;
    }

    // 用两个结点来找元素，当前结点和当前结点之前的一个结点。（暂时没懂为什么要用前一个结点）
    Node *currentNode = m_pList;
    Node *currentNodeBefore = NULL;
    for (int k = 0; k <= i; k++) {
        currentNodeBefore = currentNode;
        currentNode = currentNode->next;
    }

    pNode->data = currentNode->data;

    return true;
}

int List2::LocateElem(Node *pNode) {
    // 指定元素获取该元素的位置
    Node *currentNode = m_pList;
    int count = 0;
    while (currentNode->next != NULL) { // 用while循环不断寻找元素，count记录元素位置
        currentNode = currentNode->next;
        if (currentNode->data == pNode->data) {
            return count;
        }
        count++;
    }

    return -1;
}

bool List2::PriorElem(Node *pCurrentNode, Node *pPreNode) {
    // 指定元素找到该元素的前一个结点
    Node *currentNode = m_pList;
    Node *tempNode = NULL;
    while (currentNode->next != NULL) { // 用while循环来进行遍历，tempNode保存前驱结点
        tempNode = currentNode;
        currentNode = currentNode->next;
        if (currentNode->data == pCurrentNode->data) {
            if (tempNode == m_pList) {    // 当前节点不能为头节点
                return false;
            }
            pPreNode->data = tempNode->data;
            return true;
        }
    }

    return false;
}

bool List2::NextElem(Node *pCurrentNode, Node *pNextNode) {
    // 指定元素找到该元素的后一个结点
    Node *currentNode = m_pList;
    while (currentNode->next != NULL) {     // 用while循环来遍历，不需要另一个遍历存储的原因是可以直接返回改结点的next
        currentNode = currentNode->next;
        if (currentNode->data == pCurrentNode->data) {
            if (currentNode->next == NULL) {    // 当前节点不能为尾节点
                return false;
            }
            pNextNode->data = currentNode->next->data;
            return true;
        }
    }

    return false;
}


bool List2::ListInsert(int i, Node *pNode) {
    if ((i < 0) || (i > m_iLength)) { // 插入的位置是否合法，可以插入最后一个节点所以可以不等于m_iLength
        return false;
    }

    Node *currentNode = m_pList;     // 找到需要插入节点的位置i
    for (int k = 0; k < i; k++) {
        currentNode = currentNode->next;
    }

    Node *newNode = new Node;       // 申请内存，失败就返回false
    if (newNode == NULL) {
        return false;
    }

    newNode->data = pNode->data;    // 传入需要插入的数据域
    newNode->next = currentNode->next;  // 指针指向原来的指针指向的位置
    currentNode->next = newNode;    // 将newNode传给当前链表

    m_iLength++;
    return true;
}

bool List2::ListDelete(int i, Node *pNode) {
    // 假设要删除的节点为a，那么我们需要找到a的上一个节点，才能删除节点a
    if ((i < 0) || (i >= m_iLength)) { // 插入的位置是否合法，不能删除最后一个位置的下一个数据，所以不能等于m_iLength
        return false;
    }

    Node *currentNode = m_pList;      // 插入需要删除节点的位置和前一个节点的位置
    Node *currentNodeBefore = NULL;
    for (int k = 0; k <= i; k++) {
        currentNodeBefore = currentNode;
        currentNode = currentNode->next;
    }

    currentNodeBefore->next = currentNode->next; // 将节点a的next赋值给节点a之前那个节点的next
    pNode->data = currentNode->data;  // 取出节点a的数据
    delete currentNode;               // 删除节点a

    m_iLength--;
    return true;
}

bool List2::ListInsertHead(Node *pNode) {
    // 插入到头部
    Node *temp = m_pList->next;     // 暂存一开始的指针域
    Node *newNode = new Node;       // 申请内存，内存申请失败就返回false
    if (newNode == NULL) {
        return false;
    }

    newNode->data = pNode->data;    // 只需要传入的数据域，不需要指针
    newNode->next = temp;           // 指针域重新变为之前的m_pList的指针域，完成连接链表
    m_pList->next = newNode;        // 将数据给链表

    m_iLength++;                    // 已经插入成功，链表长度+1
    return true;
}

bool List2::ListInsertTail(Node *pNode) {
    // 插入到尾部
    Node *currentNode = m_pList;    // 遍历整个链表，直到找到最后一个节点，特征是最后一个节点的指针指向NULL
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    Node *newNode = new Node;       // 申请内存，内存申请失败就返回false
    if (newNode == NULL) {
        return false;
    }

    newNode->data = pNode->data;    // 传入数据域
    newNode->next = NULL;           // 最后一个节点的指针域指向NULL
    currentNode->next = newNode;    // 将newNode放在当前节点(原最后一个节点)的位置上
    m_iLength++;                    // 已经插入成功，链表长度+1
    return true;
}


void List2::ListTraverse() {
    Node *currentNode = m_pList;
    while (currentNode->next != NULL) {	// 遍历操作
        currentNode = currentNode->next;
        currentNode->printNode();
    }
}
