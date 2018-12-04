#include"List.h"
#include<iostream>
using namespace std;

List::List(int size) {
    m_iSize = size;
    m_pList = new Coordinate[m_iSize];
    m_iLength = 0;
}

List::~List() {
    delete []m_pList;
    m_pList = NULL;
}

void List::ClearList() {
    m_iLength = 0;
}

bool List::ListEmpty() {
    return m_iLength == 0 ? true:false;
}

int List::ListLength() {
    return m_iLength;
}

bool List::GetElem(int i, Coordinate *e) {
    // 指定序号获取元素
    if (i < 0 || i >= m_iLength) {
        return false;
    }
    *e = m_pList[i];
    return true;
}

int List::LocateElem(Coordinate *e) {
    // 指定元素获取该元素的序号
    for (int i = 0; i < m_iLength; i++) {
        if (m_pList[i] == *e) {
            return i;
        }
    }
    return -1;
}

bool List::PriorElem(Coordinate *currentElem, Coordinate *preElem) {
    // 指定元素获取该元素的前一个元素
    int temp = LocateElem(currentElem);
    if (temp == -1 || temp == 0) { // 如果元素不存在或者该元素是第一个结点，则返回false
        return false;
    } else {
        *preElem = m_pList[temp - 1];
        return true;
    }
}

bool List::NextElem(Coordinate *currentElem, Coordinate *NextElem) {
    // 指定元素获取该元素的后一个元素
    int temp = LocateElem(currentElem);
    if (temp == -1 || temp == m_iLength - 1) { // 如果元素不存在或者该元素是最后一个结点，则返回false
        return false;
    } else {
        *NextElem = m_pList[temp + 1];
        return true;
    }
}


bool List::ListInsert(int i, Coordinate *e) {
    // 在指定位置插入指定元素
    if ((i < 0) || (i > m_iLength)) {
        return false;
    }
    // 从最后一个元素到指定位置的元素，全部后移一位
    for (int k = m_iLength - 1; k >= i; k--) {
        m_pList[k+1] = m_pList[k];
    }

    m_pList[i] = *e;
    m_iLength++;
    return true;
}

bool List::ListDelete(int i, Coordinate *e) {
    // 指定位置删除元素
    if ((i < 0) || (i >= m_iLength)) {
        return false;
    }

    *e = m_pList[i];
    // 从指定位置到最后一个元素，全部前移一位
    for (int k = i + 1; k < m_iLength; k++) {
        m_pList[k-1] = m_pList[k];
    }

    m_iLength--;
    return true;
}

void List::ListTraverse() {
    for (int i = 0; i < m_iLength; i++) {
        cout << m_pList[i] << endl;
        // m_pList[i].printCoordinate();
    }
}
