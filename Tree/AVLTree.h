#ifndef __AVLTREE_H__
#define __AVLTREE_H__
#include <stdlib.h>
#include <iostream>
using namespace std;

struct AVLNode {
    int _key;
    AVLNode* _lchild;
    AVLNode* _rchild;
    AVLNode* _parent;
    int nHeight;
};

class AVLTree {
  public:
    AVLTree() : _Root(NULL), nNodeCount(0) {}
    ~AVLTree() {
        DeleteTree(&_Root);
    }
  public:
    int Insert(int _key);          // 插入节点
    int Delete(int _key);          // 删除节点
    int Find(int _key) const;      // 查找节点
    int GetNodeCount() const;       // 获取总共的节点数
    void Display() const;           // 打印AVL树

  private:
    int Max(int a, int b) const;    // 用于比较获取最大的节点
    int Height(const AVLNode* pNode) const; // 获取AVL树的高度
    AVLNode* CreateNode(int _key);         // 构造新节点
    AVLNode* DeleteNode(int _key, AVLNode* pNode);     // 删除节点
    AVLNode* BalanceAdjust(AVLNode* pNode);     // 平衡二叉树
    AVLNode* RotateLeft(AVLNode* pNode);        // 左旋
    AVLNode* RotateRight(AVLNode* pNode);       // 右旋
    AVLNode* RotateLeftRight(AVLNode* pNode);   // 左右旋
    AVLNode* RotateRightLeft(AVLNode* pNode);   // 右左旋
    void DeleteTree(AVLNode** p_Root);          // 删除树
    void PrintTree(AVLNode* pNode) const;       // 打印AVL树

    AVLTree(const AVLTree&) {}
    AVLTree& operator=(const AVLTree&) {}

  private:
    AVLNode* _Root;
    int nNodeCount;
};

int AVLTree::Max(int a, int b) const {
    // 返回两个数大的那个数
    return (a > b ? a : b);
}

int AVLTree::Height(const AVLNode* pNode) const {
    if (NULL == pNode)
        return -1;

    return pNode->nHeight;
}

int AVLTree::Insert(int _key) {
    // 如果树不存在，就构造树
    if(_Root == NULL) {
        _Root = CreateNode(_key);
        return nNodeCount;
    }

    AVLNode* pInsertNode = _Root;
    // 遍历树直到到叶子节点为止
    while (pInsertNode != NULL) {
        // 如果待插入的数小于当前节点，就遍历左边
        if (_key < pInsertNode->_key) {
            // 如果当前节点的左节点为NULL, 就将待插入的数放入到当前节点的左节点
            if (pInsertNode->_lchild == NULL) {
                pInsertNode->_lchild = CreateNode(_key);
                pInsertNode->_lchild->_parent = pInsertNode;
                // 平衡树
                _Root = BalanceAdjust(pInsertNode->_lchild);
                break;
            }
            // 如果当前节点的左节点不为NULL, 就继续向当前节点的左节点遍历
            pInsertNode = pInsertNode->_lchild;
        }
        // 如果待插入的数大于当前节点，就遍历右边
	if (_key > pInsertNode->_key) {
            // 基本步骤同上
            if (pInsertNode->_rchild == NULL) {
                pInsertNode->_rchild = CreateNode(_key);
                pInsertNode->_rchild->_parent = pInsertNode;
                _Root = BalanceAdjust(pInsertNode->_rchild);
                break;
            }
            pInsertNode = pInsertNode->_rchild;
        }
        // 如果待插入的节点等于当前节点，就不进行插入
	if (_key == pInsertNode->_key) {
            return nNodeCount;
        }
    }

    return nNodeCount;
}

int AVLTree::Delete(int _key) {
    //cout << "Delete _key = " << _key << endl;
    //cout << "pNode->_key = " << pNode->_key << endl;
    //cout << "pPNode->_key = " << pPNode->_key << endl;

    AVLNode* pCurNode = _Root;
    // 如果当前节点不为NULL, 开始进行查找
    while(pCurNode != NULL) {
        // 如果需要删除的数大于当前节点值，就继续向左节点搜索
        if (_key > pCurNode->_key)
            pCurNode = pCurNode->_rchild;
        // 如果需要删除的数小于当前节点值，就继续向右节点搜索
	if (_key < pCurNode->_key)
            pCurNode = pCurNode->_lchild;
        // 如果需要删除的数等于当前节点值，则删除当前节点
        if (_key == pCurNode->_key)
            _Root = DeleteNode(_key, pCurNode);
            break;
    }

    // 如果当前节点遍历到最后，没有找到该元素，则进行输出
    if (pCurNode == NULL)
        cout << "没有找到元素 _key = " << _key << endl;
    // int x;
    // cin >> x;
    // 没有找到要删除的元素
    return nNodeCount;
}

