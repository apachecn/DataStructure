#include"CMap.h"
#include"Edge.h"
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

CMap::CMap(int capacity) {
    m_iCapacity = capacity;
    m_iNodeCount = 0;
    m_pNodeArray = new Node[m_iCapacity];
    m_pMatrix = new int[m_iCapacity * m_iCapacity]; // 这里是一维数组
    memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));
    // 或者使用下面的方法
    /*
     * for (int i = 0; i < m_iCapacity * m_iCapacity; i++)
     * {
     *   m_pMatrix[i] = 0;
     * }
     */
    m_pEdge = new Edge[m_iCapacity - 1];
}

CMap::~CMap() {
    delete []m_pNodeArray;
    delete []m_pMatrix;
    delete []m_pEdge;
}

bool CMap::addNode(Node *pNode) {
    if (pNode == NULL) {
        return false;
    }
    m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;  // 传递数据
    m_iNodeCount++;
    return true;
}

void CMap::resetNode() {
    // 重置结点，所有的结点都设置为未被访问
    for (int i = 0; i < m_iNodeCount; i++) {
        m_pNodeArray[i].m_bIsVisted = false;
    }
}

bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val) {
    // 检验传入的row和col是否在范围
    if ((row < 0 ) || (row >= m_iCapacity) || (col < 0 ) || (col >= m_iCapacity)) {
        return false;
    }
    // 向有向图中设置权值。因为是有向图，所以ab点的权值可能与ba点的权值不同。所以只需要设置一遍。由于是一维数组，所以可以抽象的理解每m_iCapacity为一行，使用了如下的赋值方式
    m_pMatrix[row * m_iCapacity + col] = val;
    return true;
}

bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val) {
    if ((row < 0 ) || (row >= m_iCapacity) || (col < 0 ) || (col >= m_iCapacity)) {
        return false;
    }
    // 向无向图中设置权值。因为是无向图，所以ab两点权值等于ba两点之前的权值。所以每次需要向两个地方同时进行赋值。
    m_pMatrix[row * m_iCapacity + col] = val;
    m_pMatrix[col * m_iCapacity + row] = val;
    return true;
}

bool CMap::getValueFromMatrix(int row, int col, int &val) {
    // 指定row和col，进行取值
    val = m_pMatrix[row * m_iCapacity + col];
    return true;
}

void CMap::printMatrix() {
    // 这里使用两个循环格式化输出。换行输出。
    for (int i = 0; i < m_iCapacity; i++) {
        for (int k = 0; k < m_iCapacity; k++) {
            cout << m_pMatrix[i * m_iCapacity + k] << " ";
        }
        cout << endl;
    }
}

void CMap::depthFirstTraverse(int nodeIndex) {
    // 深度优先搜索
    int value = 0;

    // 打印当前传入索引的结点
    cout << m_pNodeArray[nodeIndex].m_cData << " ";
    m_pNodeArray[nodeIndex].m_bIsVisted = true;	// 设置已访问该结点

    // 通过邻接矩阵判断是否与其他顶点有连接
    for (int i = 0; i < m_iCapacity; i++) {
        getValueFromMatrix(nodeIndex, i, value);    // 遍历从当前节点到图中每个节点，取出对应的权值
        if ((value != 0) && (!m_pNodeArray[i].m_bIsVisted)) { // 两点之间有连接且未被访问过
            depthFirstTraverse(i);			// 满足条件，继续搜索。存在连接（弧）且未被访问过
        }                          			// 如果没有去向索引为i的顶点的弧，则循环继续。即这一点不与当前要查找的点有连接（弧）
    }
}

void CMap::breadthFirstTraverse(int nodeIndex) {
    // 广度优先遍历
    cout << m_pNodeArray[nodeIndex].m_cData << " "; // 打印起始结点
    m_pNodeArray[nodeIndex].m_bIsVisted = true;     // 设置已经访问过该结点

    vector<int> curVec;				  // 该层的节点（起始节点），用curVec存储
    curVec.push_back(nodeIndex);

    breadthFirstTraverseImpl(curVec);		  // 广搜的主要代码,将该层节点传入
}

