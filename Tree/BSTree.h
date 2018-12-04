#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_
#include <iostream>
using namespace std;
template<typename T>
//树结点结构
class BSTNode {
  public:
    T _key;                 // 节点值
    BSTNode *_lchild;       // 左孩子
    BSTNode *_rchild;       // 右孩子
    BSTNode *_parent;       // 父节点

    //构造函数
    BSTNode(T key,BSTNode *lchild,BSTNode *rchild,BSTNode *parent):
        _key(key),_lchild(lchild),_rchild(rchild),_parent(parent) {};
};


template<typename T>
class BSTree {
  private:
    BSTNode<T> *_Root ;  //根结点

  public:
    BSTree():_Root(NULL) {};
    ~BSTree() {};


    void insert(T key);    // 插入

    BSTNode<T>* search(T key); //查找

    void preOrder();                    //前序遍历
    void inOrder();                     //中序遍历
    void postOrder();                   //后序遍历

    BSTNode<T>* minimumNode();          //查找最小的节点
    BSTNode<T>* maximumNode();          //查找最大的节点

    T minimumKey();                     //查找最小的键值
    T maximumKey();                     //查找最大的键值

    void print();                       //打印二叉树
    void remove(T key);                 //移除某个节点

    BSTNode<T>* predecessor(BSTNode<T>* x);//查找某个结点的前驱，树中所有数取出之后排序从小到大排序，靠近x左边的数
    BSTNode<T>* sucessor(BSTNode<T>* x);   //查找某个结点的后继，树中所有数取出之后排序从小到大排序，靠近x右边的数

    void destory ();

    //内部使用函数，供外部接口调用
  private:
    void insert(BSTNode<T>* &tree,BSTNode<T>* z);
    BSTNode<T>* search(BSTNode<T>* &tree,T key) const;
    void preOrder(BSTNode<T>*&tree) const;
    void inOrder(BSTNode<T>*&tree) const;
    void postOrder(BSTNode<T>*&tree) const;
    BSTNode<T>* minimumNode(BSTNode<T> *&tree);
    BSTNode<T>* maximumNode (BSTNode<T> *&tree);
    void print(BSTNode<T>*& tree);
    BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T> *z);
    void destory(BSTNode<T>*& tree);
};


// 非递归实现,内部使用函数
template<typename T>
void BSTree<T> ::insert(BSTNode<T>* &tree,BSTNode<T>* z) {
    BSTNode<T>* parent = NULL;
    BSTNode<T>* temp = tree;

    //寻找插入点
    while(temp != NULL) {
        parent = temp;
        // 待插入的值大于当前值，就继续寻找右节点，否则寻找左节点
        temp = (z->_key > temp->_key) ? temp->_rchild : temp->_lchild;
    }

    // 当前节点的父节点为刚刚找到的节点
    z->_parent = parent;
    // 如果树为空树，就直接把节点插入到根节点中；如果小于父节点就为父节点的左节点，否则为右节点
    if (parent == NULL)
        tree = z;
    else if(z->_key > parent->_key)
        parent->_rchild = z;
    else
        parent->_lchild = z;
}

// 接口
template <typename T>
void BSTree<T>::insert(T key) {
    // 创建一个新的节点，使用构造函数初始化
    BSTNode<T>* z= new BSTNode<T>(key, NULL, NULL, NULL);
    if (!z) //如果创建失败就直接返回
        return ;
    //调用内部函数进行插入
    insert(_Root, z);
}

// 非递归实现,内部使用函数
template <typename T>
BSTNode<T>*  BSTree<T>::search(BSTNode<T>* &tree,T key) const {
    BSTNode<T>* temp = tree;
    // 因为是二叉查找树，所以只需要对左或右节点进行遍历
    while(temp != NULL) {
        if (temp->_key == key)
            return temp;
        else if (temp->_key > key)
            temp = temp->_lchild;
        else
            temp = temp->_rchild;
    }
    return NULL;
}
/*//查找算法的递归实现
template<typename T>
BSTNode<T>* BSTree<T>::search( BSTNode<T>* &tree,T key) const
{
    if(!tree)
    {
        if(tree->_key==key)
            return tree;
        if(tree->_key>key)
            return search(tree->_lchild,key);
        if(tree->_key<z->_key)
            return search(tree->_rchild,key);
    }
    return NULL;
}
*/

