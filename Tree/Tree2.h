#ifndef TREE2_H
#define TREE2_H
#include"stdio.h"

#include"Node.h"

// 二叉树链表实现
class Tree2 {
  public:
    Tree2();		// 创建树
    ~Tree2();		// 销毁树
    Node *SearchNode(int nodeIndex);	// 搜索结点
    bool AddNode(int nodeIndex, int direction, Node *pNode);	// 添加结点
    bool DeleteNode(int nodeIndex, Node *pNode);			// 删除结点
    void PreorderTraversal();		// 前序遍历
    void InorderTraversal();		// 中序遍历
    void PostorderTraversal();		// 后序遍历
    int MaxDepth();			// 树的最大深度
    int MaxWidth();			// 树的最大宽度
  private:
    int realMaxDepth(Node *pNode);
    int realMaxWidth(Node *pNode);
  private:
    Node *m_pRoot;
};

#endif