void CMap::breadthFirstTraverseImpl(vector<int> preVec) {
    int value = 0;
    vector<int> curVec;
    // preVec:上一层的所有结点
    for (int j = 0; j < (int)preVec.size(); j++) {  // 遍历上一层的所有节点到当前层所有节点
        for (int i = 0; i < m_iCapacity; i++) {
            getValueFromMatrix(preVec[j], i, value);    // 从上一层的节点到图中的所有节点,取出对应的权值
            if ((value != 0) && (!m_pNodeArray[i].m_bIsVisted)) { // 存在连接，且没有被访问过
                cout << m_pNodeArray[i].m_cData << " "; // 输出当前节点的值
                m_pNodeArray[i].m_bIsVisted = true;     // 并将此点设置为已经访问过了
                curVec.push_back(i);			// 此点加入到当前层的节点中
            }
        }
    }

    // 使用vector的size方法的时候，如果不使用int转换为整型，微软的编译器会报warning，Linux上的g++不会
    if ((int)curVec.size() == 0) {		  // 如果当前层已经不存在节点，则说明遍历完成，否则继续进行遍历
        // 返回空，即返回调用函数处
        return ;
    } else {
        breadthFirstTraverseImpl(curVec);
    }
}

// 普利姆最小生成树
void CMap::primTree(int nodeIndex) {
    int value = 0;
    int edgeCount = 0;    // 当前最小生成树的边数
    vector<int> nodeVec;  // 存放已经遍历的点集合
    vector<Edge> edgeVec; // 存放权值最小的边集合

    cout << m_pNodeArray[nodeIndex].m_cData << endl;  // 输出起始节点
    nodeVec.push_back(nodeIndex);			    // 放入起始节点
    m_pNodeArray[nodeIndex].m_bIsVisted = true;	    // 设置已经被选择过了

    // 当最小生成树的边数小于所有的点数减１，此时最小生成树构造完成
    while (edgeCount < m_iCapacity - 1) {
        int temp = nodeVec.back();   // 取出nodeVec中最后一个元素,上一个遍历的节点

        for (int i = 0; i < m_iCapacity; i++) { // 遍历上一个节点到图中所有的节点
            getValueFromMatrix(temp, i, value);
            if ((value != 0) && (!m_pNodeArray[i].m_bIsVisted)) { // 两点间有连接且未被访问过
                Edge edge(temp, i, value);      // 构造一个边的对象
                edgeVec.push_back(edge);        // 将对象放入"被选边集合"中
            }
        }

        // 从上面找到的可选边集合中找出最小的边，并更改边的状态
        int edgeIndex = getMinEdge(edgeVec);
        edgeVec[edgeIndex].m_bSelected = true;

        // 打印从A节点到B节点,及对应边的权值
        cout << edgeVec[edgeIndex].m_iNodeIndexA << "----" << edgeVec[edgeIndex].m_iNodeIndexB << " " << edgeVec[edgeIndex].m_iWeightValue << " ";

        // 找出当前这一条边连接的另一个点
        int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;

        nodeVec.push_back(nextNodeIndex);  // 将找到的点放入点集合中
        m_pNodeArray[nextNodeIndex].m_bIsVisted = true; // 同时，标记此点已被选择

        cout << m_pNodeArray[nextNodeIndex].m_cData << endl;  // 打印边连接的另一个点

        edgeCount++; // 找到的点数加1
    }
}

int CMap::getMinEdge(vector<Edge> edgeVec) {
    // 从边集合中找到没有被选过的权值最小的边，返回对应边的索引

    int INT_MAX = 2147483647; // 整型变量的最大值
    int minWeight = INT_MAX;  // 设定一个最小权值,应该为最大值
    int edgeIndex = 0;        // 最小权值对应边的索引

    for (int i = 0; i < (int)edgeVec.size(); i++) {
        if ((!edgeVec[i].m_bSelected) && (minWeight > edgeVec[i].m_iWeightValue)) {
            minWeight = edgeVec[i].m_iWeightValue;
            edgeIndex = i;
        }
    }

    // 如果所有的边都被选择过了，则最小权值为初始设定的值
    if (minWeight == INT_MAX) {
        cout << minWeight << endl;
        return -1;
    }

    return edgeIndex;
}