// 接口
template <typename T>
BSTNode<T> * BSTree<T>::search(T key) {
    return search(_Root,key);
}

// 三种遍历, 内部调用的接口
template<typename T>
void BSTree<T>::preOrder(BSTNode<T>*&tree) const {
    if(tree) {
        cout<<tree->_key<<" ";
        preOrder(tree->_lchild);
        preOrder(tree->_rchild);
    }
}
template <typename T>
void BSTree<T>::inOrder(BSTNode<T>*&tree) const {
    if(tree) {
        inOrder(tree->_lchild);
        cout<<tree->_key<<" ";
        inOrder(tree->_rchild);
    }
}
template <typename T>
void BSTree<T>::postOrder(BSTNode<T>*&tree) const {
    if(tree) {
        postOrder(tree->_lchild);
        postOrder(tree->_rchild);
        cout<<tree->_key<<" ";
    }
}

// 外部调用的接口
template<typename T>
void BSTree<T>::preOrder() {
    preOrder(_Root);
}
template<typename T>
void BSTree<T>::inOrder() {
    inOrder(_Root);
}
template<typename T>
void BSTree<T>::postOrder() {
    postOrder(_Root);
}

// 查找最小的结点，内部调用函数
template <typename T>
BSTNode<T>* BSTree<T>::minimumNode(BSTNode<T>*&tree) {
    BSTNode<T>* temp = tree;
    // 因为左节点小于右节点，所以只需要在左节点进行查找
    while (temp->_lchild) {
        temp= temp->_lchild;
    }
    return temp;
}


// 接口
template<typename T>
BSTNode<T>* BSTree<T>::minimumNode() {
    return minimumNode(_Root);
}

// 查找最大的节点，内部调用函数
template<typename T>
BSTNode<T>* BSTree<T>::maximumNode(BSTNode<T>* &tree) {
    // 因为左节点小于右节点，所以只需要在右节点进行查找
    BSTNode<T>* temp=tree;
    while (temp->_rchild) {
        temp= temp->_rchild;
    }
    return temp;
}

// 接口
template<typename T>
BSTNode<T>* BSTree<T>::maximumNode() {
    return maximumNode(_Root);
}

// 查找最小的节点值，外部接口函数, 调用内部函数minimumNode实现
template<typename T>
T BSTree<T>::minimumKey() {
    BSTNode<T> *temp = minimumNode(_Root);
    return temp->_key;
}

// 查找最大的节点值，外部接口函数, 调用内部函数maximumNode实现
template<typename T>
T BSTree<T>::maximumKey() {
    BSTNode<T> *temp = maximumNode(_Root);
    return temp->_key;
}

// 打印出平衡二叉树
template<typename T>
void BSTree<T>::print(BSTNode<T>*& tree) {
    //如果tree不为空
    if (tree) {
        //结点有左孩子
        if (tree->_lchild) {
            cout << "节点" << tree->_key << "有左孩子为" << tree->_lchild->_key << endl;
        } else {
            cout << "节点" << tree->_key << "无左孩子" << endl;
        }
        if (tree->_rchild) {
            cout << "节点" << tree->_key << "有右孩子为" << tree->_rchild->_key << endl;
        } else {
            cout << "节点" << tree->_key << "无右孩子" << endl;
        }
        print(tree->_lchild);
        print(tree->_rchild);
    }
}

//接口
template<typename T>
void BSTree<T>::print() {
    print(_Root);
}

