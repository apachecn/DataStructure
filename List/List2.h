#ifndef LIST2_H
#define LIST2_H
#include"Node.h"
#include"Person.h"

// 加上Node类实现，单链表

class List2 {
  public:
    List2();
    ~List2();
    void ClearList();       // 清空线性表
    bool ListEmpty();       // 判断线性表是否为空
    int ListLength();       // 获取线性表长度
    bool GetElem(int i, Node *pNode);  // 获取指定元素
    int LocateElem(Node *pNode);  // 寻找第一个满足e的数据元素的位序
    bool PriorElem(Node *pCurrentNode, Node *pPreNode);      // 获取指定元素的前驱
    bool NextElem(Node *pCurrentNode, Node *pNextNode);      // 获取指定元素的后继
    bool ListInsert(int i, Node *pNode);  // 在第i个位置插入元素
    bool ListDelete(int i, Node *pNode);  // 删除第i个位置的元素
    bool ListInsertHead(Node *pNode);     // 从头部插入元素
    bool ListInsertTail(Node *pNode);     // 从尾部插入元素
    void ListTraverse();    // 遍历线性表

  private:
    Node *m_pList;
    int m_iLength;
};

#endif
