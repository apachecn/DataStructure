#include "AVLTree.h"
#include <iostream>
#include <exception>

int main() {
    try {
        AVLTree avl;
        for(int i = 1; i < 10; i++) {
            avl.Insert(i);
        }

        avl.Delete(4);
        avl.Display();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}