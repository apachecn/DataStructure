#include<iostream>
#include"Tree.h"
using namespace std;

Tree::Tree(int size, int *pRoot) {
    m_iSize = size;
    m_pTree = new int[m_iSize];
    // 初始化树中每个结点为0
    for (int i = 0; i < size; i++) {
        m_pTree[i] = 0;
    }
    // 根节点的索引，进行赋值
    m_pTree[0] = *pRoot;
}


Tree::~Tree() {
    delete []m_pTree;
    m_pTree = NULL;
}

int *Tree::SearchNode(int nodeIndex) {
    // 指定结点索引，找到结点
    if ((nodeIndex < 0) || (nodeIndex >= m_iSize)) {  // 检查是否不在范围内
        return NULL;
    }
    if (m_pTree[nodeIndex] == 0) {    // 原来的结点上是否有值，如果为0则表示原来的结点没有值，寻找失败
        return NULL;
    }
    return &m_pTree[nodeIndex];
}

bool Tree::AddNode(int nodeIndex, int direction, int *pNode) {
    // 指定索引，指定方位（左右孩子），指定Node，进行插入
    if ((nodeIndex < 0) || (nodeIndex >= m_iSize)) {
        return false;
    }
    if (m_pTree[nodeIndex] == 0) {   // 需要插入的父结点是否有值，如果父结点无值，则插入失败
        return false;
    }

    // direction 定义0为左，1为右。number是根据direction算出需要插入的位置
    int number = (direction == 0) ? nodeIndex * 2 + 1 : nodeIndex * 2 + 2;
    if (number >= m_iSize) {
        return false;
    }
    if (m_pTree[number] != 0) { // 插入的位置上是否有值，如果不为0，原来位置有值，插入失败
        return false;
    }
    m_pTree[number] = *pNode;


    return true;
}

bool Tree::DeleteNode(int nodeIndex, int *pNode) {
    // 指定结点索引，删除结点
    if ((nodeIndex < 0) || (nodeIndex >= m_iSize)) {
        return false;
    }
    if (m_pTree[nodeIndex] == 0) {
        return false;
    }

    // 取出结点，将原来的结点值重新赋值为0
    *pNode = m_pTree[nodeIndex];
    m_pTree[nodeIndex] = 0;
    return true;
}

void Tree::TreeTraverse() {
    // 遍历树
    for (int i = 0; i < m_iSize; i++) {
        cout << m_pTree[i] << " ";
    }
}
