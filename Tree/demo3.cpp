#include <iostream>
#include "BSTree.h"
using namespace std;
int main() {
    BSTree<int> s;
    // int a ;
    cout << "请输入二叉树结点以构造二叉查找树：" << endl;
    // 插入数据
    int a[] = {88, 47, 19, 55, 50, 98};
    for (int i = 0; i < 6; i++) {
        s.insert(a[i]);
    }

    // 遍历二叉树
    cout << "前序遍历二叉查找树:" << endl;
    s.postOrder();
    cout << endl;

    cout << "中序遍历二叉查找树:" << endl;
    s.inOrder();
    cout << endl;

    cout << "后序遍历二叉查找树:" << endl;
    s.postOrder();
    cout << endl;

    cout << "打印二叉查找树" << endl;
    s.print();

    // 查找一个数, 如果找不到就插入
    int a = 10;
    BSTNode<int>* findnode = s.search(a);
    if(!findnode) {
        cout<<"查找失败"<<endl;
        s.insert(a);
        cout<<"已经将"<<a<<"插入二叉查找树,现在二叉查找树为："<<endl;
        s.inOrder();
        cout<<endl;
    } else {
        cout<<findnode->_key<<"查找成功"<<endl;
    }

    // 找一个数的前驱或者后继
    BSTNode<int>* findPreNode= new BSTNode<int>(1, NULL, NULL, NULL);
    findPreNode->_key = 1;

    BSTNode<int>* preNode ;
    if((preNode = s.predecessor(findPreNode)) != NULL) {
        cout << "其前驱结点为：";
        cout << preNode->_key << endl;
    } else
        cout << "没有前驱结点" << endl;

    if((preNode = s.sucessor(findPreNode)) != NULL) {
        cout << "其后继结点为：";
        cout << preNode->_key << endl;
    } else
        cout << "没有后继结点" << endl;

    // 删除一个节点
    int a = 1;
    s.remove(a);
    cout<<"删除后的二叉排序树："<<endl;
    s.print();


    BSTNode<int>* maxNode =  s.minimumNode();
    if(!maxNode)
        cout<<"最小的节点为："<<maxNode->_key<<endl;

    BSTNode<int>* minNode = s.maximumNode();
    if(!minNode)
        cout<<"最大的节点为："<<minNode->_key<<endl;

    cout<<"销毁二叉树"<<endl;
    s.destory();
    s.inOrder();

    system("pause");

    return 0;
}