AVLNode* AVLTree::DeleteNode(int _key, AVLNode* pNode) {
    // 首先减少树的节点个数
    nNodeCount--;

    // 如果删除的节点有左右子树
    if (pNode->_lchild && pNode->_rchild) {
        // 从删除节点的左子树中，找出最大的节点代替删除节点
        AVLNode* pLMaxNode = pNode->_lchild;
        // 删除节点左子树中最大节点的父节点
	AVLNode* pLMaxPNode = pNode;
        // 如果删除节点的左节点不存在右节点
        if (pLMaxNode->_rchild == NULL) {
            // 可以直接将这个节点换为待删除节点
            pNode->_key = pLMaxNode->_key;
            pNode->_lchild = pLMaxNode->_lchild;
            // 将待删除节点的左节点的左子树，全部重新衔接到当前待删除节点（删除节点的左节点需要删除）
            if (pLMaxNode->_lchild != NULL)
                pLMaxNode->_lchild->_parent = pNode;
            // 如果删除节点的左节点存在右节点，就在右节点的子树搜索
        } else {
            // 一直搜索找到没有右子树为止(存储节点的父节点)，即找到最大节点
            while (pLMaxNode->_rchild) {
                pLMaxPNode = pLMaxNode;
                pLMaxNode = pLMaxNode->_rchild;
            }
            // 将待删除节点的值改为找到的最大节点的值
            pNode->_key = pLMaxNode->_key;

            // 找到最大节点为父节点的左节点还是右节点，如果是右节点就将最大节点的子树接到最大节点的父节点上
            if (pLMaxNode == pLMaxPNode->_rchild)
                pLMaxPNode->_rchild = pLMaxNode->_lchild;
            // 如果是左节点，它已经是叶子节点了，就将这个节点赋值为NULL
            else if (pLMaxNode == pLMaxPNode->_lchild)
                pLMaxPNode->_lchild = NULL;
        }
        // 删除最大节点
        delete pLMaxNode;
        return BalanceAdjust(pLMaxPNode);
        // 如果删除的节点只有左节点
    } else if (pNode->_lchild) {
        // 删除节点的左子树
        AVLNode* _lchild = pNode->_lchild;
        pNode->_key = _lchild->_key;

        // 将左子树的左节点赋值为待删除节点的左节点
        pNode->_lchild = _lchild->_lchild;
        // 如果左子树的左节点存在，那么左节点赋值为待删除节点
        if (_lchild->_lchild)
            _lchild->_lchild->_parent = pNode;

        // 将左子树的右节点赋值为待删除节点的右节点
        pNode->_rchild = _lchild->_rchild;
        // 如果左子树的右节点存在，那么就将右节点赋值为待删除节点
        if (_lchild->_rchild)
            _lchild->_rchild->_parent = pNode;

        delete _lchild;

        return BalanceAdjust(pNode);
    // 删除节点只有右子树
    } else if (pNode->_rchild) {
        AVLNode* _rchild = pNode->_rchild;

        pNode->_key = _rchild->_key;

        pNode->_lchild = _rchild->_lchild;
        if (_rchild->_lchild != NULL)
            _rchild->_lchild->_parent = pNode;

        pNode->_rchild = _rchild->_rchild;
        if (_rchild->_rchild != NULL)
            _rchild->_rchild->_parent = pNode;

        delete _rchild;

        return BalanceAdjust(pNode);
    //删除节点没有子树
    } else { 
	AVLNode* pPNode = pNode->_parent;
        if (pPNode->_lchild == pNode)
            pPNode->_lchild = NULL;
        else if (pPNode->_rchild == pNode)
            pPNode->_rchild = NULL;

        delete pNode;

        return BalanceAdjust(pPNode);
    }
}

AVLNode* AVLTree::BalanceAdjust(AVLNode* pNode) {
    AVLNode* _Root;
    AVLNode* pPNode;

    while(pNode != NULL) { //删除节点的子节点进行平衡
        pPNode = pNode->_parent;

        bool bIsLeft = false;
        if(pPNode != NULL && pNode == pPNode->_lchild)
            bIsLeft = true;

        pNode->nHeight = Max(Height(pNode->_lchild), Height(pNode->_rchild)) + 1;

        if (Height(pNode->_lchild) - Height(pNode->_rchild) == 2) {  // AVL树不平衡  执行LL型或者LR型旋转
            if (Height(pNode->_lchild->_lchild) - Height(pNode->_lchild->_rchild) == -1)
                pNode = RotateLeftRight(pNode);
            else
                pNode = RotateLeft(pNode);

            if(pPNode != NULL && bIsLeft)
                pPNode->_lchild = pNode;
            else if(pPNode != NULL)
                pPNode->_rchild = pNode;
        } else if(Height(pNode->_lchild) - Height(pNode->_rchild) == -2) { // AVL树不平衡  执行RR型或者RL型旋转
            if (Height(pNode->_rchild->_lchild) - Height(pNode->_rchild->_rchild) == 1)
                pNode = RotateRightLeft(pNode);
            else
                pNode = RotateRight(pNode);

            if (pPNode != NULL && bIsLeft)
                pPNode->_lchild = pNode;
            else if(pPNode != NULL)
                pPNode->_rchild = pNode;
        }

        _Root = pNode;
        pNode = pPNode;
    }

    return _Root;
}

