#ifndef LIST_H
#define LIST_H

#include"Coordinate.h"

// 顺序表

class List {
  public:
    List(int size);         // 创建线性表
    ~List();                // 销毁线性表
    void ClearList();       // 清空线性表
    bool ListEmpty();       // 判断线性表是否为空
    int ListLength();       // 获取线性表长度
    bool GetElem(int i, Coordinate *e);  // 获取指定元素
    int LocateElem(Coordinate *e);  // 寻找第一个满足e的数据元素的位序
    bool PriorElem(Coordinate *currentElem, Coordinate *preElem);                     // 获取指定元素的前驱
    bool NextElem(Coordinate *currentElem, Coordinate *nextElem);                    // 获取指定元素的后继
    bool ListInsert(int i, Coordinate *e);  // 在第i个位置插入元素
    bool ListDelete(int i, Coordinate *e);  // 删除第i个位置的元素
    void ListTraverse();    // 遍历线性表

  private:
    Coordinate *m_pList;
    int m_iSize;
    int m_iLength;
};

#endif
