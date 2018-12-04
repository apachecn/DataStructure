#include<iostream>
#include<stdlib.h>
#include"Tree2.h"
#include"Node.h"
#include<vector>
#include<algorithm>
using namespace std;

// 0 5 8  2 6 9 7

int main(void) {
    Node *node1 = new Node();
    node1->index = 1;
    node1->data = 5;

    Node *node2 = new Node();
    node2->index = 2;
    node2->data = 8;

    Node *node3 = new Node();
    node3->index = 3;
    node3->data = 2;

    Node *node4 = new Node();
    node4->index = 4;
    node4->data = 6;

    Node *node5 = new Node();
    node5->index = 5;
    node5->data = 9;

    Node *node6 = new Node();
    node6->index = 6;
    node6->data = 7;

    Tree2 *tree = new Tree2();


    tree->AddNode(0, 0, node1);
    tree->AddNode(0, 1, node2);
    tree->AddNode(1, 0, node3);
    tree->AddNode(1, 1, node4);
    tree->AddNode(2, 0, node5);
    tree->AddNode(2, 1, node6);

    //tree->DeleteNode(6, NULL);

    /*
    cout << "前序：" << endl;
    tree->PreorderTraversal();

    cout << "中序：" << endl;
    tree->InorderTraversal();

    cout << "后序: " << endl;
    tree->PostorderTraversal();
    */
    //Node *node0 =
//  cout << tree->MaxDepth();
    cout << tree->MaxWidth() << endl;
    delete tree;

    return 0;
}
