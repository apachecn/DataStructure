#include"Coordinate.h"
#include<iostream>
using namespace std;

Coordinate::Coordinate(int x, int y) {
    m_iX = x;
    m_iY = y;
}

void Coordinate::printCoordinate() {
    cout << "(" << m_iX << "," << m_iY << ")" << endl;
}

ostream &operator<<(ostream &out, Coordinate &coor) {	// 实现重载输出运算符
    out << "(" << coor.m_iX << "," << coor.m_iY << ")" << endl;
    return out;
}
