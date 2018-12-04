## 数据结构

> 来源：[数据结构探险系列代码](https://www.imooc.com/u/1349694/courses?sort=publish)
>
> 贡献者：[wnma3mz](https://github.com/wnma3mz)
>
> 欢迎任何人参与和完善：一个人可以走的很快，但是一群人却可以走的更远。

- [ApacheCN 机器学习交流群 629470233](http://shang.qq.com/wpa/qunwpa?idkey=30e5f1123a79867570f665aa3a483ca404b1c3f77737bc01ec520ed5f078ddef)
- [ApacheCN 学习资源](http://www.apachecn.org/)

目前，只在课程基础上用C++实现了一遍，并加入了堆和平衡二叉树的实现。欢迎提交完善C++版本和其他语言版本。若有疑问，欢迎提issus。



## 说明

C++在Linux下编译

1. `g++ *.cpp -o outfile`
2. `./outfile`

### Stack/

栈的实现

| 名字             | 功能                                    |
| -------------- | ------------------------------------- |
| `MyStack.h`    | 实现了栈的数据结构，并且可拓展                       |
| `MyStack.cpp`  | 可以不需要编译，因为代码已经转移到了`MyStack.h`中，为了实现模板 |
| `Coordinate.h` | 实现坐标类，`m_iX`和`m_iY`                   |
| `demo.cpp`     | 检验栈的实现                                |
| `demo2.cpp`    | 引入新的`Coordinate.h`实现栈                 |
| `demo3.cpp`    | 实现进制转换                                |
| `demo4.cpp`    | 实现符号匹配`[(){}]`                        |

###  Queue/

队列的实现（环形队列）

| 名字           | 功能                                |
| ------------ | --------------------------------- |
| `MyQueue.h`  | 实现了队列的数据结构，编译的时候需要使用`MyQueue.cpp` |
| `Customer.h` | 实现顾客类，`m_strName`和`m_iAge`        |
| `demo.cpp`   | 检验队列的实现                           |
| `demo2.cpp`  | 引入`Customer.h`实现队列                |

### List/

**线性表**的实现（**顺序表**和**单向表**）

| 名字             | 功能                                       |
| -------------- | ---------------------------------------- |
| `List.h`       | 实现**顺序表**                                |
| `List2.h`      | 实现**单链表**                                |
| `Node.h`       | 实现`List2.h`中需要的`Node`类，`Person`类和`Node`类的指针 |
| `Person.h`     | 使用`Person`类，有两个属性`name`和`phone`          |
| `Coordinate.h` | 实现坐标类，同`stack_demo/`                     |
| `demo.cpp`     | 检验**顺序表**的实现                             |
| `demo2.cpp`    | 引入`Coordinate.h`实现**顺序表**                |
| `demo3.cpp`    | 引入`Node.h`检验**单链表**的实现                   |
| `demo4.cpp`    | 引入`Person.h`实现**单链表**                    |


### Tree/

树的实现（二叉树数组和二叉树链表）

| 名字          | 功能                                       |
| ----------- | ---------------------------------------- |
| `Tree.h`    | 实现二叉树数组                                  |
| `Tree2.h`   | 实现二叉树链表                                  |
| `Node.h`    | 实现二叉树链表所需要的结点。`index`索引、`data`数值、`Node *pLChild, *pRChild, *pParent`左右孩子父结点 |
| `demo.cpp`  | 检验二叉树数组的实现                               |
| `demo2.cpp` | 检验二叉树链表的实现                               |
| `BSTree.h` | 实现二叉查找树                               |
| `demo3.cpp` | 检验二叉查找树的实现                               |
|`AVLTree.h`|平衡二叉树|

### Map/

图的实现

| 名字          | 功能                                       |
| ----------- | ---------------------------------------- |
| `CMap.h`    | 实现图                                      |
| `Edge.h`    | 实现图所需要的边，`nodeIndexA`，`nodeIndexB`，`weightValue`，节点A、B的索引及对应边的权值 |
| `Node.h`    | 实现图所需要的点，`m_cData`节点的值，`m_bIsVisted`改节点是否被访问过 |
| `demo.cpp`  | 检验图的实现，深度优先遍历和广度优先遍历                     |
| `demo2.cpp` | 检验最小生成树算法的实现，普利姆最小生成树和克鲁斯卡尔最小生成树         |
| `demo3.cpp` | 检验最短路径算法的实现，迪杰斯特拉最短路径和弗洛伊德最短路径         |

### Heap/

堆的实现

| 名字          | 功能                                       |
| ----------- | ---------------------------------------- |
| `Heap.cpp`    | 最小堆排序                                      |