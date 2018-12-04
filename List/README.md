## 链表

线性表，并不是一定按线性的顺序进行存储，而是依靠指针进行存储。

这里仅仅实现了单向链表和顺序表。

### 顺序表

实现以下功能

1. 创建、销毁、清空
2. 判断是否为空
3. 长度
4. 根据索引获取指定元素
5. 根据元素获取第一个满足索引
6. 根据元素获取它的前驱、后继
7. 指定位置插入、删除元素
8. 遍历

### 单链表

在顺序表的基础上加了两个功能

1. 从头部插入元素
2. 从尾部插入元素

且调用了指针来完成单链表

```bash
# 编译各个demo所需要的cpp
g++ demo.cpp List.cpp -o demo
g++ demo2.cpp List.cpp Coordinate.cpp -o demo2
g++ demo3.cpp List2.cpp Node.cpp -o demo3
g++ demo4.cpp List2.cpp Node.cpp Person.cpp -o demo4
```

