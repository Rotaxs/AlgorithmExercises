#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5;

int n = 0;
// 大根堆
int maxHeap[N], len = 0;

int left(int i) { return 2 * i + 1; }

int right(int i) { return 2 * i + 2; }

int parent(int i) { return (i - 1) / 1; }

int peek() { return maxHeap[0]; }

// 向上堆化
// 只要父结点比自己大，就往上走
void shift_up(int i)
{
    while (i > 0 && maxHeap[i] > maxHeap[parent(i)])
    {
        swap(maxHeap[i], maxHeap[parent(i)]);
        i = parent(i);
    }
}

void shift_up_enhanced(int i)
{
    int tmp = maxHeap[i];
    while (i > 0 && tmp > maxHeap[parent(i)])
    {
        // 父结点下移，此时父结点和其原来位置的数相同
        maxHeap[i] = maxHeap[parent(i)];
        i = parent(i);
    }
    maxHeap[i] = tmp;
}

// 向下堆化
// 与较大的子节点交换
void shift_down(int i, int len)
{
    // 只要左子结点存在，就有可能下沉
    while (left(i) < len)
    {
        // 假设左子节点较大
        int max_child = left(i);
        // 如果有右子结点，且右子结点大于左子结点
        if (right(i) < len && maxHeap[right(i)] > maxHeap[left(i)])
            max_child = right(i);
        // 判断是否需要下沉
        if (maxHeap[i] >= maxHeap[max_child])
            break;
        // 如果需要下沉，就交换
        swap(maxHeap[i], maxHeap[max_child]);
        // 更新需要下沉的对象的索引
        i = max_child;
    }
}

void shift_down_enhanced(int i, int len)
{
    // 现将要移动的对象存起来
    int tmp = maxHeap[i];
    int child;
    // 定义要交换的子结点
    while ((child = left(i)) < len)
    {
        // child + 1 就是右子结点
        if (child + 1 < len && maxHeap[child + 1] > maxHeap[child])
            child++;

        // 用缓存的值判断是否需要下沉
        if (tmp >= maxHeap[child])
            break;

        // 原来的对象有缓存 tmp，因此可以先不考虑
        maxHeap[i] = maxHeap[child];
        i = child;
    }
    maxHeap[i] = tmp;
}

// 添加元素
void push(int x)
{
    // 先将新元素放到最后
    maxHeap[len] = x;
    // 然后新元素上浮
    shift_up(len++);
}

// 弹出堆顶
int pop()
{
    if (len == 0)
        return;
    int peek = maxHeap[0];
    // 将最后的元素移到堆顶
    maxHeap[0] = maxHeap[--len];
    // 新的堆顶下沉堆化
    shift_down(0, len);
    return peek;
}

void print_arr()
{
    for (int i = 1; i <= n; i++)
    {
        cout << maxHeap[i] << " ";
    }
    cout << endl;
}

int main()
{

    return 0;
}