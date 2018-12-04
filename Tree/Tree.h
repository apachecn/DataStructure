#ifndef TREE_H
#define TREE_H
#include<stdio.h>

class Tree {
  public:
    Tree(int size, int *pRoot);
    ~Tree();
    int *SearchNode(int nodeIndex);             //根据索引寻找结点
    bool AddNode(int nodeIndex, int direction, int *pNode);     // 添加结点
    bool DeleteNode(int nodeIndex, int *pNode); // 删除结点
    void TreeTraverse();                        // 遍历结点

  private:
    int *m_pTree;
    int m_iSize;
};

#endif
