#include<iostream>
#include<stdlib.h>
#include"CMap.h"
using namespace std;

/*
 * 图例：
 *         A
 *        / \
 *       B   D
 *      / \ / \
 *     C  F G-H
 *      \ /
 *       E
 *
 *    A B C D E F G H
 * A    1   1
 * B  1   1     1
 * C    1     1 1
 * D  1           1 1
 * E      1
 * F    1 1
 * G        1       1
 * H        1     1
 *
 * 正确结果
 *
 * 深度优先遍历
 * A B C E F D G H
 * 广度优先遍历
 * A B D C F G H E
 */


int main(void) {
    CMap *pMap = new CMap(8);

    Node *pNodeA = new Node('A');
    Node *pNodeB = new Node('B');
    Node *pNodeC = new Node('C');
    Node *pNodeD = new Node('D');
    Node *pNodeE = new Node('E');
    Node *pNodeF = new Node('F');
    Node *pNodeG = new Node('G');
    Node *pNodeH = new Node('H');

    pMap->addNode(pNodeA);
    pMap->addNode(pNodeB);
    pMap->addNode(pNodeC);
    pMap->addNode(pNodeD);
    pMap->addNode(pNodeE);
    pMap->addNode(pNodeF);
    pMap->addNode(pNodeG);
    pMap->addNode(pNodeH);

    pMap->setValueToMatrixForUndirectedGraph(0, 1);
    pMap->setValueToMatrixForUndirectedGraph(0, 3);
    pMap->setValueToMatrixForUndirectedGraph(1, 2);
    pMap->setValueToMatrixForUndirectedGraph(1, 5);
    pMap->setValueToMatrixForUndirectedGraph(3, 6);
    pMap->setValueToMatrixForUndirectedGraph(3, 7);
    pMap->setValueToMatrixForUndirectedGraph(6, 7);
    pMap->setValueToMatrixForUndirectedGraph(2, 4);
    pMap->setValueToMatrixForUndirectedGraph(4, 5);

    pMap->printMatrix();

    cout << "深度优先遍历" << endl;

    pMap->depthFirstTraverse(0);

    cout << endl;
    pMap->resetNode();

    cout << "广度优先遍历" << endl;

    pMap->breadthFirstTraverse(0);

    return 0;
}
