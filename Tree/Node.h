#ifndef NODE_H
#define NODE_H

#include"stdio.h"
class Node {
  public:
    Node();
    Node *SearchNode(int nodeIndex);	// 用Node.h来代替Tree2.h实现查找过程
    void DeleteNode();			// 用Node.h来代替Tree2.h实现删除操作
    void PreorderTraversal();		// 实现前序遍历
    void InorderTraversal();		// 实现中序遍历
    void PostorderTraversal();		// 实现后序遍历
    int index;
    int data;
    Node *pLChild;
    Node *pRChild;
    Node *pParent;
};

#endif
