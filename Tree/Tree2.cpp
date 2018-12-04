#include"Tree2.h"
#include<iostream>
#include<string.h>
#include<vector>
#include"Node.h"
using namespace std;


Tree2::Tree2() {
    m_pRoot = new Node();
}


Tree2::~Tree2() {
    // DeleteNode(0, NULL);
    m_pRoot->DeleteNode();
}

Node *Tree2::SearchNode(int nodeIndex) {
    return m_pRoot->SearchNode(nodeIndex);
}

bool Tree2::AddNode(int nodeIndex, int direction, Node *pNode) {
    // 指定结点索引，指定方向（左右结点），指定元素，插入元素
    Node *temp = SearchNode(nodeIndex);	// 需要判断插入位置的父结点是否存在
    if (temp == NULL) {
        return false;
    }

    // 定义一个新node变量存储需要插入的pNode
    Node *node = new Node();
    node->index = pNode->index;
    node->data = pNode->data;
    node->pParent = temp;

    // direction为0表示插入到左边，为1表示插入到右边
    if (direction == 0) {
        temp->pLChild = node;
    }

    if (direction == 1) {
        temp->pRChild = node;
    }

    return true;
}


bool Tree2::DeleteNode(int nodeIndex, Node *pNode) {
    // 指定结点索引，删除结点
    Node *temp = SearchNode(nodeIndex);	// 找到需要删除结点
    if (temp == NULL) {
        return false;
    }

    if (pNode != NULL) {		// 将删除结点的值传给pNode->data
        pNode->data = temp->data;
    }

    temp->DeleteNode();			// 进行删除结点（同时删除了其所有的子结点）

    return true;
}

void Tree2::PreorderTraversal() {
    m_pRoot->PreorderTraversal();		// 前序遍历
}


void Tree2::InorderTraversal() {
    m_pRoot->InorderTraversal();		// 中序遍历
}

void Tree2::PostorderTraversal() {
    m_pRoot->PostorderTraversal();	// 后序遍历
}

int Tree2::MaxDepth() {
    int depth = realMaxDepth(m_pRoot);
    return depth;
}

int Tree2::realMaxDepth(Node *pNode) {
    if (!pNode) {
        return 0;
    }
    //cout << pNode->pLChild->index;
    int lDepth = realMaxDepth(pNode->pLChild);
    int rDepth = realMaxDepth(pNode->pRChild);

    return lDepth > rDepth ? lDepth + 1:rDepth + 1;
}

int Tree2::MaxWidth() {
    int width = realMaxWidth(m_pRoot);
    return width;
}

int Tree2::realMaxWidth(Node *pNode) {
    if (pNode != NULL) {
        //Node *temp = new Node();
        //Node *temp = pNode;
        vector<Node*> vec;
        vec.push_back(pNode);
        int MaxWidth = 1;
        int LastWidth = 1;
        int CurWidth = 0;
        while ((int)vec.size() > 0) {
            while (LastWidth > 0) {
                Node* temp_node = vec[0];
                vec.erase(vec.begin());
                if (temp_node->pLChild != NULL) {
                    vec.push_back(temp_node->pLChild);
                }
                if (temp_node->pRChild != NULL) {
                    vec.push_back(temp_node->pRChild);
                }
                LastWidth--;
            }
            LastWidth = (int)vec.size();
            CurWidth = (int)vec.size();
            MaxWidth = CurWidth > MaxWidth ? CurWidth : MaxWidth;
        }
        return MaxWidth;
    }

    return 0;
}
