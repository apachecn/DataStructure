#ifndef COORDINATE_H
#define COORDINATE_H
#include <stdio.h>
#include<ostream>
using namespace std;

class Coordinate {
    friend ostream &operator<<(ostream &out, Coordinate &coor); // 实现重载
  public:
    Coordinate(int x = 0, int y = 0);
    void printCoordinate();

  private:
    int m_iX;
    int m_iY;
};

#endif