// 克鲁斯卡尔最小生成树
void CMap::kruskalTree() {
    /*
     * 定义存放结点集合的数组
     *
     * 1. 取出所有边
     * 2. 从所有边中取出组成最小生成树的边
     *    1. 找到算法结束条件————边数等于点数-1
     *    2. 从边集合中找到最小边
     *    3. 找出最小边连接的点
     *    4. 找出点所在的点集合
     *    5. 根据点所在集合的不同做出不同的处理　
     *
     */

    int value = 0;
    int edgeCount = 0;

    vector<vector<int> > nodeSets;      // 定义存放结点集合的二维数组，第一维存放点集合，第二维存放点集合中并入的点集合
    vector<Edge> edgeVec;  		      // 定义存放边的集合

    // 取出所有边，只要邻接矩阵的右上角部分
    for (int i = 0; i < m_iCapacity; i++) {
        for (int k = i + 1; k < m_iCapacity; k++) {
            getValueFromMatrix(i, k, value);        // 进行遍历，有连接（弧）的边放入集合
            if (value != 0) {
                Edge edge(i, k, value);
                edgeVec.push_back(edge);
            }
        }
    }

    // 从所有边中取出组成最小生成树的边
    // 同普利姆算法的结束条件
    while (edgeCount < m_iCapacity - 1) {

        // 从边集合中找到最小边,且选择状态改为被已选择
        int minEdgeIndex = getMinEdge(edgeVec);
        edgeVec[minEdgeIndex].m_bSelected = true;

        // 根据最小边找到两个连接点
        int nodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;
        int nodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;

        // 设定点A、B在点集合中的索引
        int nodeAInSetLabel = -1;
        int nodeBInSetLabel = -1;

        // 如果某点在点集合中，就将对应点的索引改为A、B在点集合中的索引
        for (int i = 0; i < (int)nodeSets.size(); i++) {
            nodeAInSetLabel = isInSet(nodeSets[i], nodeAIndex) ? i : nodeAInSetLabel;
            nodeBInSetLabel = isInSet(nodeSets[i], nodeBIndex) ? i : nodeBInSetLabel;
        }

        // 根据点所在集合的不同做出不同的处理　
        if (nodeAInSetLabel == -1 && nodeBInSetLabel == -1) {       // 如果都不在点集合中，就将节点A、B放入点集合中
            vector<int> vec;
            vec.push_back(nodeAIndex);
            vec.push_back(nodeBIndex);
            nodeSets.push_back(vec);
        } else if ((nodeAInSetLabel == -1) && (nodeBInSetLabel != -1)) { // 如果点A不在集合中，点B在集合中。就将点A放入点集合中点B的索引位置
            nodeSets[nodeBInSetLabel].push_back(nodeAIndex);
        } else if ((nodeAInSetLabel != -1) && (nodeBInSetLabel == -1)) { // 同上
            nodeSets[nodeAInSetLabel].push_back(nodeBIndex);
        } else if ((nodeAInSetLabel != -1) && (nodeBInSetLabel != -1) && (nodeAInSetLabel != nodeBInSetLabel)) { // 如果两点都在点集合中，且点AB索引位置不同，就合并点AB集合（将B集合并入A集合），且删除原来点集合中点B集合的位置（将点B集合后的集合全部前移一位，覆盖点B集合）
            mergeNodeSet(nodeSets[nodeAInSetLabel], nodeSets[nodeBInSetLabel]);
            for (int k = nodeBInSetLabel; k < (int)nodeSets.size() - 1; k++) {
                nodeSets[k] = nodeSets[k + 1];
            }

        } else if ((nodeAInSetLabel != -1) && (nodeBInSetLabel != -1) && (nodeAInSetLabel == nodeBInSetLabel)) { // 如果两点都在点集合中，且AB索引位置相同，就不做操作
            continue;
        }

        // 打印节点A、B的值及对应边的权值
        cout << edgeVec[minEdgeIndex].m_iNodeIndexA << "--" << edgeVec[minEdgeIndex].m_iNodeIndexB << " ";
        cout << edgeVec[minEdgeIndex].m_iWeightValue << endl;

        edgeCount++;

    }
}


bool CMap::isInSet(vector<int> nodeSet, int target) {
    // 判断点是否在点集合中
    for (int i = 0; i < (int)nodeSet.size(); i++) {
        if (nodeSet[i] == target) {
            return true;
        }
    }
    return false;
}

void CMap::mergeNodeSet(vector<int> &nodeSetA, vector<int> nodeSetB) {
    // 合并B集合到A集合中
    for (int i = 0; i < (int)nodeSetB.size(); i++) {
        nodeSetA.push_back(nodeSetB[i]);
    }
}

