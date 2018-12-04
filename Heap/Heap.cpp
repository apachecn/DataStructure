#include <iostream>
using namespace std;

// 用指针进行交换
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void minheapfixdown(int a[], int i, int n)
{
    int j, temp;
    // 当前的元素
    temp = a[i];
    // 当前元素的左子节点的索引
    j = 2 * i + 1;
    // 如果索引没有超过数组长度
    while (j < n)
    {
        // 如果索引在数组长度范围内，且当前元素的右节点小于左节点，则对右节点进行操作
        if (j + 1 < n and a[j + 1] < a[j])
            j++;
        // 如果当前元素的子节点大于当前元素，则说明不需要替换，直接退出
        if (a[j] >= temp)
            break;
        // 进行交换， 并将当前元素的子节点的子节点继续进行遍历
        a[i] = a[j];
        i = j;
        j = 2 * j + 1;
    }
    // 最后将原有的当前元素替换
    a[i] = temp;
}

void makeheap(int a[], int n)
{
    // 从数组中间开始到数组头部
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minheapfixdown(a, i, n);
    }
}

// 堆排序函数
void minheapsort(int a[], int n)
{
    int j = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        swap(&a[0], &a[i]);
        minheapfixdown(a, 0, i);
    }
}

int main()
{
    int a[100];
    int n;
    // 读入数据
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // 构造最小堆
    makeheap(a, n);
    for (int i = n - 1; i >= 0; i--)
        cout << a[i] << '\t';
    cout << endl;
    // 最小堆排序
    minheapsort(a, n);
    for (int i = n - 1; i >= 0; i--)
        cout << a[i] << '\t';
    return 0;
}