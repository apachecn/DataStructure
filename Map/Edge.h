#ifndef EDGE_H
#define EDGE_H

class Edge {
  public:
    Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0);
    int m_iNodeIndexA;    // 连接的A点
    int m_iNodeIndexB;    // 连接的B点
    int m_iWeightValue;   // 边的权值
    bool m_bSelected;     // 此边是否被选择了，生成最小生成树的时候需要使用

};

#endif
