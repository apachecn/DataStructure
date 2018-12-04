#ifndef NODE_H
#define NODE_H

class Node {
  public:
    Node(char data = 0);
    char m_cData;
    bool m_bIsVisted;  // 用于判断是否被访问过，遍历树的时候需要使用
};

#endif