// 迪杰斯特拉最短路径
void CMap::Dijkstra(int nodeIndex) {
    /*
     * 定义一个数组vector存放已经遍历的点，暂时未加上路径
     * 循环终止条件————数组长度等于顶点数
     * 循环过程：
     * 1. 从U中取出与原顶点距离最小的顶点k，加入S
     * 2. 以k为新顶点，修改U中各顶点的距离;确保顶点之间的距离是最小的。
     * 3. 重复上述步骤
     */
    int INFINITY = 10000000;
    int node_count = 1;
    int nodeValue = 0;
    int temp_node = 0;
    vector<int> nodeVec;

    // 点到其他各点的距离，若不存在则为无穷大
    for (int i = 0; i < m_iCapacity; i++) {
        getValueFromMatrix(nodeIndex, i, nodeValue);
        nodeValue = nodeValue == 0 ? INFINITY : nodeValue;
        nodeVec.push_back(nodeValue);
    }
    nodeVec[nodeIndex] = 0;   // 自己到自己的距离为零
    m_pNodeArray[nodeIndex].m_bIsVisted = true;

    // 终止条件是遍历完所有的点（除自己及之前的点）
    while (node_count < m_iCapacity - nodeIndex) {
        // 先找出看似最小的路径，获取边的另一个点
        int min_num = INFINITY;
        for (int i = nodeIndex; i < m_iCapacity; i++) {
            if ((!m_pNodeArray[i].m_bIsVisted) && (nodeVec[i] < min_num)) {
                min_num = nodeVec[i];
                temp_node = i;
            }
        }

        m_pNodeArray[temp_node].m_bIsVisted = true;

        // 边的另一个点到其余各点的距离是否小于原始点到各点的距离
        for (int i = nodeIndex; i < m_iCapacity; i++) {
            getValueFromMatrix(temp_node, i, nodeValue);
            nodeValue = nodeValue == 0 ? INFINITY : nodeValue;
            if ((nodeValue + min_num < nodeVec[i]) && (!m_pNodeArray[i].m_bIsVisted)) {
                nodeVec[i] = nodeValue + min_num;
            }
        }
        cout << m_pNodeArray[nodeIndex].m_cData << "-->" << m_pNodeArray[temp_node].m_cData << " "<< nodeVec[temp_node] << endl;
        node_count++;
    }
}

// 弗洛伊德最短路径
void CMap::Floyd() {
    int INFINITY = 100000;
    int value = 0;

    // D重新定义邻接矩阵，两点若不存在距离，则距离为无穷大
    // P存储点点之间的索引
    vector<vector <int> > D_vec;
    vector<vector <int> > P_vec;
    for (int i = 0; i < m_iCapacity; i++) {
        vector<int> d_vec;
        vector<int> p_vec;
        for (int j = 0; j < m_iCapacity; j++) {
            getValueFromMatrix(i, j, value);
            value = value == 0 ? INFINITY : value;
            d_vec.push_back(value);
            p_vec.push_back(j);
        }
        D_vec.push_back(d_vec);
        P_vec.push_back(p_vec);
    }

    // 三重循环，里面的两个循环为不经过第三个点，最外层循环表示经过第三个点
    for (int i = 0; i < m_iCapacity; i++) {
        for (int j = 0; j < m_iCapacity; j++) {
            for (int k = 0; k < m_iCapacity; k++) {
                if (D_vec[j][k] > D_vec[j][i] + D_vec[i][k]) {
                    D_vec[j][k] = D_vec[j][i] + D_vec[i][k];
                    P_vec[j][k] = P_vec[j][i];
                }
            }
        }
    }

    // 输出点到各点的距离及路径
    for (int i = 0; i < m_iCapacity; i++) {
        for (int j = i + 1; j < m_iCapacity; j++) {
            cout << m_pNodeArray[i].m_cData << "-" << m_pNodeArray[j].m_cData << " weight: " << D_vec[i][j] << endl;
            int node_index = P_vec[i][j];
            cout << "路径：" << m_pNodeArray[i].m_cData;
            while (node_index != j) {
                cout << "->" << m_pNodeArray[node_index].m_cData;
                node_index = P_vec[node_index][j];
            }
            cout << "->" << m_pNodeArray[node_index].m_cData << endl;
        }
        cout << " " << endl;
    }
}
