#ifndef CMAP_H
#define CMAP_H
#include<vector>
#include"Node.h"
#include"Edge.h"
using namespace std;

class CMap {
  public:
    CMap(int capacity);
    ~CMap();
    bool addNode(Node *pNode);		     // 往图中添加顶点(结点)
    void resetNode();			     // 重置顶点
    bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);   // 为有向图设置邻接矩阵
    bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1); // 为无向图设置邻接矩阵
    void printMatrix();			     // 打印邻接矩阵
    void depthFirstTraverse(int nodeIndex);    // 深度优先遍历
    void breadthFirstTraverse(int nodeIndex);  // 广度优先遍历

    void primTree(int nodeIndex); 	     // 普里姆生成树
    void kruskalTree();			     // 克鲁斯卡尔生成树
    void Dijkstra(int nodeIndex);		     // 迪杰斯特拉最短路径
    void Floyd();				     // 弗洛伊德最短路径

  private:
    bool getValueFromMatrix(int row, int col, int &val);	// 从矩阵中获取权值
    void breadthFirstTraverseImpl(vector<int> preVec);	// 广度优先遍历实现函数
    int getMinEdge(vector<Edge> edgeVec);			// 从当前的边集合中，找出权值最小的边
    bool isInSet(vector<int> nodeSet, int target);	// 判断顶点是否在点集合中
    void mergeNodeSet(vector<int> &nodeSetA, vector<int> nodeSetB); // 合并两个顶点集合

  private:
    int m_iCapacity;	// 图中最多可以容纳的顶点数
    int m_iNodeCount;	// 已经添加的顶点(结点)个数
    Node *m_pNodeArray;	// 存放顶点数组
    int *m_pMatrix;	// 存放邻接矩阵

    Edge *m_pEdge;	// 存放边所连接的两个点和对应的权值
};

#endif