AVLNode* AVLTree::CreateNode(int _key) {
    nNodeCount++;

    AVLNode* pNewNode = new AVLNode();
    pNewNode->_key = _key;
    pNewNode->nHeight = 0;
    pNewNode->_lchild = pNewNode->_rchild = NULL;

    return pNewNode;
}

int AVLTree::Find(int _key) const {
    AVLNode* pFindNode = _Root;
    while(pFindNode) {
        if(_key < pFindNode->_key)
            pFindNode = pFindNode->_lchild;
        else if(_key > pFindNode->_key)
            pFindNode = pFindNode->_rchild;
        else
            return pFindNode->_key;
    }

    return -1;
}

AVLNode* AVLTree::RotateLeft(AVLNode* pNode) { //左单
    AVLNode* _lchildChild;

    _lchildChild = pNode->_lchild;
    pNode->_lchild = _lchildChild->_rchild;
    _lchildChild->_rchild = pNode;

    _lchildChild->_parent = pNode->_parent;
    pNode->_parent = _lchildChild;

    if(pNode->_lchild)
        pNode->_lchild->_parent = pNode;

    // 结点的位置改变,节点高度要重新计算
    pNode->nHeight = Max(Height(pNode->_lchild), Height(pNode->_rchild)) + 1;
    _lchildChild->nHeight = Max(Height(_lchildChild->_lchild), pNode->nHeight) + 1;

    return _lchildChild;
}

AVLNode* AVLTree::RotateRight(AVLNode* pNode) { //右单
    AVLNode* _rchildChild;

    _rchildChild = pNode->_rchild;
    pNode->_rchild = _rchildChild->_lchild;
    _rchildChild->_lchild = pNode;

    _rchildChild->_parent = pNode->_parent;
    pNode->_parent = _rchildChild;

    if(pNode->_rchild)
        pNode->_rchild->_parent = pNode;

    // 结点的位置改变,节点高度要重新计算
    pNode->nHeight = Max(Height(pNode->_lchild), Height(pNode->_rchild)) + 1;
    _rchildChild->nHeight = Max(Height(_rchildChild->_rchild), pNode->nHeight) + 1;

    return _rchildChild;
}

AVLNode* AVLTree::RotateLeftRight(AVLNode* pNode) { //左双
    pNode->_lchild = RotateRight(pNode->_lchild);

    return RotateLeft(pNode);
}

AVLNode* AVLTree::RotateRightLeft(AVLNode* pNode) { //右双
    pNode->_rchild = RotateLeft(pNode->_rchild);

    return RotateRight(pNode);
}

// 后序遍历树以删除树
void AVLTree::DeleteTree(AVLNode** p_Root) {
    if (NULL == p_Root || NULL == *p_Root)
        return;

    DeleteTree(&((*p_Root)->_lchild));
    DeleteTree(&((*p_Root)->_rchild));
    delete *p_Root;
    *p_Root = NULL;
}

int AVLTree::GetNodeCount() const {
    return nNodeCount;
}

void AVLTree::Display() const {
    PrintTree(this->_Root);
}

void AVLTree::PrintTree(AVLNode* pNode) const {
    if (NULL == _Root)
        return;

    if (NULL == pNode) {
        return;
    }

    static int n = 0;

    if(pNode == _Root) {
        std::cout << "[" << ++n << "]_key = " << pNode->_key << ",nParentData= 0 ,";

        if(pNode->_lchild)
            std::cout << "nLeftData= " << pNode->_lchild->_key << " ,";
        if(pNode->_rchild)
            std::cout << "nRightData= " << pNode->_rchild->_key << " ,";

        std::cout << "nHeight = " << pNode->nHeight << std::endl;
    } else {
        std::cout << "[" << ++n << "]_key = " << pNode->_key << ",nParentData= " << pNode->_parent->_key << " ,";

        if(pNode->_lchild)
            std::cout << "nLeftData= " << pNode->_lchild->_key << " ,";
        if(pNode->_rchild)
            std::cout << "nRightData= " << pNode->_rchild->_key << " ,";

        std::cout << "nHeight = " << pNode->nHeight << std::endl;
    }
    PrintTree(pNode->_lchild);
    PrintTree(pNode->_rchild);
}
#endif        //__AVLTREE_H__
