#include"Node.h"
#include<iostream>
#include"stdio.h"
using namespace std;

Node::Node() {
    // 进行初始化
    index = 0;
    data = 0;
    pLChild = NULL;
    pRChild = NULL;
    pParent = NULL;
}

Node *Node::SearchNode(int nodeIndex) {
    // 指定结点位置获取结点

    // 如果是当前结点，则返回当前结点
    if (this->index == nodeIndex) {
        return this;
    }

    // 如果左右孩子存在，那么继续对左右孩子进行搜索
    Node *temp = NULL;
    if (this->pLChild != NULL) {
        // 如果是当前孩子结点，则返回当前孩子结点，否则进行以当前孩子结点为结点继续进行搜索，这里调用了递归
        if (this->pLChild->index == nodeIndex) {
            return this->pLChild;
        } else {
            temp = this->pLChild->SearchNode(nodeIndex);
            // 如果找了结点，就是temp
            if (temp != NULL) {
                return temp;
            }
        }
    }

    // 同上
    if (this->pRChild != NULL) {
        if (this->pRChild->index == nodeIndex) {
            return this->pRChild;
        } else {
            temp = this->pRChild->SearchNode(nodeIndex);
            return temp;
        }
    }
    // 没有找到则返回NULL
    return NULL;
}


void Node::DeleteNode() {
    // 删除左右孩子结点，如果不为空的话，这里调用了递归，不断删除孩子结点
    if (this->pLChild != NULL) {
        this->pLChild->DeleteNode();
    }

    if (this->pRChild != NULL) {
        this->pRChild->DeleteNode();
    }

    // 令自己为NULL，首先需要知道自己是父结点的左还是右孩子。
    if (this->pParent != NULL) {
        if (this->pParent->pLChild == this) {
            this->pParent->pLChild = NULL;
        }
        if (this->pParent->pRChild == this) {
            this->pParent->pRChild = NULL;
        }
    }

    // 删除自己
    delete this;
}


void Node::PreorderTraversal() {
    // 前序遍历。先输出自己，再遍历左孩子，输出左孩子，再遍历右孩子，输出右孩子
    cout << this->index << "   "  << this->data << endl;
    if (this->pLChild != NULL) {
        this->pLChild->PreorderTraversal();
    }

    if (this->pRChild != NULL) {
        this->pRChild->PreorderTraversal();
    }
}

void Node::InorderTraversal() {
    // 中序遍历。先遍历左孩子，输出左孩子，再遍历右孩子，输出右孩子
    if (this->pLChild != NULL) {
        this->pLChild->InorderTraversal();
    }

    cout << this->index << "   "  << this->data << endl;

    if (this->pRChild != NULL) {
        this->pRChild->InorderTraversal();
    }
}

void Node::PostorderTraversal() {
    // 后序遍历。先遍历左孩子，再遍历右孩子，输出右孩子，输出左孩子
    if (this->pLChild != NULL) {
        this->pLChild->PostorderTraversal();
    }

    if (this->pRChild != NULL) {
        this->pRChild->PostorderTraversal();
    }

    cout << this->index << "   "  << this->data << endl;

}