// 查找某个节点x的前驱, 外部函数调用
template <typename T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T>* x) {

    //如果x是最小的结点，则它没有前驱
    if (x->_key == minimumNode(_Root)->_key)
        return NULL;

    //先获取二叉树中键值与x的键值相同的结点y
    BSTNode<T>* y = NULL;
    y = search(_Root,x->_key);
    if (y == NULL)
        return NULL;

    //如果y有左孩子，则x的前驱为“以x的左孩为根的子树的最大结点”
    if (y->_lchild != NULL)
        return maximumNode(y->_lchild);

    //如果y没有左孩子，则x有两种可能：
    //1.y是一个右孩子，此时x的前驱为其双亲节点
    BSTNode<T>* parent = y->_parent;
    if (parent->_rchild == y)
        return parent;

    //2.y是一个左孩子，则其前驱为其”父结点的父节点中第一个拥有右孩子结点”的结点
    while (parent != NULL && parent->_rchild == NULL) {
        parent = parent->_parent;
    }
    return parent;
}

// 查找某个节点x的后继, 外部调用接口
template <typename T>
BSTNode<T>* BSTree<T>::sucessor(BSTNode<T>* x) {
    //如果x是键值最大的，则x没有后继结点
    if (x->_key == maximumNode(_Root)->_key)
        return NULL;

    //获取x在二叉树中的结点y
    BSTNode<T>* y = NULL;
    y = search(_Root,x->_key);
    if (!y)              //若二叉树没有此结点
        return NULL;

    //如果y有右孩子，则y的后继为其右孩子的最小结点
    if (y->_rchild != NULL)
        return minimumNode(y->_rchild);

    //如果y没有右孩子，则可分为两种情况：
    //1.y 是左孩子。此时y的后继为y的父结点
    BSTNode <T>* parent = y->_parent;
    if (y->_parent->_lchild == y)
        return parent;

    //2.y是右孩子。此时y的后继结点为“它的父节点的父节点中第一个拥有左孩”的结点
    while (parent!=NULL) {
        if (parent->_lchild != NULL && parent != y->_parent)
            return parent;
        parent = parent->_parent;
    }
    return NULL;
}

// 删除结点, BSTree类内部调用函数
template <class T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T>* &tree, BSTNode<T> *z) {

    /* 将待删除节点命名为z
    * 情况一：如果z为叶子节点(没有左子树和没有右子树)，那么就可以直接删除该节点再修改其父节点的指针
    * 情况二：如果z为单支节点(只有左子树或者只有右子树), 那么就让z的子树连接z的父节点,再删除z
    * 情况三：如果z左右子树均不为空。找到z的后继y(y一定没有左子树),所以可以删除y, 让y的父节点成为y的右子树的父节点，用y代替z
    */

    BSTNode<T> *y=NULL;
    BSTNode<T> *zl = z->_lchild;
    BSTNode<T> *zr = z->_rchild;
    BSTNode<T> *zpl = z->parent->_lchild;
    BSTNode<T> *zpr = z->parent->_rchild;


    // 情况一
    if (zl == NULL && zr == NULL) {
        if (zpl == z)
            zpl = NULL;
        if (zpr == z)
            zpr = NULL;
        return z;
    }
    // 情况二
    if (zl == NULL || zr == NULL) {
        if (zpl == z)
            zpl = (zl != NULL) ? zl : zr;
        if (zpr == z)
            zpr = (zl != NULL) ? zl : zr;
        return z;
    }
    // 情况三
    if (zl != NULL && zr != NULL) {
        y = sucessor(z);
        z->_key = y->_key;
        if (y->_parent->_lchild == y)
            y->_parent->_lchild = NULL;
        if (y->_parent->_rchild == y)
            y->_parent->_rchild = NULL;
        return y;
    }
}

// 接口
template<typename T>
void BSTree<T>::remove(T key) {
    BSTNode<T> *z, *node;
    if ((z = search(_Root, key)) != NULL)
        if ((node = remove(_Root, z)) != NULL)
            delete node;
}

// 销毁查找二叉树, 内部调用函数
template<typename T>
void BSTree<T>::destory(BSTNode<T>*& tree) {
    if(tree->_lchild != NULL)
        destory(tree->_lchild);
    if(tree->_rchild != NULL)
        destory(tree->_rchild);
    if(tree->_lchild == NULL && tree->_rchild == NULL) {
        delete(tree);
        tree = NULL;
    }
}

// 接口
template<typename T>
void BSTree<T>::destory() {
    destory(_Root);
}
#endif
