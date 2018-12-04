#include<iostream>
#include<stdlib.h>
#include"CMap.h"
#include"Edge.h"
#include<vector>
using namespace std;

/*
 *
 *       A
 *     / | \
 *    B--F--E
 *     \/ \/
 *     C---D
 *
 *  A B C D E F
 *  0 1 2 3 4 5
 *
 *  A-B 6   B-C 3   C-D 7   D-E 2   E-F 9
 *  A-E 5   B-F 2   C-F 8   D-F 4
 *  A-F 1
 *
 * 正确结果
 *
 * A
 * 0----5 1
 * F
 * 5----1 2
 * B
 * 1----2 3
 * C
 * 5----3 4
 * D
 * 3----4 2
 * E

 * 0--5 1
 * 1--5 2
 * 3--4 2
 * 1--2 3
 * 3--5 4
 *
 */

int main(void) {
    CMap *pMap = new CMap(6);

    Node *pNodeA = new Node('A');
    Node *pNodeB = new Node('B');
    Node *pNodeC = new Node('C');
    Node *pNodeD = new Node('D');
    Node *pNodeE = new Node('E');
    Node *pNodeF = new Node('F');

    pMap->addNode(pNodeA);
    pMap->addNode(pNodeB);
    pMap->addNode(pNodeC);
    pMap->addNode(pNodeD);
    pMap->addNode(pNodeE);
    pMap->addNode(pNodeF);

    pMap->setValueToMatrixForUndirectedGraph(0, 1, 6);
    pMap->setValueToMatrixForUndirectedGraph(0, 2, 3);
    pMap->setValueToMatrixForUndirectedGraph(1, 2, 2);
    pMap->setValueToMatrixForUndirectedGraph(1, 3, 5);
    pMap->setValueToMatrixForUndirectedGraph(2, 3, 3);
    pMap->setValueToMatrixForUndirectedGraph(2, 4, 4);
    pMap->setValueToMatrixForUndirectedGraph(3, 4, 2);
    pMap->setValueToMatrixForUndirectedGraph(3, 5, 3);
    pMap->setValueToMatrixForUndirectedGraph(4, 5, 5);

    //pMap->printMatrix();
    pMap->Dijkstra(0);
    pMap->Floyd();

    return 0;
}
